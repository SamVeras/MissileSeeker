#pragma once
#include "drawable.h"

class Ray : public Drawable {
  protected:
   Vetor direction;
   double length{5000};
   Vetor end_point;

  public:
   void update() override;
   void draw() override;

   Ray(SDL_Renderer* ren, Vetor pos, Vetor dir);
};