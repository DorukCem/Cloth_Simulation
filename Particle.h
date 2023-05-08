#pragma once
#include "Constraint.h"

class Particle
{
public:
	sf::Vector2f position;
	sf::Vector2f prev_position;
	sf::Vector2f acceleration;

	bool is_pinned = false;

	Particle(float x, float y);

	Constraint* constraints[2] = { nullptr };
	void add_constraint(Constraint* c, int index) { constraints[index] = c; }
	
	const sf::Vector2f& get_position() const { return position; }

	void update(float dt);
	void accelerate(sf::Vector2f acc) { acceleration += acc;}
	void keep_in_bounds();
	
};
