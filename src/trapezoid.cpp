#include "../include/trapezoid.hpp"

Trapezoid::Trapezoid()
{
    const int rand_x = rand_int(0, 50);
    const int rand_y = rand_int(0, 50);
    const int rand_x_adv = rand_int(rand_x, 100);
    const int rand_y_adv = rand_int(rand_y, 100);

    this->_point.set_xy(center_cart_x - rand_x, center_cart_y - rand_y);
    this->point1.set_xy(center_cart_x + rand_x, center_cart_y - rand_y);
    this->point2.set_xy(center_cart_x - rand_x_adv, center_cart_y + rand_y_adv);
    this->point3.set_xy(center_cart_x + rand_x_adv, center_cart_y + rand_y_adv);

    this->r = 0xFF;
    this->g = 0xFF;
    this->b = 0xFF,
    this->a = 0xFF;

    std::cout << "\tnew trapezoid\n";
}

const void Trapezoid::show(SDL_Renderer *_renderer)
{
    if (current_size_x_up != 0)
        this->set_dxdy();

    if (this->is_out_of_range())
        this->replace_trapezoid_to_center_coord();

    lineRGBA(_renderer, this->_point.get_x(), this->_point.get_y(),
             this->point1.get_x(), this->point1.get_y(),
             this->r, this->g, this->b, this->a);
    lineRGBA(_renderer, this->point2.get_x(), this->point2.get_y(),
             this->point3.get_x(), this->point3.get_y(),
             this->r, this->g, this->b, this->a);
    lineRGBA(_renderer, this->_point.get_x(), this->_point.get_y(),
             this->point2.get_x(), this->point2.get_y(),
             this->r, this->g, this->b, this->a);
    lineRGBA(_renderer, this->point1.get_x(), this->point1.get_y(),
             this->point3.get_x(), this->point3.get_y(),
             this->r, this->g, this->b, this->a);
    updateCurrentSizeValue();
}

const void Trapezoid::change_size(const int &_size, const bool &_flg)
{
    if (!this->is_out_of_size(_flg))
    {
        this->_point.set_xy(this->_point.get_x() - _size, this->_point.get_y() - _size);
        this->point1.set_xy(this->point1.get_x() + _size, this->point1.get_y() - _size);
        this->point2.set_xy(this->point2.get_x() - _size, this->point2.get_y() + _size);
        this->point3.set_xy(this->point3.get_x() + _size, this->point3.get_y() + _size);
        updateCurrentSizeValue();
    }
}

const bool Trapezoid::is_out_of_size(const bool &_flg) const
{
    if (this->is_out_of_range() && _flg)
        return true;
    else if ((point1.get_x() - _point.get_x() < this->minSize ||
              point3.get_y() - _point.get_y() < this->minSize) &&
             !_flg)
        return true;

    return false;
}

const bool Trapezoid::is_out_of_range() const
{
    if (_point.get_x() <= (cartCoord[coord::cart::x1] + 2) || _point.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        _point.get_y() <= (cartCoord[coord::cart::y1] + 2) || _point.get_y() >= (cartCoord[coord::cart::y2] - 2) ||
        point1.get_x() <= (cartCoord[coord::cart::x1] + 2) || point1.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        point1.get_y() <= (cartCoord[coord::cart::y1] + 2) || point1.get_y() >= (cartCoord[coord::cart::y2] - 2) ||
        point2.get_x() <= (cartCoord[coord::cart::x1] + 2) || point2.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        point2.get_y() <= (cartCoord[coord::cart::y1] + 2) || point2.get_y() >= (cartCoord[coord::cart::y2] - 2) ||
        point3.get_x() <= (cartCoord[coord::cart::x1] + 2) || point3.get_x() >= (cartCoord[coord::cart::x2] - 2) ||
        point3.get_y() <= (cartCoord[coord::cart::y1] + 2) || point3.get_y() >= (cartCoord[coord::cart::y2] - 2))
        return true;

    return false;
}

const void Trapezoid::replace_trapezoid_to_center_coord()
{
    _point.set_xy(center_cart_x - current_size_x_up / 2,
                  center_cart_y - current_size_y / 2);

    point1.set_xy(center_cart_x + current_size_x_up / 2,
                  center_cart_y - current_size_y / 2);

    point2.set_xy(center_cart_x - current_size_x_down / 2,
                  center_cart_y + current_size_y / 2);

    point3.set_xy(center_cart_x + current_size_x_down / 2,
                  center_cart_y + current_size_y / 2);
}

const void Trapezoid::set_dxdy()
{
    point1.set_xy(_point.get_x() + current_size_x_up,
                  _point.get_y());
    point2.set_xy(_point.get_x() - (current_size_x_down - current_size_x_up) / 2,
                  _point.get_y() + current_size_y);
    point3.set_xy(point1.get_x() + (current_size_x_down - current_size_x_up) / 2,
                  point2.get_y());
}

const void Trapezoid::updateCurrentSizeValue()
{
    current_size_x_up = point1.get_x() - _point.get_x();
    current_size_x_down = point3.get_x() - point2.get_x();
    current_size_y = point3.get_y() - _point.get_y();
}