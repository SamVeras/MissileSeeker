#pragma once

#include <SDL2/SDL.h>

#include "structures.h"

void draw_circle(SDL_Renderer *renderer, Point coords, double radius);

double get_distance(Point p1, Point p2);