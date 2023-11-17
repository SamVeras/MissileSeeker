#pragma once
#include "drawable.h"

class movable : public drawable {
  public:
   Vetor velocity;
   Vetor acceleration;

   void update() override;
   void draw() override;

   movable(SDL_Renderer* ren, Vetor pos, Vetor vel, Vetor acc);
};