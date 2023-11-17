#pragma once
#include "drawable.h"

class Movable : public Drawable {
  public:
   Vetor velocity;
   Vetor acceleration;

   void update() override;
   void draw() override;

   Movable(SDL_Renderer* ren, Vetor pos, Vetor vel, Vetor acc);
};