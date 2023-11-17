#pragma once
#include "ray.h"

class mouse_laser : public ray {
  private:
   Vetor const& mouse_ref;

  public:
   void update() override final;

   mouse_laser(SDL_Renderer* ren, Vetor pos, Vetor const& mouse_pos);
};