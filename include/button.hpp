#pragma once

#include "libs.hpp"

struct Button
{
    SDL_Rect btn;
    std::string name;
    bool isVisible{false};

    Button();

    explicit Button(const int &_x, const int &_y, const int &_w, const int &_h,
                    const std::string &name)
    {
        btn.x = _x;
        btn.y = _y;
        btn.w = _w;
        btn.h = _h;
        this->name = name;
    }

    void changeName(const std::string &newName)
    {
        this->name = name;
    }

    bool is_pressed()
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x <= (btn.x + btn.w) && x >= btn.x &&
            y <= (btn.y + btn.h) && y >= btn.y &&
            this->isVisible)
            return true;
        return false;
    }

    void set_label(SDL_Renderer *renderer)
    {
        TTF_Font *sans = TTF_OpenFont("/home/rzms/Documents/cpp_proj/labs/first/OpenSans-Regular.ttf", 12);
        const SDL_Color white = {0XFF, 0XFF, 0XFF};
        SDL_Surface *surfaceMsg = TTF_RenderText_Solid(sans, this->name.c_str(), white);
        SDL_Texture *msg = SDL_CreateTextureFromSurface(renderer, surfaceMsg);
        SDL_FreeSurface(surfaceMsg);

        SDL_Rect renderQuad = {btn.x + (btn.w - 90), btn.y + 8, btn.w - 70, btn.h - 15};
        SDL_RenderCopy(renderer, msg, NULL, &renderQuad);
        SDL_DestroyTexture(msg);
    }
};