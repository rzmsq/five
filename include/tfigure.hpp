#pragma once

#include "libs.hpp"
#include "point.hpp"

const int screen_width{1024};
const int screen_height{640};
const std::vector<int> cartCoord{20, screen_width - 224, 20, screen_height - 40};

class TFigure
{
private:
    const std::pair<int, int> pointDX(const char &direction)
    {
        if (direction == moveCode::RIGHT)
            return std::pair<int, int>(10, 0);
        else if (direction == moveCode::LEFT)
            return std::pair<int, int>(-10, 0);
        else if (direction == moveCode::UP)
            return std::pair<int, int>(0, -10);
        else if (direction == moveCode::DOWN)
            return std::pair<int, int>(0, 10);
        else
            return std::pair<int, int>(rand_int(-50, 50), rand_int(-50, 50));
    };

protected:
    Point _point = Point();

public:
    TFigure() { std::cout << "parent\n"; };
    virtual const void show(SDL_Renderer *_renderer) = 0;
    const void move(const char &direction)
    {
        const std::pair<int, int> pdx = pointDX(direction);
        this->_point.set_xy(this->_point.get_x() + pdx.first, this->_point.get_y() + pdx.second);
    };
};