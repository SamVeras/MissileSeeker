#pragma once

#include <SDL2/SDL.h>
#include "structures.h"

class movable {
 public:
  Point position{};
  Point velocity{};
  Point acceleration{};

  void update();
  void draw(SDL_Renderer* renderer);
};

class missile : public movable {
 public:
  double max_speed{};

  void track(const Point& target_position);
  void draw(SDL_Renderer* renderer);
};

class balloon : public movable {
 public:
  int size{1};

  void draw(SDL_Renderer* renderer);
};