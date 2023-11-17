#include "ray.h"
#include "SDL_wrappers.h"

ray::ray(SDL_Renderer* ren, Vetor pos, Vetor dir)
    : drawable::drawable(ren, pos), direction(dir){};

void ray::update(){

};

void ray::draw() {
   draw_line(this->renderer, this->position, this->end_point * 50);
};