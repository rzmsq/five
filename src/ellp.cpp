#include "../include/ellp.hpp"

Ellips::Ellips()
{
    this->_point.set_xy(center_cart_x, center_cart_y);

    this->rx = rand_int(10, 50);
    this->ry = rand_int(10, 50);

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;

    std::cout << "\tnew ellips\n";
}

const void Ellips::show(SDL_Renderer *renderer)
{
    if (this->is_out_of_range())
        this->_point.set_xy(center_cart_x, center_cart_y);

    filledEllipseRGBA(renderer, this->_point.get_x(), this->_point.get_y(),
                      rx, ry, r, g, b, a);
}

const void Ellips::change_rad(const int &_rx, const int &_ry, const bool &_flg)
{
    if (!this->is_out_of_rad(_flg))
    {
        this->rx += _rx;
        this->ry += _ry;
    }
}

const bool Ellips::is_out_of_rad(const bool &_flg) const
{
    if (this->is_out_of_range() && _flg)
        return true;
    else if (this->rx < minSize && !_flg)
        return true;

    return false;
}

const bool Ellips::is_out_of_range() const
{
    if (((this->_point.get_x() + this->rx) > cartCoord[coord::cart::x2] ||
         (this->_point.get_x() - this->rx) < cartCoord[coord::cart::x1] ||
         (this->_point.get_y() + this->ry) > cartCoord[coord::cart::y2] ||
         (this->_point.get_y() - this->ry) < cartCoord[coord::cart::y1]))
        return true;

    return false;
}

const void Ellips::rotate()
{
    const int tmp = this->rx;
    this->rx = this->ry;
    this->ry = tmp;

    if (this->is_out_of_range())
        this->_point.set_xy(center_cart_x, center_cart_y);
}