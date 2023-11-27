#pragma once
#include "SDL_wrappers.h"
#include "meteor.h"
#include "vetor.h"

struct RayCheck {
  double hit_length;
  Vetor hit_position;
  bool result;
};

class Ray {
 protected:
  Vetor start;
  Vetor direction;
  Vetor end_point;
  double current_length;
  RayCheck check_collision(const Meteor& target) const;

 public:
  void change_position(Vetor new_pos);
  void change_direction(Vetor new_dir);
  const Vetor& get_point() const;
  const Vetor& get_start() const;
  bool update(const Meteor& target);
  void draw(SDL_Renderer* render);

  Ray(Vetor pos, Vetor dir);
};
