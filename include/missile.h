#pragma once
#include "movable.h"

class Missile final : public Movable {
  private:
   const Vetor& target_position;

   void explode();
   void track();

  public:
   double max_speed{0.0};
   double max_force{0.0};

   void update() override final;
   void draw() override final;

   Missile(
       SDL_Renderer* ren,
       Vetor pos,
       Vetor vel,
       Vetor acc,
       double m_spd,
       double m_frc,
       const Vetor& t_pos
   );
};