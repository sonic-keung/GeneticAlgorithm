#pragma once
#include <iostream>
class City {
private:
    int name;
    double coordinate_x;
    double coordinate_y;
public:
    City();
    ~City() {}
    City(int name, double x, double y) : name(name), coordinate_x(x), coordinate_y(y) {}
    int getName();
    double getX();
    double getY();

};