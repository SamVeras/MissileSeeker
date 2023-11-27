#pragma once
#include <SDL2/SDL.h>
#include "SDL_wrappers.h"
#include "vetor.h"

class Mobile {
 protected:
  Vetor position;
  Vetor velocity;
  Vetor acceleration;
  bool destroy{false};
  bool out_of_bounds{false};

 public:
  void change_position(Vetor new_pos);
  void mark_for_destroy();
  void mark_out_of_bounds();
  const Vetor& get_position() const;
  const bool& check_destroy() const;
  const bool& check_bounds() const;

  virtual void update();
  virtual void draw(SDL_Renderer* render) const;

  Mobile(Vetor pos, Vetor vel, Vetor acc);
};