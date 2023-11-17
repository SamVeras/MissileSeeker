#pragma once
#include <SDL2/SDL.h>
#include "vetor.h"

int draw_line(SDL_Renderer* renderer, Vetor A, Vetor B);
int draw_point(SDL_Renderer* renderer, Vetor P);