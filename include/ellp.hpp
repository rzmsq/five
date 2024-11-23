#pragma once

#include "circle.hpp"

class Ellips : public Circle
{
private:
    int rx, ry, r, g, b, a;
    const short minSize{8};

    const bool is_out_of_rad(const bool &_flg) const;
    const bool is_out_of_range() const;

public:
    Ellips();
    explicit Ellips(const int &_x, const int &_y, const int &_rx, const int &_ry,
                    const int &_r, const int &_g, const int &_b, const int &_a);

    virtual const void show(SDL_Renderer *_renderer) override;
    const void change_size(const int &_rad, const bool &_flg) override;
    const void rotate();
};