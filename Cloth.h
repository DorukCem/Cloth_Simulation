#pragma once

#include <vector>
#include "Particle.h"
#include "Constraint.h"

class Cloth {
public:
    Cloth(int width, int height, int spacing, int start_x, int start_y);

    const std::vector<Constraint*>& get_constraints() const;
    const std::vector<Particle*>& get_particles() const;

    void update(float dt);

private:
    sf::Vector2f gravity;
    float drag;
    float elasticity;
    std::vector<Particle*> m_particles;
    std::vector<Constraint*> m_constraints;
};