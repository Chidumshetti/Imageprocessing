#include "../lib/horizontal_edge.h"
#include <opencv2/opencv.hpp>
void horizontal_edge::horizontaledg(const std::string& imagePath) {
    // Load the image from the given path
    cv::Mat image = cv::imread(imagePath);
    
    if (image.empty()) {
        std::cerr << "Error: Could not load the image!" << std::endl;
        return; // Exit if the image is empty
    }

    cv::Mat grayImage;
    // Convert to grayscale
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Define a kernel for horizontal edge detection (using Laplacian)
    cv::Mat kernel = (cv::Mat_<float>(3, 3) <<
        -1, -1, -1,
         2,  2,  2,
        -1, -1, -1);
    
    // Apply the kernel to the image using filter2D
    cv::Mat edges;
    cv::filter2D(grayImage, edges, CV_32F, kernel);

    // Convert the result to a more readable format (8-bit)
    cv::Mat abs_edges;
    cv::convertScaleAbs(edges, abs_edges);

    // Show the result
    cv::imshow("Horizontal Edges", abs_edges);
    cv::waitKey(0); // Wait for a key press to close the image window
}
