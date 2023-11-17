#include <cmath>

#include "functions.h"

void draw_circle(SDL_Renderer* renderer, Vetor coords, double radius) {
   const int diameter = (radius * 2);

   int x = radius - 1;
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = tx - diameter;

   while (x >= y) {
      // Each renders an octant of the circle
      SDL_RenderDrawPoint(renderer, coords.x + x, coords.y + y);
      SDL_RenderDrawPoint(renderer, coords.x + x, coords.y - y);
      SDL_RenderDrawPoint(renderer, coords.x - x, coords.y + y);
      SDL_RenderDrawPoint(renderer, coords.x - x, coords.y - y);
      SDL_RenderDrawPoint(renderer, coords.x + y, coords.y - x);
      SDL_RenderDrawPoint(renderer, coords.x + y, coords.y + x);
      SDL_RenderDrawPoint(renderer, coords.x - y, coords.y - x);
      SDL_RenderDrawPoint(renderer, coords.x - y, coords.y + x);

      if (error <= 0) {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0) {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
};

double distance(Vetor p1, Vetor p2) {
   return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};

double to_radians(double degrees) {
   return degrees * (M_PI / 180);
};

double to_degrees(double radians) {
   return radians * (180 / M_PI);
};