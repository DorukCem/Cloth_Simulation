#pragma once

#include "Particle.h"


struct Renderer
{
    Renderer();

    sf::RenderWindow window;
    sf::RenderWindow* get_window() { return &window; } 

    void draw_constraints(const std::vector<Particle*>& particles) ;
};