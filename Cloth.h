#pragma once

#include <vector>
#include "Particle.h"
#include "Constraint.h"

class Cloth {
public:
    
    uint32_t solver_iterations;
    uint32_t sub_steps;

    sf::Vector2f gravity;
    float friction_coef = 0.5f;

    std::vector<Particle*> m_particles;
    std::vector<Constraint*> m_constraints;


    Cloth(int width, int height, int spacing, int start_x, int start_y);
    
    const std::vector<Constraint*>& get_constraints() const {
        return m_constraints;
    }

    const std::vector<Particle*>& get_particles() const {
        return m_particles;
    }
    
    void update(float dt);

private:
    void apply_gravity();
    void apply_air_friction();
    void update_positions(float dt);
    void update_derivatives(float dt);
    void solve_constraints();

};