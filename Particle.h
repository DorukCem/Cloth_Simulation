#pragma once
#include "Constraint.h"

class Particle
{
public:
	
	float drag = 0.01f;
	float elasticity = 10.0f;
	float mass = 2.0f;

	bool is_pinned = false;

	sf::Vector2f position;
	sf::Vector2f prev_position;
	sf::Vector2f forces;
	sf::Vector2f velocity;

	// Constraints that are referencing this particle
	std::vector<Constraint*> constraints;

	Particle(float x, float y);

// Inline functions
	const sf::Vector2f& get_position() const { return position; }
	void add_force(sf::Vector2f force) { forces += force; }
	void move(sf::Vector2f move_ammount) { if (not is_pinned) position += move_ammount; }

// Functions
	void add_constraint(Constraint* c);
	void update(float dt);
	void update_velocity(float dt);
	
	void break_constraints();
};
