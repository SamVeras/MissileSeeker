#include "SDL_wrappers.h"

int draw_line(SDL_Renderer* renderer, Vetor A, Vetor B) {
   return SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
};

int draw_point(SDL_Renderer* renderer, Vetor P) {
   return SDL_RenderDrawPoint(renderer, P.x, P.y);
};