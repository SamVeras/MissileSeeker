#pragma once
#include <SDL2/SDL.h>
#include "vetor.h"

void draw_circle(SDL_Renderer* ren, Vetor center, double radius);
void draw_filled_circle(SDL_Renderer* ren, Vetor center, double radius);
double distance(Vetor p1, Vetor p2);
double to_radians(double degrees);
double to_degrees(double radians);