#pragma once

#include "SFML/Graphics.hpp"

class Particle;
class Constraint
{
public:

	Particle &p1;
	Particle &p2;
	
	float initial_length;
	float strength = 1.0f;
	float max_elongation_ratio = 1.5f;
	bool broken = false;


	Constraint(Particle& p1, Particle& p2);

	bool is_valid();

	float find_current_length() const;
	
	void solve();
};