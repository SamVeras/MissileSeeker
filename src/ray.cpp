#include "ray.h"
#include "SDL_wrappers.h"

Ray::Ray(SDL_Renderer* ren, Vetor pos, Vetor dir)
    : Drawable::Drawable(ren, pos), direction(dir){};

void Ray::update(){

};

void Ray::draw() {
   draw_line(this->renderer, this->position, this->end_point * 50);
};