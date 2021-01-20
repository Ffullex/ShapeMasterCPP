#include <string>
#include <iostream>

class IShape {
public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
    virtual std::string getType() = 0;
};

class Rectangle : public IShape {
private:
    double width;
    double height;
public:
    Rectangle(std::istream* input, std::ostream* output);
    Rectangle(double width, double height);
    double getArea() override;
    double getVolume() override;
    std::string getType() override;
};

class Circle : public IShape {
protected:
    double radius;

public:
    Circle(std::istream* input, std::ostream* output);
    Circle(double radius);
    double getArea() override;
    double getVolume() override;
    std::string getType() override;
};

class Sphere : public Circle {
public:
    Sphere(std::istream* input, std::ostream* output);
    Sphere(double radius);
    double getArea() override;
    double getVolume() override;
    std::string getType() override;
};

class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(std::istream* input, std::ostream* output);
    Cylinder(double radius, double height);
    double getArea() override;
    double getVolume() override;
    std::string getType() override;
};

IShape* guessShape(std::istream* input, std::ostream* output);