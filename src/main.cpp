#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

#include "entities.h"
#include "functions.h"
#include "structures.h"

#define WINDOW_W 800
#define WINDOW_H 600
int* currentMouseX = new int;
int* currentMouseY = new int;

int main() {
  using std::cout, std::endl, std::cerr;
  /* ------------------------- SDL initialization ------------------------- */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("seeker", 100, 100, WINDOW_W, WINDOW_H,
                                        SDL_WINDOW_SHOWN);
  SDL_Renderer* render =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;

  /* ---------------------------- declarations ---------------------------- */
  bool exit = false;

  Point mouse_pos{(double)*currentMouseX, (double)*currentMouseY};

  // balloon b1;
  // b1.set(render, {600, 500}, {0, -3}, {});
  // fazer um negocio q gera missels qnd clica
  // missile m1;
  // m1.set(render, {800, 500}, {}, {}, 10, 0.2, b1.position);

  // std::vector<drawable*> draw_list;

  std::vector<std::unique_ptr<drawable>> draw_list;
  // render, {20, 250}, {}, {}, 7, 0.3, mouse_pos
  draw_list.push_back(std::make_unique<missile>(render, Point{50, 250}, Point{},
                                                Point{}, 10, 0.3, mouse_pos));
  draw_list.push_back(std::make_unique<missile>(render, Point{500, 25}, Point{},
                                                Point{}, 10, 0.3, mouse_pos));
  draw_list.push_back(std::make_unique<missile>(render, Point{70, 150}, Point{},
                                                Point{}, 10, 0.3, mouse_pos));

  while (!exit) {
    SDL_GetMouseState(currentMouseX, currentMouseY);
    mouse_pos.x = (double)*currentMouseX;
    mouse_pos.y = (double)*currentMouseY;
    /* --------------------------- event polling -------------------------- */

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          exit = true;
        } break;
        case SDL_KEYDOWN: {
          if (event.key.keysym.sym == SDLK_q) {
            exit = true;
          }
        } break;
      }
    }

    /* ------------------------------- loop ------------------------------- */

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

    draw_circle(render, mouse_pos, 10);

    for (auto t = draw_list.begin(); t != draw_list.end();) {
      if ((*t)->check_death()) {
        t = draw_list.erase(t);
      } else {
        t++;
      }
    }

    for (auto& d : draw_list) {
      d->update();
      d->draw();
    };

    SDL_RenderPresent(render);
    SDL_Delay(20);
  }

  /* ---------------------------- end sequence ---------------------------- */

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}