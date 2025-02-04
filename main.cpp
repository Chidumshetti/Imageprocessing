#include "./lib/module.h"
#include <iostream>

int main() {
    std::cout << "Hello GG" << std::endl;

    std::string imagePath;
    std::cout << "Enter image path: ";
    std::cin >> imagePath;

    getImage(imagePath);    
    rotateImage(imagePath,1);
    return 0;
}
