#include "Cloth.h"
#include <iostream>

Cloth::Cloth(int width, int height, int spacing, int start_x, int start_y)
    : solver_iterations(1), sub_steps(16), gravity(0.0f, 1500.000f), friction_coef(0.5f)
{
    for (int y = 0; y <= height; y++)
    {
        for (int x = 0; x <= width; x++)
        {
            Particle* point = new Particle(start_x + x * spacing, start_y + y * spacing);

            if (x != 0)
            {
                Particle* left_point = m_particles[m_particles.size() - 1];
                Constraint* c = new Constraint(*point, *left_point);
                m_constraints.push_back(c);
            }

            if (y != 0)
            {
                Particle* up_point = m_particles[x + (y - 1) * (width + 1)];
                Constraint* c = new Constraint(*point, *up_point);
                m_constraints.push_back(c);
            }

            if (y == 0 and x%10 == 0)
            {
                point->is_pinned = true;
            }

            m_particles.push_back(point);
        }
    }
}


void Cloth::update(float dt) {
    const float sub_step_dt = dt / static_cast<float>(sub_steps);
    for (uint32_t i = sub_steps; i>0; i--)
    { 
        apply_gravity();
        apply_air_friction();  
        update_positions(sub_step_dt); 
        solve_constraints();  
        update_derivatives(sub_step_dt);
    }
}


void Cloth::apply_gravity() {
    for (Particle* p : m_particles)
    {
        p->add_force( gravity * p->mass );
    }
}

void Cloth::apply_air_friction() {
    for (Particle* p : m_particles)
    {
        p->add_force( -p->velocity * friction_coef);
    }
}

void Cloth::update_positions(float dt) {
    for (Particle* p : m_particles)
    {
        p->update(dt);
    }
}

void Cloth::update_derivatives(float dt) {
    for (Particle* p : m_particles)
    {
        p->update_velocity(dt);
    }
}

void Cloth::solve_constraints() {
    for (uint32_t i(solver_iterations); i>0 ; i--)
    {
        for (Constraint* c : m_constraints)
        {
            c->solve();
        }
    }
}

// User applied force 

void Cloth::apply_force_on_cloth(sf::Vector2f position, float radius, sf::Vector2f force)
{
    for (Particle* p : m_particles)
    {
        if (is_in_radius(p, position, radius))
        {
            p->add_force(force);
        }
    }
}


// User tears cloth

void Cloth::tear_cloh(sf::Vector2f position, float radius)
{   
    for (Particle* p : m_particles)
    {
        if (is_in_radius(p, position, radius))
        {
            p->break_constraints();
        }
    }

}

