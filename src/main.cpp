#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "entities.h"
#include "functions.h"
#include "structures.h"

#define WINDOW_W 800
#define WINDOW_H 600
int *currentMouseX = new int;
int *currentMouseY = new int;

int main() {
  using std::cout, std::endl, std::cerr;
  /* ------------------------- SDL initialization ------------------------- */
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("seeker", 100, 100, WINDOW_W, WINDOW_H,
                                        SDL_WINDOW_SHOWN);
  SDL_Renderer *render =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;

  /* ---------------------------- declarations ---------------------------- */
  bool exit = false;
  balloon b1;
  b1.set(render, {600, 500}, {0, -3}, {});

  missile m1;
  m1.set(render, {100, 100}, {}, {}, 6, 3, b1.position);

  // std::vector<drawable> objects;
  // objects.push_back(m1);

  while (!exit) {
    /* --------------------------- event polling -------------------------- */
    SDL_GetMouseState(currentMouseX, currentMouseY);

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
    // draw_circle(render, {WINDOW_W / 2, WINDOW_H / 2}, 90);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    m1.update();
    m1.draw();
    b1.update();
    b1.draw();
    SDL_RenderPresent(render);
    SDL_Delay(20);
  }

  /* ---------------------------- end sequence ---------------------------- */

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}