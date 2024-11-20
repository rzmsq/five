#include "../include/main.hpp"

namespace codes
{
    enum codeBtn
    {
        circle,
        rect,
        ellipse,
        trapezoid,
        menu,
        array
    };
}

namespace ind
{
    enum settBtn
    {
        menu,
        add,
        move,
        remove,
        erase
    };
    enum figBtn
    {
        cirlce,
        rect,
        ellips,
        trapezoid,
        array
    };
}

namespace all_buttons
{
    Button menuBtn(860, 50, 128, 36, "Menu");
    Button addBtn(860, 100, 128, 36, "Add");
    Button moveBtn(860, 150, 128, 36, "Move");
    Button removeBtn(860, 200, 128, 36, "Remove");
    Button eraseBtn(860, 250, 128, 36, "Erase");
    Button circleBtn(860, 50, 128, 36, "Circle");
    Button rectBtn(860, 100, 128, 36, "Rectangle");
    Button ellipseBtn(860, 150, 128, 36, "Ellipse");
    Button trapezoidBtn(860, 200, 128, 36, "Trapezoid");
    Button arrayBtn(860, 250, 128, 36, "Array");
}
int codeB;

std::vector<Button *> settingBtn{
    &all_buttons::menuBtn,
    &all_buttons::addBtn,
    &all_buttons::moveBtn,
    &all_buttons::removeBtn,
    &all_buttons::eraseBtn};

std::vector<Button *> figureBtn{
    &all_buttons::circleBtn,
    &all_buttons::rectBtn,
    &all_buttons::ellipseBtn,
    &all_buttons::trapezoidBtn,
    &all_buttons::arrayBtn};

std::vector<Circle> circs{};
std::vector<Rect> rects{};
std::vector<Ellips> ellps{};
std::vector<Trapezoid> trapezs{};
std::vector<TFigure *> figures{};

bool isShowAllFigures{true};

const void draw_main_menu(SDL_Renderer *renderer)
{
    draw_app(renderer);
    draw_figure_btns(renderer);
    if (isShowAllFigures)
        draw_all_figures(renderer);
    SDL_RenderPresent(renderer);
}

const void draw_figure_menu(SDL_Renderer *renderer)
{
    draw_app(renderer);
    draw_setting_btns(renderer);
    if (isShowAllFigures)
        draw_all_figures(renderer);
    SDL_RenderPresent(renderer);
}

const void add_figure()
{
    switch (codeB)
    {
    case codes::codeBtn::circle:
    {
        Circle circ = Circle();
        circs.push_back(circ);
        break;
    }
    case codes::codeBtn::rect:
    {
        Rect rect = Rect();
        rects.push_back(rect);
        break;
    }
    case codes::codeBtn::ellipse:
    {
        Ellips ellp = Ellips();
        ellps.push_back(ellp);
        break;
    }
    case codes::codeBtn::trapezoid:
    {
        Trapezoid trapz = Trapezoid();
        trapezs.push_back(trapz);
        break;
    }
    case codes::codeBtn::array:
    {
        for (size_t i = 0; i < 21; ++i)
        {
            Rect *rect = new Rect();
            Circle *circ = new Circle();
            Ellips *ellp = new Ellips();
            Trapezoid *trapez = new Trapezoid();
            std::vector<TFigure *> tmpFigures{rect, circ, ellp, trapez};

            figures.push_back(tmpFigures[rand() % 4]);
        }
        break;
    }
    }
}

const void mouse_button_left_process(SDL_Renderer *renderer)
{
    if (settingBtn[ind::settBtn::menu]->is_pressed())
    {
        codeB = codes::codeBtn::menu;
        draw_main_menu(renderer);
        return;
    }
    else if (figureBtn[ind::figBtn::cirlce]->is_pressed())
        codeB = codes::codeBtn::circle;
    else if (figureBtn[ind::figBtn::rect]->is_pressed())
        codeB = codes::codeBtn::rect;
    else if (figureBtn[ind::figBtn::ellips]->is_pressed())
        codeB = codes::codeBtn::ellipse;
    else if (figureBtn[ind::figBtn::trapezoid]->is_pressed())
        codeB = codes::codeBtn::trapezoid;
    else if (figureBtn[ind::figBtn::array]->is_pressed())
        codeB = codes::codeBtn::array;
    else if (settingBtn[ind::settBtn::add]->is_pressed())
        add_figure();
    else if (settingBtn[ind::settBtn::move]->is_pressed())
        move_all_figure(moveCode::RAND);
    else if (settingBtn[ind::settBtn::remove]->is_pressed())
        remove_figure();
    else if (settingBtn[ind::settBtn::erase]->is_pressed())
        erase_figure(renderer);
    else
        return;

    draw_figure_menu(renderer);
}

const void move_all_figure(const char &direction)
{
    switch (codeB)
    {
    case codes::codeBtn::circle:
        for (auto &&circle : circs)
            circle.move(direction);
        break;
    case codes::codeBtn::rect:
        for (auto &&rect : rects)
            rect.move(direction);
        break;
    case codes::codeBtn::ellipse:
        for (auto &&ellips : ellps)
            ellips.move(direction);
        break;
    case codes::codeBtn::trapezoid:
        for (auto &&trapz : trapezs)
            trapz.move(direction);
        break;
    case codes::codeBtn::array:
        for (auto &&figure : figures)
            figure->move(direction);
        break;
    }
}

