#pragma once
#include <SDL2/SDL.h>
#include "vetor.h"

void draw_circle(SDL_Renderer* renderer, Vetor coords, double radius);
double distance(Vetor p1, Vetor p2);
double to_radians(double degrees);
double to_degrees(double radians);