#include "missile.h"
#include "functions.h"

missile::missile(
    SDL_Renderer* ren,
    Vetor pos,
    Vetor vel,
    Vetor acc,
    double max_s,
    double max_f,
    const Vetor& t_pos
)
    : movable{ren, pos, vel, acc},
      target_position(t_pos),
      max_speed(max_s),
      max_force(max_f){};

void missile::track() {
   Vetor desired_velocity{target_position - this->position};
   desired_velocity.set_magnitude(this->max_speed);
   desired_velocity -= this->velocity;
   desired_velocity.limit(this->max_force);
   this->acceleration += desired_velocity;
};

void missile::update() {
   // this->velocity += global::gravity_acceleration;
   this->track();
   if (distance(this->position, target_position) < 25) {
      this->explode();
   };
   this->velocity += this->acceleration;
   this->position += this->velocity;
   this->acceleration = {0.0, 0.0};
};

void missile::draw() {
   Vetor copy_vel = this->velocity;
   copy_vel.set_magnitude(18);
   Vetor head = this->position + copy_vel;
   SDL_RenderDrawLine(
       this->renderer, this->position.x, this->position.y, head.x, head.y
   );
};

void missile::explode() {
   draw_circle(this->renderer, this->position, 60);
   SDL_Delay(100);
   this->kill_this = true;
};