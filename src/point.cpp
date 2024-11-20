#include "../include/point.hpp"

Point::Point(const int &_x, const int &_y)
{
    this->set_xy(_x, _y);
    std::cout << "New point\n";
}

const void Point::set_xy(const int &_x, const int &_y)
{
    this->x = _x;
    this->y = _y;
}

const int &Point::get_x() const
{
    return this->x;
}

const int &Point::get_y() const
{
    return this->y;
}
