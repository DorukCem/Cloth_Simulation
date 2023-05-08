#pragma once

#include "SFML/Graphics.hpp"

class Particle;
class Constraint
{
public:

	Particle &p1;
	Particle &p2;
	float initial_length;
	bool is_active = true;
	
	Constraint(Particle& p1, Particle& p2);

	float find_current_length() const;
	
	void update();
};