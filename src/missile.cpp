#include "missile.h"
#include "functions.h"

Missile::Missile(
    SDL_Renderer* ren,
    Vetor pos,
    Vetor vel,
    Vetor acc,
    double max_s,
    double max_f,
    const Vetor& t_pos
)
    : Movable{ren, pos, vel, acc},
      target_position(t_pos),
      max_speed(max_s),
      max_force(max_f){};

void Missile::track() {
   Vetor tracking_velocity{target_position - this->position};
   tracking_velocity.set_magnitude(this->max_speed);
   tracking_velocity -= this->velocity;
   tracking_velocity.limit(this->max_force);
   this->acceleration += tracking_velocity;
};

void Missile::update() {
   this->track();
   if (distance(this->position, target_position) < 25) {
      this->explode();
   };
   this->velocity += this->acceleration;
   this->velocity.limit(max_speed);
   this->position += this->velocity;
   this->acceleration = {0.0, 0.0};
};

void Missile::draw() {
   Vetor copy_vel = this->velocity;
   copy_vel.set_magnitude(18);
   Vetor head = this->position + copy_vel;
   SDL_RenderDrawLine(
       this->renderer, this->position.x, this->position.y, head.x, head.y
   );
};

void Missile::explode() {
   draw_circle(this->renderer, this->position, 60);
   SDL_Delay(100);
   this->kill_this = true;
};