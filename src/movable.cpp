#include "movable.h"

movable::movable(SDL_Renderer* ren, Vetor pos, Vetor vel, Vetor acc)
    : drawable{ren, pos}, velocity(vel), acceleration(acc){};

void movable::update() {
   this->velocity += this->acceleration;
   this->position += this->velocity;
   this->acceleration = {0.0, 0.0};
};

void movable::draw() {
   double cx1{this->position.x - 15}, cx2{this->position.x + 15};
   double cy1{this->position.y - 15}, cy2{this->position.y + 15};
   SDL_RenderDrawLine(this->renderer, cx1, cy1, cx2, cy2);
};

bool drawable::check_death() {
   return this->kill_this;
};