#include "movable.h"

Movable::Movable(SDL_Renderer* ren, Vetor pos, Vetor vel, Vetor acc)
    : Drawable{ren, pos}, velocity(vel), acceleration(acc){};

void Movable::update() {
   this->velocity += this->acceleration;
   this->position += this->velocity;
   this->acceleration = {0.0, 0.0};
};

void Movable::draw() {
   double cx1{this->position.x - 15}, cx2{this->position.x + 15};
   double cy1{this->position.y - 15}, cy2{this->position.y + 15};
   SDL_RenderDrawLine(this->renderer, cx1, cy1, cx2, cy2);
};

bool Drawable::check_death() {
   return this->kill_this;
};