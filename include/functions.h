#pragma once

#include <SDL2/SDL.h>
#include "structures.h"

void draw_circle(SDL_Renderer* renderer, Point coords, double radius);
double get_distance(Point p1, Point p2);
double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);