#include "mouse_laser.h"
#include "functions.h"

mouse_laser::mouse_laser(SDL_Renderer* ren, Vetor pos, Vetor const& mouse_pos)
    : ray::ray(ren, pos, {}), mouse_ref(mouse_pos) {
   this->update();
};

void mouse_laser::update() {
   this->direction = {mouse_ref.x, mouse_ref.y};
   Vetor N = (this->position - this->direction).normalized();
   N *= -1;
   this->end_point = N * 1000;
}