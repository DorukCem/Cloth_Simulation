#pragma once

#include "Particle.h"


struct Renderer
{
    sf::RenderWindow window;

    Renderer();

    sf::RenderWindow* get_window() { return &window; } 

    void draw_constraints(const std::vector<Constraint*>& constraints) ;
    void draw_particles(const std::vector<Particle*>& particles) ;
};