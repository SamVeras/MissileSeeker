#pragma once
#include <memory>
#include <vector>
#include "meteor.h"
#include "mobile.h"

class Missile : public Mobile {
 private:
  Vetor target_position;
  double max_speed = 0.0;
  double max_force = 0.0;

  void track_target();

 public:
  bool check_explode(std::unique_ptr<Meteor>& objeto);
  void update() override;
  void draw(SDL_Renderer* render) const override;
  void change_target(Vetor new_target_position);
  const Vetor& get_target() const;
  Missile(Vetor pos, Vetor vel, Vetor acc, double m_spd, double m_frc);
};
