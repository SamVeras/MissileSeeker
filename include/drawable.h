#pragma once
#include <SDL2/SDL.h>
#include "vetor.h"

class drawable {
  protected:
   SDL_Renderer* renderer;
   Vetor position;
   bool kill_this;

  public:
   virtual bool check_death();
   virtual void update();
   virtual void draw();

   drawable(SDL_Renderer* ren, Vetor pos);
};