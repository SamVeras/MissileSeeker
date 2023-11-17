#include "drawable.h"

Drawable::Drawable(SDL_Renderer* ren, Vetor pos)
    : renderer(ren), position(pos), kill_this(false){};

void Drawable::update(){};

void Drawable::draw(){};