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

  SDL_Window* window = SDL_CreateWindow("misseis e meteoros e lasers", 100, 100,
                                        DEFINED::WIN_W, DEFINED::WIN_H, 2);

  SDL_Renderer* render =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;

  /* ---------------------------- declarations --------------------------- */

  bool exit = false;
  MeteorManager metman;

  std::unique_ptr<Ray> ray1 = std::make_unique<Ray>(Vetor{0, 0}, Vetor{1, 1});
  std::unique_ptr<Missile> mis1 =
      std::make_unique<Missile>(Vetor{300, 300}, Vetor{}, Vetor{}, 10, 0.25);
  std::unique_ptr<Missile> mis2 =
      std::make_unique<Missile>(Vetor{-300, -300}, Vetor{}, Vetor{}, 5, 0.5);
  std::unique_ptr<Missile> mis3 =
      std::make_unique<Missile>(Vetor{300, -300}, Vetor{}, Vetor{}, 7.5, 0.375);

  unsigned int red_death_counter{};
  int mouse_x{};
  int mouse_y{};
  Vetor mouse_position;

  while (!exit) {
    if (red_death_counter >= 255) {
      exit = true;
      SDL_Delay(600);
      break;
    }
    /* -------------------------- setup do mouse -------------------------- */

    SDL_GetMouseState(&mouse_x, &mouse_y);
    mouse_position = Vetor{(double)mouse_x, double(mouse_y)};
    mouse_position -= DEFINED::WIN_CENTER;  // arrumar coordenadas
    mouse_position.y *= -1;                 // arrumar eixo

    /* ----------------------- event polling do SDL2 ---------------------- */

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

    /* -------------------------------- coisas -------------------------------- */

    if (metman.return_list().size() < 100) {
      double r_x =
          biased_rand(-DEFINED::WIN_CENTER.x - 70, DEFINED::WIN_CENTER.x + 70);
      Vetor pos{r_x, DEFINED::WIN_CENTER.y + 100};
      double r_v_x = (double)biased_rand(-50, 50) / 1000;
      double r_v_y = (double)biased_rand(10, 100) / -75;
      Vetor vel{r_v_x, r_v_y};
      double r_r = biased_rand(10, 40);
      double radius{r_r};
      metman.create_meteor(pos, vel, {}, radius);
    }

    SDL_SetRenderDrawColor(render, red_death_counter, 0, 0, 255);  // black
    // SDL_SetRenderDrawColor(render, 255, 255, 255, 255);  // white

    SDL_RenderClear(render);  // background

    /* --------------------------- draw sequence--------------------------- */
    ray1->change_direction(mouse_position);

    // SDL_SetRenderDrawColor(render, 205, 205, 205, 255);  // bright

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);  // white
    // SDL_SetRenderDrawColor(render, 0, 0, 0, 255);  // black
    draw_cartesian_plane(render, DEFINED::WIN_CENTER);

    for (auto& meteor : metman.return_list()) {
      meteor->update();
      meteor->draw(render);
      if (ray1->update(*meteor)) {
        mis1->change_target(ray1->get_point());
        mis2->change_target(ray1->get_point());
        mis3->change_target(ray1->get_point());
      }
      if (meteor->check_bounds())
        red_death_counter += 10;

      if (mis1->check_explode(meteor) || mis2->check_explode(meteor) ||
          mis3->check_explode(meteor))
        if (red_death_counter != 0)
          red_death_counter -= 1;
    }

    for (auto& meteor : metman.return_list()) {
      if (meteor->check_destroy() || meteor->check_bounds()) {
        metman.destroy_meteor(meteor);
        break;
      }
    };

    mis1->update();
    mis2->update();
    mis3->update();
    SDL_SetRenderDrawColor(render, 255, 0, 255, 255);  // missile color
    mis1->draw(render);
    SDL_SetRenderDrawColor(render, 0, 0, 255, 255);    // missile color
    mis2->draw(render);
    SDL_SetRenderDrawColor(render, 0, 255, 0, 255);    // missile color
    mis3->draw(render);

    SDL_SetRenderDrawColor(render, 255, red_death_counter, 0, 255);  // red

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