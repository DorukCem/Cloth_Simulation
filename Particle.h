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

	bool alive = true;
	std::vector<Constraint*> constraints;
// Functions

	Particle(float x, float y);

	
	void add_constraint(Constraint* c) ;
	
	void update(float dt);
	void update_velocity(float dt);

	void add_force(sf::Vector2f force) { forces += force;}
	void move(sf::Vector2f move_ammount) { if (not is_pinned) position += move_ammount; }
	const sf::Vector2f& get_position() const { return position; }

	void break_particle();
};
