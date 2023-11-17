#pragma once
#include "drawable.h"

class ray : public drawable {
  protected:
   Vetor direction;
   double length{5000};
   Vetor end_point;

  public:
   void update() override;
   void draw() override;

   ray(SDL_Renderer* ren, Vetor pos, Vetor dir);
};