#pragma once

#include "tfigure.hpp"

class Rect : public TFigure
{
private:
    int r, g, b, a;
    short currentSizeX{0}, currentSizeY{0}, minSize{10};
    Point point1;

    const void set_dxdy();
    const bool is_out_of_size(const bool &_flg) const;
    const bool is_out_of_range() const;
    const void replace_rect_to_center_coord();
    const void updateCurrentSizeValue();

public:
    Rect();
    explicit Rect(const int &_x1, const int &_y1, const int &_x2, const int &_y2,
                  const int &_r, const int &_g, const int &_b, const int &_a);

    virtual const void show(SDL_Renderer *_renderer) override;
    const void change_size(const int &_rad, const bool &_flg);
};