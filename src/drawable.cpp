#include "drawable.h"

drawable::drawable(SDL_Renderer* ren, Vetor pos)
    : renderer(ren), position(pos), kill_this(false){};

void drawable::update(){};

void drawable::draw(){};