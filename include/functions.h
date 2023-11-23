#pragma once
#include <SDL2/SDL.h>
#include "vetor.h"

double distance(Vetor p1, Vetor p2);
double to_radians(double degrees);
double to_degrees(double radians);
int biased_rand(int min, int max);
