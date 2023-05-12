#include "Particle.h"
#include <iostream>

Particle::Particle(float x, float y)
{
	position = sf::Vector2f(x, y);
	prev_position = position;
	forces = {0.0f , 0.0f};
}


// Verlet integration 
void Particle::update(float dt)
{
	if (is_pinned) {return;}

	prev_position = position;
	velocity += (forces / mass) * dt;
	position += velocity * dt;
	
}

// Verlet integration
void Particle::update_velocity(float dt)
{
	velocity = (position - prev_position) / dt;
	forces = { 0.0f , 0.0f };
}


void Particle::break_constraints()
{
	for (Constraint* c : constraints)
	{
		c->broken = true;
	}
}

void Particle::add_constraint(Constraint* c)
{
	constraints.push_back(c);
}