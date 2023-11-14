#pragma once

#include <SDL2/SDL.h>

#include "structures.h"

class movable {
 public:
  Point position{};
  Point velocity{};
  Point acceleration{};
  SDL_Renderer* renderer;

  void update();
  void draw();
};

class missile : public movable {
 public:
  double max_speed{};
  double max_force{};
  Point* target_position;

  void track();
  void update();
  void draw();
  void explode();
};

class balloon : public movable {
 public:
  int size{1};

  void draw();
};

// class circle {
//  public:
//   double radius;
//   void ;
// };