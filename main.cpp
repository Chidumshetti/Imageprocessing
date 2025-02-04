#include "./lib/module.h"
#include <iostream>

int main() {
    std::string imagePath;
     int k;
    std::cout << "Enter image path: ";
    std::cin >> imagePath;
    getImage(imagePath);    
    std::cout << "Enter angle of rotation: ";
    std::cin>>k;
    rotateImage(imagePath,k);
    return 0;
}
