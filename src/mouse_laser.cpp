#include "mouse_laser.h"
#include "functions.h"

MouseLaser::MouseLaser(SDL_Renderer* ren, Vetor pos, Vetor const& mouse_pos)
    : Ray::Ray(ren, pos, {}), mouse_ref(mouse_pos) {
   this->update();
};

void MouseLaser::update() {
   this->direction = {mouse_ref.x, mouse_ref.y};
   Vetor N = (this->position - this->direction).normalized() * -1;
   this->end_point = N * 1000;
}