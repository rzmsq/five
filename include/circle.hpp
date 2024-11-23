#pragma once

#include "tfigure.hpp"

class Circle : public TFigure
{
private:
    int rad, r, g, b, a;

    const short minSize{8};

    const bool is_out_of_rad(const bool &_flg) const;
    const bool is_out_of_range() const;

public:
    Circle();

    virtual const void show(SDL_Renderer *_renderer) override;
    const void change_size(const int &_rad, const bool &_flg) override;
};