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
    void apply_force_on_cloth(sf::Vector2f position, float radius, sf::Vector2f force);
    void tear_cloh(sf::Vector2f position, float radius);

private:
    void apply_gravity();
    void apply_air_friction();
    void update_positions(float dt);
    void update_derivatives(float dt);
    void solve_constraints();
    void remove_broken_links();

    bool is_in_radius(const Particle* p, sf::Vector2f center, float radius) {
        const sf::Vector2f v = center - p->get_position();
        return (v.x * v.x + v.y * v.y) < radius * radius;
    }

   
};