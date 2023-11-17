#include "SDL_wrappers.h"

int draw_line(SDL_Renderer* renderer, Vetor A, Vetor B) {
   return SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
}