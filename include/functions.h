#pragma once

#include "structures.h"
#include <SDL2/SDL.h>

void draw_circle(SDL_Renderer *renderer, Point coords, double radius);
double get_distance(Point p1, Point p2);