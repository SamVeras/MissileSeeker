#pragma once
#include "ray.h"

class MouseLaser : public Ray {
  private:
   Vetor const& mouse_ref;

  public:
   void update() override final;

   MouseLaser(SDL_Renderer* ren, Vetor pos, Vetor const& mouse_pos);
};