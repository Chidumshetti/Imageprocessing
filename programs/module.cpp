#include "../lib/module.h"
#include <iostream>
#include <opencv2/opencv.hpp>

void getImage(const std::string& imagePath) {
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Error: Cannot open image file: " << imagePath << std::endl;
        return;
    }

    std::cout << "Image successfully loaded: " << imagePath << std::endl;
}
void rotateImage(const std::string& imagePath, int angle) {
   
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return;
    }

     cv::Point2f center(img.cols / 2.0, img.rows / 2.0);

    // Compute the rotation matrix
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, angle, 1.0);

    // Determine the new bounding rectangle
    cv::Rect bbox = cv::RotatedRect(center, img.size(), angle).boundingRect();

    // Adjust transformation matrix to keep the image centered
    rotationMatrix.at<double>(0, 2) += bbox.width / 2.0 - center.x;
    rotationMatrix.at<double>(1, 2) += bbox.height / 2.0 - center.y;

    cv::Mat rotatedImg;
    cv::warpAffine(img, rotatedImg, rotationMatrix, bbox.size());

    // Save rotated image
    std::string outputPath = "rotated_image.jpg";
    cv::imwrite(outputPath, rotatedImg);

    std::cout << "Rotation complete! Rotated image saved as " << outputPath << std::endl;
}
