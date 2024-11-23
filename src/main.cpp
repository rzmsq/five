#include "../include/main.hpp"

int main(int argc, char *args[])
{
    SDL_Window *window{nullptr};
    SDL_Surface *screenSurface{nullptr};
    SDL_Renderer *renderer{nullptr};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << '\n';
    else if (TTF_Init() < 0)
        std::cerr << "TTF could not initialize! TTF_Error: " << TTF_GetError() << '\n';
    else
    {
        window = SDL_CreateWindow("Lab-1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (window == NULL)
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
        else
        {
            draw_app(renderer);
            SDL_RenderPresent(renderer);

            SDL_Event e;
            bool quit{false};
            int figCod = figureCode::ALL;
            while (quit == false)
            {
                while (SDL_PollEvent(&e))
                {
                    switch (e.type)
                    {
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (e.button.button == SDL_BUTTON_LEFT)
                            mouse_button_left_process(renderer, figCod);
                        break;
                    case SDL_KEYDOWN:
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_1:
                            figCod = figureCode::CIRCLE;
                            break;
                        case SDLK_2:
                            figCod = figureCode::RECT;
                            break;
                        case SDLK_3:
                            figCod = figureCode::ALL;
                            break;
                        case SDLK_KP_PLUS:
                        {
                            increase_radius();
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_KP_MINUS:
                        {
                            reduce_radius();
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_F10:
                        {
                            rotate();
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_RIGHT:
                        {
                            move_all_figure(moveCode::RIGHT, figCod);
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_LEFT:
                        {
                            move_all_figure(moveCode::LEFT, figCod);
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_UP:
                        {
                            move_all_figure(moveCode::UP, figCod);
                            draw_figure_menu(renderer);
                            break;
                        }
                        case SDLK_DOWN:
                        {
                            move_all_figure(moveCode::DOWN, figCod);
                            draw_figure_menu(renderer);
                            break;
                        }
                        }
                        break;
                    }
                    }
                }
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
