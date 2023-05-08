#include "Cloth.h"

Cloth::Cloth(int width, int height, int spacing, int start_x, int start_y)
    : gravity(0.0f, 981.0f), drag(0.01f), elasticity(10.0f)
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

            // this can change
            if (y == 0)
            {
                point->is_pinned = true;
            }

            m_particles.push_back(point);
        }
    }
}

const std::vector<Constraint*>& Cloth::get_constraints() const {
    return m_constraints;
}

const std::vector<Particle*>& Cloth::get_particles() const {
    return m_particles;
}

void Cloth::update(float dt) {
    for (Particle* p : m_particles)
    {
        p->accelerate(gravity);
        p->update(dt);
    }
    for (Constraint* c : m_constraints)
    {
        c->update();
    }
}