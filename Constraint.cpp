#include "Constraint.h"
#include "Particle.h"
#include <iostream>
#include <math.h>

Constraint::Constraint(Particle& p1, Particle& p2)
	:p1(p1), p2(p2)
{
	
	if (p1.constraints[0] == nullptr)
	{
		p1.add_constraint(this, 0);
	}
	else
	{
		p1.add_constraint(this, 1);
	}

	if (p2.constraints[0] == nullptr)
	{
		p2.add_constraint(this, 0);
	}
	else
	{
		p2.add_constraint(this, 1);
	}
	

	initial_length = find_current_length();
}

float Constraint::find_current_length() const
{
	sf::Vector2f diff = p1.get_position() - p2.get_position();

	return sqrtf(diff.x * diff.x + diff.y * diff.y);
}

void Constraint::update()
{
	if (not is_active) { return ;}

	float current_length = find_current_length();
	float diff_factor = (initial_length - current_length) / current_length;
	sf::Vector2f offset = ( p1.get_position() - p2.get_position() ) * diff_factor * 0.5f;

	p1.position += offset;
	p2.position -= offset;

}