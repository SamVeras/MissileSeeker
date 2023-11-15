#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

#include "entities.h"
#include "functions.h"
#include "global.h"

/* ------------------------------------------------------------------------ */
/*                              Drawable class                              */
/* ------------------------------------------------------------------------ */
drawable::drawable(SDL_Renderer* ren, Point pos)
    : renderer(ren), position(pos), kill_this(false){};

void drawable::update(){};
void drawable::draw(){};

/* ------------------------------------------------------------------------ */
/*                                 Ray class                                */
/* ------------------------------------------------------------------------ */

ray::ray(SDL_Renderer* ren, Point pos, double ang)
    : drawable::drawable(ren, pos), angle(ang){};

void ray::update() {
   double x = this->length * cos(angle);
   double y = this->length * sin(angle);
   this->end_point = this->position + Point{x, -y};
};

void ray::draw() {
   SDL_RenderDrawLine(
       this->renderer, this->position.x, this->position.y, this->end_point.x,
       this->end_point.y
   );
};
/* ------------------------------ Mouse laser ----------------------------- */

mouse_laser::mouse_laser(SDL_Renderer* ren, Point pos, Point const& mouse_pos)
    : ray::ray(ren, pos, 0), mouse_ref(mouse_pos) {
   this->update();
};

void mouse_laser::update() {
   this->angle = atan2(
       -(this->mouse_ref.y - this->position.y),
       this->mouse_ref.x - this->position.x
   );
   double x = this->length * cos(angle);
   double y = this->length * sin(angle);
   this->end_point = this->position + Point{x, -y};
}

/* ------------------------------------------------------------------------ */
/*                               Movable class                              */
/* ------------------------------------------------------------------------ */
movable::movable(SDL_Renderer* ren, Point pos, Point vel, Point acc)
    : drawable{ren, pos}, velocity(vel), acceleration(acc){};

void movable::update() {
   // this->velocity += global::gravity_acceleration;
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

/* -------------------------------------------------------------------------- */
/*                                Missile class                               */
/* -------------------------------------------------------------------------- */

missile::missile(
    SDL_Renderer* ren,
    Point pos,
    Point vel,
    Point acc,
    double max_s,
    double max_f,
    const Point& t_pos
)
    : movable{ren, pos, vel, acc},
      target_position(t_pos),
      max_speed(max_s),
      max_force(max_f){};

void missile::track() {
   Point desired_velocity{target_position - this->position};
   desired_velocity.set_magnitude(this->max_speed);
   desired_velocity -= this->velocity;
   desired_velocity.limit(this->max_force);
   this->acceleration += desired_velocity;
};

void missile::update() {
   // this->velocity += global::gravity_acceleration;
   this->track();
   if (get_distance(this->position, target_position) < 25) {
      this->explode();
   };
   this->velocity += this->acceleration;
   this->position += this->velocity;
   this->acceleration = {0.0, 0.0};
};

void missile::draw() {
   Point copy_vel = this->velocity;
   copy_vel.set_magnitude(18);
   Point head = this->position + copy_vel;
   SDL_RenderDrawLine(
       this->renderer, this->position.x, this->position.y, head.x, head.y
   );
};

void missile::explode() {
   draw_circle(this->renderer, this->position, 60);
   SDL_Delay(100);
   this->kill_this = true;
};

/* -------------------------------------------------------------------------- */
/*                                Balloon class                               */
/* -------------------------------------------------------------------------- */

balloon::balloon(SDL_Renderer* ren, Point pos, Point vel, Point acc)
    : movable{ren, pos, vel, acc} {};

void balloon::draw() {
   draw_circle(this->renderer, this->position, this->size);
}
