#include <iostream>
#include "shapes.h"

int main() {
    IShape *shape = guessShape(&std::cin, &std::cout);
    std::cout << "Chosen shape area is: " << shape->getArea() << std::endl;
    std::cout << "Chosen shape volume is: " << shape->getVolume() << std::endl;
    delete shape;

    return 0;
}
