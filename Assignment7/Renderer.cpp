//
// Created by goksu on 2/25/20.
//

#include <fstream>
#include <thread>
#include <atomic>
#include <mutex>
#include "Scene.hpp"
#include "Renderer.hpp"


inline float deg2rad(const float& deg) { return deg * M_PI / 180.0; }

const float EPSILON = 0.00001;

// The main render function. This where we iterate over all pixels in the image,
// generate primary rays and cast these rays into the scene. The content of the
// framebuffer is saved to a file.
void Renderer::Render(const Scene& scene)
{
    std::vector<Vector3f> framebuffer(scene.width * scene.height);

    float scale = tan(deg2rad(scene.fov * 0.5));
    float imageAspectRatio = scene.width / (float)scene.height;
    Vector3f eye_pos(278, 273, -800);
    int spp = 128;
    std::cout << "SPP: " << spp << "\n";

    const int threadCount = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::atomic<int> finishedRows(0);
    std::mutex progressMutex;

    auto renderRows = [&](int startY, int endY)
        {
            for (int j = startY; j < endY; ++j)
            {
                for (int i = 0; i < scene.width; ++i)
                {
                    int index = j * scene.width + i;

                    float x = (2 * (i + 0.5f) / (float)scene.width - 1) *
                        imageAspectRatio * scale;

                    float y = (1 - 2 * (j + 0.5f) / (float)scene.height) * scale;

                    Vector3f dir = normalize(Vector3f(-x, y, 1));

                    Vector3f pixelColor(0);

                    for (int k = 0; k < spp; k++)
                    {
                        pixelColor += scene.castRay(Ray(eye_pos, dir), 0) / spp;
                    }

                    framebuffer[index] = pixelColor;
                }

                int rowsDone = ++finishedRows;

                std::lock_guard<std::mutex> lock(progressMutex);
                UpdateProgress(rowsDone / (float)scene.height);
            }
        };

    int rowsPerThread = scene.height / threadCount;
    int startY = 0;

    for (int t = 0; t < threadCount; ++t)
    {
        int endY = (t == threadCount - 1)
            ? scene.height
            : startY + rowsPerThread;

        threads.emplace_back(renderRows, startY, endY);

        startY = endY;
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    UpdateProgress(1.f);

    // save framebuffer to file
    FILE* fp = fopen("binary.ppm", "wb");
    (void)fprintf(fp, "P6\n%d %d\n255\n", scene.width, scene.height);
    for (auto i = 0; i < scene.height * scene.width; ++i) {
        static unsigned char color[3];
        color[0] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].x), 0.6f));
        color[1] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].y), 0.6f));
        color[2] = (unsigned char)(255 * std::pow(clamp(0, 1, framebuffer[i].z), 0.6f));
        fwrite(color, 1, 3, fp);
    }
    fclose(fp);    
}
