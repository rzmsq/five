#pragma once

#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point() {};
    Point(const int &_x, const int &_y);
    const void set_xy(const int &_x, const int &_y);
    const int &get_y() const;
    const int &get_x() const;
};