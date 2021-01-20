#include "shapes.h"

const double PI = 3.14;

Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

Rectangle::Rectangle(std::istream* input, std::ostream* output) {
    *output << "Enter height: " << std::endl;
    *input >> height;
    *output << "Enter width: " << std::endl;
    *input >> width;
}

std::string Rectangle::getType() {
    return "rectangle";
}


double Rectangle::getArea() {
    return height * width;
}

double Rectangle::getVolume() {
    return 0;
}

Circle::Circle(double radius) : radius(radius) {}

Circle::Circle(std::istream* input, std::ostream* output) {
    *output << "Enter radius: " << std::endl;
    *input >> radius;
}

double Circle::getArea() {
    return PI * radius * radius;
}

double Circle::getVolume() {
    return 0;
}

std::string Circle::getType() {
    return "circle";
}

Sphere::Sphere(double radius) : Circle(radius) {}

Sphere::Sphere(std::istream* input, std::ostream* output) : Circle(input, output) {}

double Sphere::getArea() {
    return 4 * PI * radius * radius;
}

double Sphere::getVolume() {
    return PI * radius * radius * radius * (4 / 3);
}

std::string Sphere::getType() {
    return "sphere";
}

Cylinder::Cylinder(double radius, double height) : Circle(radius), height(height) {}

Cylinder::Cylinder(std::istream* input, std::ostream* output) : Circle(input, output) {
    *output << "Enter height: " << std::endl;
    *input >> height;
}

double Cylinder::getArea() {
    return height * PI * radius * 2 + 2 * PI * radius * radius;
}

double Cylinder::getVolume() {
    return PI * radius * radius * height;
}

std::string Cylinder::getType() {
    return "cylinder";
}

IShape* guessShape(std::istream* input, std::ostream* output) {
    std::string type;
    *output << "Enter shape type: " << std::endl;
    if (!std::getline(*input, type)) {
        exit(1);
    }
    if (type == "rectangle") {
        return new Rectangle(input, output);
    }
    else if (type == "circle") {
        return new Circle(input, output);
    }
    else if (type == "sphere") {
        return new Sphere(input, output);
    }
    else if (type == "cylinder") {
        return new Cylinder(input, output);
    }
    else {
        *output << "Not known type: " << type << std::endl;
        exit(1);
    }
}