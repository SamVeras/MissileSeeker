#pragma once
#include <SDL2/SDL.h>
#include "defined.h"
#include "vetor.h"

int draw_line(SDL_Renderer* renderer, Vetor A, Vetor B);
int draw_point(SDL_Renderer* renderer, Vetor P);

void draw_circle(SDL_Renderer* ren, Vetor center, double radius);
void draw_filled_circle(SDL_Renderer* ren, Vetor center, double radius);

void draw_cartesian_plane(SDL_Renderer* ren, Vetor offset);
void draw_grid(SDL_Renderer* ren, int step, Vetor offset);