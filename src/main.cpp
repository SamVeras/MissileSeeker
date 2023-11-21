#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <vector>

#include "SDL_wrappers.h"
#include "defined.h"
#include "functions.h"
#include "meteor.h"
#include "missile.h"
#include "ray.h"

int main() {
  using std::cout, std::endl, std::cerr;
  /* ------------------------- SDL2 Inicialização ------------------------ */

  SDL_Init(SDL_INIT_VIDEO);

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

  SDL_Window* window = SDL_CreateWindow("RAYCAST", 100, 100, DEFINED::WIN_W,
                                        DEFINED::WIN_H, SDL_WINDOW_OPENGL);

  SDL_Renderer* render =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;

  /* ---------------------------- Declarations --------------------------- */
  bool exit = false;

  MeteorManager metman;

  // for (unsigned int i = 0; i < 50; i++) {
  //   double rvy = 20 / (double)biased_randint(10, 20);
  //   double rvx = 1 / (double)biased_randint(-5, 5);
  //   double rx = biased_randint(-350, 350);
  //   double ry = biased_randint(300, 400);
  //   int r = biased_randint(5, 25);
  //   metman.create_meteor({rx, ry}, {rvx, -rvy}, {}, r);
  // }

  metman.create_meteor({-200, 300}, {0, -1}, {0, 0}, 34);
  metman.create_meteor({200, 300}, {0, -1.3}, {0, 0}, 13);
  metman.create_meteor({300, 300}, {0, -0.9}, {0, 0}, 22);

  std::unique_ptr<Ray> ray1 = std::make_unique<Ray>(Vetor{0, 0}, Vetor{1, 1});
  std::unique_ptr<Missile> mis1 =
      std::make_unique<Missile>(Vetor{300, 300}, Vetor{}, Vetor{}, 2, 0.1, 2);

  int m_x;
  int m_y;
  Vetor current_mouse_position;

  while (!exit) {
    SDL_GetMouseState(&m_x, &m_y);
    current_mouse_position =
        Vetor{(double)m_x, double(m_y)} - DEFINED::WIN_CENTER;
    current_mouse_position.y *= -1;
    /* ----------------------- SDL2 Event Polling ----------------------- */
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT: {
          exit = true;
        } break;
        case SDL_KEYDOWN: {
          if (event.key.keysym.sym == SDLK_q)
            exit = true;
        } break;
      }
    }

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);  // white
    SDL_RenderClear(render);                             // background

    SDL_SetRenderDrawColor(render, 220, 220, 220, 255);  // grayish
    draw_grid(render, 15, {});

    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);        // black
    draw_cartesian_plane(render, {});

    /* --------------------------- draw meteors --------------------------- */
    ray1->change_direction(current_mouse_position);
    for (std::unique_ptr<Meteor>& meteor : metman.return_list()) {
      meteor->update();
      meteor->draw(render);
      if (ray1->update(*meteor)) {
        mis1->change_target(ray1->get_point());
      }
    }

    // if (ray1->update(*meteor))
    //   meteor->mark_for_destroy();

    // for (std::unique_ptr<Meteor>& meteor : metman.return_list()) {
    //   if (meteor->check_destroy()) {
    //     metman.destroy_meteor(meteor);
    //     break;
    //   }
    // };

    mis1->update();
    mis1->draw(render);

    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);  // black

    ray1->draw(render);

    SDL_RenderPresent(render);
    SDL_Delay(15);  // 15ms
  }
  /* ---------------------------- End Sequence --------------------------- */

  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}