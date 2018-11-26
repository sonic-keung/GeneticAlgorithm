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
    City(int name, double x, double y) : name(name), coordinate_x(x), coordinate_y(y) {
//        if (coordinate_x < 0 || coordinate_x > 1000 || coordinate_y < 0 || coordinate_y > 100) {
//            throw "X and Y coordinates must be greater than 0 or less than 1000";
//        }
    }

    int getName();
    double getX();
    double getY();

};