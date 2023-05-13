#include "Constraint.h"
#include "Particle.h"
#include <iostream>
#include <math.h>

Constraint::Constraint(Particle& p1, Particle& p2)
	:p1(p1), p2(p2)
{
	// p1 and and p2 will hold pointers to this constraint

	p1.add_constraint(this);
	p2.add_constraint(this);

	initial_length = find_current_length() ;
}


float Constraint::find_current_length() const
{
	sf::Vector2f diff = p1.get_position() - p2.get_position();

	return sqrtf(diff.x * diff.x + diff.y * diff.y);
}


void Constraint::solve()
{
	if (broken) {  return ;}

	float current_length = find_current_length();
	if (current_length > initial_length)
	{
		if (current_length > initial_length * max_elongation_ratio)
		{
			broken = true;
		}
		
		const sf::Vector2f diff = (p1.get_position() - p2.get_position()) / current_length;
		const float offset = initial_length - current_length ;
		const sf::Vector2f p = -(offset * strength) / (p1.mass + p2.mass) * diff;

		p1.move(-p / p1.mass);
		p2.move( p / p2.mass);
	}

}