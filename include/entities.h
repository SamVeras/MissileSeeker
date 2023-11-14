#pragma once

#include "structures.h"
#include <SDL2/SDL.h>

class drawable {
public:
  SDL_Renderer *renderer;
  Point position{};
  bool kill_this{false};

  virtual void update();
  virtual void draw();
};

class movable : public drawable {
public:
  Point velocity{};
  Point acceleration{};

  void update() override;
  void draw() override;
};

class missile final : public movable {
public:
  double max_speed{};
  double max_force{};
  const Point *target_position;

  void set(SDL_Renderer *ren, Point pos, Point vel, Point acc, double m_spd,
           double m_frc,
           const Point &t_pos);  // might need to make dummy target default?
  void track();
  void update() override final;
  void draw() override final;
  void explode();
};

class balloon final : public movable {
public:
  int size{25};

  void set(SDL_Renderer *ren, Point pos, Point vel, Point acc);
  void draw() override final;
};