#include "Particle.h"

Particle::Particle(float x, float y)
{
	position = sf::Vector2f(x, y);
	prev_position = position;
	acceleration = {0,0};
}

void Particle::update(float dt)
{

	if (is_pinned)
	{
		return;
	}

	const sf::Vector2f velocity = position - prev_position;
	prev_position = position;
	position = position + velocity + acceleration * dt * dt;

	
	keep_in_bounds();

	acceleration = {0.0f , 0.0f};
}

void Particle::keep_in_bounds()
{
	//Change implementation
	float height = 800.0f;
	float width = 800.0f;
	if (position.y >= height) position.y = height;
	if (position.x >= width) position.x = width;
	if (position.y < 0) position.y = 0;
	if (position.x < 0) position.x = 0;

}