const void erase_figure(SDL_Renderer *renderer)
{
    isShowAllFigures = !isShowAllFigures;
    if (all_buttons::eraseBtn.name == "Erase")
        all_buttons::eraseBtn.name = "Show";
    else
        all_buttons::eraseBtn.name = "Erase";
}

const void remove_figure()
{
    switch (codeB)
    {
    case codes::codeBtn::circle:
    {
        if (circs.size() < 1)
            break;
        circs.pop_back();
        break;
    }
    case codes::codeBtn::rect:
    {
        if (rects.size() < 1)
            break;
        rects.pop_back();
        break;
    }
    case codes::codeBtn::ellipse:
    {
        if (ellps.size() < 1)
            break;
        ellps.pop_back();
        break;
    }
    case codes::codeBtn::trapezoid:
    {
        if (trapezs.size() < 1)
            break;
        trapezs.pop_back();
        break;
    }
    case codes::codeBtn::array:
    {
        if (figures.size() < 1)
            break;
        for (auto &&figure : figures)
            delete figure;
        figures.clear();
        break;
    }
    }
}

const void increase_radius()
{
    if (codeB == codes::codeBtn::circle && circs.size() > 0)
        for (auto &&circle : circs)
            circle.change_rad(5, true);
    if (codeB == codes::codeBtn::rect && rects.size() > 0)
        for (auto &&rect : rects)
            rect.change_size(5, true);
    if (codeB == codes::codeBtn::ellipse && ellps.size() > 0)
        for (auto &&ellips : ellps)
            ellips.change_rad(6, 3, true);
    if (codeB == codes::codeBtn::trapezoid && trapezs.size() > 0)
        for (auto &&trapz : trapezs)
            trapz.change_size(5, true);
}

const void reduce_radius()
{
    if (codeB == codes::codeBtn::circle && circs.size() > 0)
        for (auto &&circle : circs)
            circle.change_rad(-5, false);
    if (codeB == codes::codeBtn::rect && rects.size() > 0)
        for (auto &&rect : rects)
            rect.change_size(-5, false);
    if (codeB == codes::codeBtn::ellipse && ellps.size() > 0)
        for (auto &&ellips : ellps)
            ellips.change_rad(-6, -3, false);
    if (codeB == codes::codeBtn::trapezoid && trapezs.size() > 0)
        for (auto &&trapz : trapezs)
            trapz.change_size(-5, false);
}

const void rotate()
{
    if (codeB == codes::codeBtn::ellipse && ellps.size() > 0)
        for (auto &&ellips : ellps)
            ellips.rotate();
}

const void draw_all_figures(SDL_Renderer *renderer)
{
    for (auto &&circle : circs)
        circle.show(renderer);
    for (auto &&rect : rects)
        rect.show(renderer);
    for (auto &&ellips : ellps)
        ellips.show(renderer);
    for (auto &&trapez : trapezs)
        trapez.show(renderer);
    for (auto &&figure : figures)
        figure->show(renderer);
}

const void draw_setting_btns(SDL_Renderer *renderer)
{
    for (auto &&i : settingBtn)
        draw_btn(renderer, *i);
    for (auto &&i : figureBtn)
        (*i).isVisible = false;
}

const void draw_figure_btns(SDL_Renderer *renderer)
{
    for (auto &&i : figureBtn)
        draw_btn(renderer, *i);
    for (auto &&i : settingBtn)
        (*i).isVisible = false;
}

const void draw_app(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0x22, 0x2D, 0x32, 0xFF);
    SDL_RenderClear(renderer);
    draw_cart(renderer);
    draw_figure_btns(renderer);
}

const void draw_btn(SDL_Renderer *renderer, Button &btn)
{
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &btn.btn);
    SDL_RenderDrawRect(renderer, &btn.btn);
    btn.set_label(renderer);
    btn.isVisible = true;
}

const void draw_cart(SDL_Renderer *renderer)
{
    // поверхность коорд плоскости
    SDL_Rect cartRect;
    cartRect.w = cartCoord[coord::cart::x2];
    cartRect.h = cartCoord[coord::cart::y2];
    cartRect.x = cartCoord[coord::cart::x1];
    cartRect.y = cartCoord[coord::cart::y1];
    SDL_SetRenderDrawColor(renderer, 0x69, 0x69, 0x69, 0xFF);
    SDL_RenderFillRect(renderer, &cartRect);
    SDL_RenderDrawRect(renderer, &cartRect);

    // линии коорд плоскости
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(renderer, 410, 20, 410, 620);
    SDL_RenderDrawLine(renderer, 20, 300, 820, 300);
    SDL_RenderDrawLine(renderer, 410, 20, 415, 25);
    SDL_RenderDrawLine(renderer, 410, 20, 405, 25);
    SDL_RenderDrawLine(renderer, 820, 300, 815, 305);
    SDL_RenderDrawLine(renderer, 820, 300, 815, 295);
}