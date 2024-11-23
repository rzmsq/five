#include "../include/circle.hpp"

Circle::Circle()
{
    this->rad = rand_int(10, 50);
    this->_point.set_xy(center_cart_x, center_cart_y);

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;

    std::cout << "\tNew circle\n";
}

const void Circle::show(SDL_Renderer *_renderer)
{
    if (this->is_out_of_range())
        this->_point.set_xy(center_cart_x, center_cart_y);

    circleRGBA(_renderer, this->_point.get_x(), this->_point.get_y(), rad, r, g, b, a);
}

const void Circle::change_size(const int &_rad, const bool &_flg)
{
    if (!is_out_of_rad(_flg))
        this->rad += _rad;
}

const bool Circle::is_out_of_rad(const bool &_flg) const
{
    if (this->is_out_of_range() && _flg)
        return true;
    else if (this->rad < this->minSize && !_flg)
        return true;

    return false;
}

const bool Circle::is_out_of_range() const
{
    if ((this->_point.get_x() + this->rad) > cartCoord[coord::cart::x2] ||
        (this->_point.get_x() - this->rad) < cartCoord[coord::cart::x1] ||
        (this->_point.get_y() + this->rad) > cartCoord[coord::cart::y2] ||
        (this->_point.get_y() - this->rad) < cartCoord[coord::cart::y1])
        return true;

    return false;
}