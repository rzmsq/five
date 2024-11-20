#include "../include/rect.hpp"

Rect::Rect()
{
    this->_point.set_xy(center_cart_x - rand_int(0, 50), center_cart_y - rand_int(0, 50));
    this->point1.set_xy(center_cart_x + rand_int(0, 50), center_cart_y + rand_int(0, 50));

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;

    std::cout << "\tnew rect\n";
}

const void Rect::show(SDL_Renderer *_renderer)
{
    this->set_dxdy();

    if (this->is_out_of_range())
        this->replace_rect_to_center_coord();

    rectangleRGBA(_renderer, this->_point.get_x(), this->_point.get_y(),
                  this->point1.get_x(), this->point1.get_y(),
                  this->r, this->g, this->b, this->a);
    updateCurrentSizeValue();
}

const void Rect::change_size(const int &_size, const bool &_flg)
{
    if (!this->is_out_of_size(_flg))
    {
        this->_point.set_xy(this->_point.get_x() - _size, this->_point.get_y() - _size);
        this->point1.set_xy(this->point1.get_x() + _size, this->point1.get_y() + _size);
        updateCurrentSizeValue();
    }
}

const bool Rect::is_out_of_size(const bool &_flg) const
{
    if (this->is_out_of_range() && _flg)
        return true;
    else if ((this->point1.get_x() - this->_point.get_x() < this->minSize ||
              this->point1.get_y() - this->_point.get_y() < this->minSize) &&
             !_flg)
        return true;

    return false;
}

const bool Rect::is_out_of_range() const
{
    if (this->_point.get_x() <= (cartCoord[coord::cart::x1] + 2) || this->_point.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        this->point1.get_x() <= (cartCoord[coord::cart::x1] + 2) || this->point1.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        this->_point.get_y() <= (cartCoord[coord::cart::y1] + 2) || this->_point.get_y() >= (cartCoord[coord::cart::y2] - 2) ||
        this->point1.get_y() <= (cartCoord[coord::cart::y1] + 2) || this->point1.get_y() >= (cartCoord[coord::cart::y2] - 2))
        return true;

    return false;
}

const void Rect::replace_rect_to_center_coord()
{
    this->_point.set_xy(center_cart_x - currentSizeX / 2,
                        center_cart_y - currentSizeY / 2);
    this->point1.set_xy(center_cart_x + currentSizeX / 2,
                        center_cart_y + currentSizeY / 2);
}

const void Rect::set_dxdy()
{
    if (currentSizeX == 0 && currentSizeY == 0)
        point1.set_xy(center_cart_x + (center_cart_x - _point.get_x()),
                      center_cart_y + (center_cart_y - _point.get_y()));
    else
        point1.set_xy(_point.get_x() + currentSizeX,
                      _point.get_y() + currentSizeY);
}

const void Rect::updateCurrentSizeValue()
{
    currentSizeX = this->point1.get_x() - this->_point.get_x();
    currentSizeY = this->point1.get_y() - this->_point.get_y();
}