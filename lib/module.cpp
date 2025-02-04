#include "module.h"
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
void rotateImage(const std::string& imagePath, int k) {
    if (k != 1 && k != -1) {
        std::cerr << "Invalid rotation value! Use 1 for 90° clockwise and -1 for 90° counterclockwise." << std::endl;
        return;
    }
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return;
    }
    cv::Mat rotated;
    if (k == 1) {
        // Rotate 90° clockwise
        cv::rotate(img, rotated, cv::ROTATE_90_CLOCKWISE);
    } else if (k == -1) {
        // Rotate 90° counterclockwise
        cv::rotate(img, rotated, cv::ROTATE_90_COUNTERCLOCKWISE);
    }

    // Save rotated image
    std::string outputPath = "rotated_image.jpg";
    cv::imwrite(outputPath, rotated);

    std::cout << "Rotation complete! Rotated image saved as " << outputPath << std::endl;
}
