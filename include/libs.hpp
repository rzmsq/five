#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>

constexpr int center_cart_x{410};
constexpr int center_cart_y{300};

namespace coord
{
    enum cart
    {
        x1,
        x2,
        y1,
        y2
    };
}

enum moveCode
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    RAND
};

enum figureCode
{
    CIRCLE,
    RECT,
    ALL
};

inline int rand_int(const int &from, const int &to)
{
    std::random_device rd;
    std::mt19937 generator{rd()};
    std::uniform_int_distribution<int> distribution_x(from, to);
    return distribution_x(generator);
}