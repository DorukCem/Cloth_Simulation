#include "Particle.h"
#include <iostream>

Particle::Particle(float x, float y)
{
	position = sf::Vector2f(x, y);
	prev_position = position;
	forces = {0.0f , 0.0f};
}

void Particle::update(float dt)
{
	if (is_pinned) {return;}

	prev_position = position;
	velocity += (forces / mass) * dt;
	position += velocity * dt;
	
}

void Particle::update_velocity(float dt)
{
	velocity = (position - prev_position) / dt;
	forces = { 0.0f , 0.0f };
}

