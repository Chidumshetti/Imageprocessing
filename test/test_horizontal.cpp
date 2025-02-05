#include "../lib/horizontal_edge.h"
#include "../lib/module.h"
int main() {
    std::string imagePath;
    std::cout << "Enter image path: ";
    std::cin >> imagePath;
    horizontal_edge edgeProcessor;
    edgeProcessor.horizontaledg(imagePath);
    return 0;
}
