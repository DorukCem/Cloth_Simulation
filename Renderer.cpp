#include "Renderer.h"

Renderer::Renderer() : window(sf::VideoMode(800, 800), "Cloth") {}

void Renderer::draw_constraints(const std::vector<Constraint*>& constraints) 
{
    for (Constraint* c : constraints)
    {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = c->p1.position;
        line[1].position = c->p2.position;

        window.draw(line);
    }
}

void Renderer::draw_particles(const std::vector<Particle*>& particles) 
{
    for (Particle* p : particles)
    {
        sf::CircleShape circle(10.0f);
        circle.setOrigin(circle.getRadius(), circle.getRadius());
        circle.setPosition(p->position);
        window.draw(circle);
    }
}