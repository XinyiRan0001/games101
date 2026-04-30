#include <iostream>
#include <cmath>
#include <Eigen/Core>

int main()
{
    Eigen::Vector3f p(2.0f, 1.0f, 1.0f);

    float angle = 45.0f / 180.0f * acos(-1);

    Eigen::Matrix3f rotation;
    rotation << cos(angle), -sin(angle), 0,
        sin(angle), cos(angle), 0,
        0, 0, 1;

    Eigen::Matrix3f translation;
    translation << 1, 0, 1,
        0, 1, 2,
        0, 0, 1;

    Eigen::Vector3f result = translation * rotation * p;

    std::cout << result << std::endl;

    return 0;
}