#pragma once
#include <SDL2/SDL.h>
#include "SDL_wrappers.h"
#include "vetor.h"

class Mobile {
 protected:
  Vetor position;
  Vetor velocity;
  Vetor acceleration;
  bool destroy;

 public:
  void change_position(Vetor new_pos);
  void mark_for_destroy();
  const Vetor& get_position() const;
  const bool& check_destroy() const;

  virtual void update();
  virtual void draw(SDL_Renderer* render) const;

  Mobile(Vetor pos, Vetor vel, Vetor acc);
};