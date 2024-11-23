#pragma once

#include "button.hpp"
#include "tfigure.hpp"
#include "circle.hpp"
#include "rect.hpp"
#include "ellp.hpp"
#include "trapezoid.hpp"

const void draw_main_menu(SDL_Renderer *renderer);
const void draw_figure_menu(SDL_Renderer *renderer);
const void add_figure();
const void mouse_button_left_process(SDL_Renderer *renderer, const int &figCod = figureCode::ALL);
const void move_all_figure(const char &direction, const int &figCod = figureCode::ALL);
const void erase_figure(SDL_Renderer *renderer);
const void remove_figure();
const void increase_radius();
const void reduce_radius();
const void rotate();
const void draw_cart(SDL_Renderer *renderer);
const void draw_btn(SDL_Renderer *renderer, Button &btn);
const void draw_app(SDL_Renderer *renderer);
const void draw_setting_btns(SDL_Renderer *renderer);
const void draw_figure_btns(SDL_Renderer *renderer);
const void draw_all_figures(SDL_Renderer *renderer);