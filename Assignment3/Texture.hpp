

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        u = std::min(1.0f, std::max(0.0f, u));
        v = std::min(1.0f, std::max(0.0f, v));

        int u_img = static_cast<int>(u * (width - 1));
        int v_img = static_cast<int>((1.0f - v) * (height - 1));

        auto color = image_data.at<cv::Vec3b>(v_img, u_img);

        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColorBilinear(float u, float v)
    {
        u = std::min(1.0f, std::max(0.0f, u));
        v = std::min(1.0f, std::max(0.0f, v));

        float x = u * (width - 1);
        float y = (1.0f - v) * (height - 1);

        int x0 = std::floor(x);
        int y0 = std::floor(y);
        int x1 = std::min(x0 + 1, width - 1);
        int y1 = std::min(y0 + 1, height - 1);

        float s = x - x0;
        float t = y - y0;

        auto c00_cv = image_data.at<cv::Vec3b>(y0, x0);
        auto c10_cv = image_data.at<cv::Vec3b>(y0, x1);
        auto c01_cv = image_data.at<cv::Vec3b>(y1, x0);
        auto c11_cv = image_data.at<cv::Vec3b>(y1, x1);

        Eigen::Vector3f c00(c00_cv[0], c00_cv[1], c00_cv[2]);
        Eigen::Vector3f c10(c10_cv[0], c10_cv[1], c10_cv[2]);
        Eigen::Vector3f c01(c01_cv[0], c01_cv[1], c01_cv[2]);
        Eigen::Vector3f c11(c11_cv[0], c11_cv[1], c11_cv[2]);

        Eigen::Vector3f c0 = c00 * (1.0f - s) + c10 * s;
        Eigen::Vector3f c1 = c01 * (1.0f - s) + c11 * s;

        Eigen::Vector3f color = c0 * (1.0f - t) + c1 * t;

        return color;
    }


};
#endif //RASTERIZER_TEXTURE_H
