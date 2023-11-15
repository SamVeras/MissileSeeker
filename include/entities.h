#pragma once

#include <SDL2/SDL.h>
#include "structures.h"

class drawable {
 protected:
  SDL_Renderer* renderer;
  bool kill_this;

 public:
  Point position;

  virtual bool check_death();
  virtual void update();
  virtual void draw();

  drawable(SDL_Renderer* ren, Point pos);
};

class movable : public drawable {
 public:
  Point velocity;
  Point acceleration;

  void update() override;
  void draw() override;

  movable(SDL_Renderer* ren, Point pos, Point vel, Point acc);
};

class missile final : public movable {
 private:
  const Point& target_position;

  void explode();
  void track();

 public:
  double max_speed{0.0};
  double max_force{0.0};

  void update() override final;
  void draw() override final;

  missile(SDL_Renderer* ren,
          Point pos,
          Point vel,
          Point acc,
          double m_spd,
          double m_frc,
          const Point& t_pos);
};

class balloon final : public movable {
 private:
  int size{25};

 public:
  void draw() override final;

  balloon(SDL_Renderer* ren, Point pos, Point vel, Point acc);
};