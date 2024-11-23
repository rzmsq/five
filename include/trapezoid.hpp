#pragma once

#include "rect.hpp"

class Trapezoid : public Rect
{
private:
    int r, g, b, a;
    short minSize{10};
    int current_size_x_up{0}, current_size_x_down{0}, current_size_y{0};
    Point point1, point2, point3;

    const bool is_out_of_size(const bool &_flg) const;
    const bool is_out_of_range() const;
    const void replace_trapezoid_to_center_coord();
    const void set_dxdy();
    const void updateCurrentSizeValue();

public:
    Trapezoid();

    virtual const void show(SDL_Renderer *_renderer) override;
    const void change_size(const int &_size, const bool &_flg) override;
};
