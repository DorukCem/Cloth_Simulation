#include "Renderer.h"
#include <iostream>

Renderer::Renderer() : window(sf::VideoMode(1920, 1080), "Cloth") {window.setFramerateLimit(60);}


void Renderer::draw_constraints(const std::vector<Particle*>& particles) 
{
    for (Particle* p : particles)
    {
        for (Constraint* c : p->constraints)
        {
            if (c->broken) { continue; }

            sf::VertexArray line(sf::Lines, 2);
            line[0].position = c->p1.position;
            line[1].position = c->p2.position;

            window.draw(line);
        }
    }
    

}