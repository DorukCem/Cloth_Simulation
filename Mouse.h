#pragma once
#include "SFML/Graphics.hpp"

struct Mouse
{
	sf::Vector2f position;
	sf::Vector2f prev_position;

	Mouse() :position({ 0.0f,0.0f }), prev_position({ 0.0f,0.0f }) {}

	bool left_button_down = false;
	bool right_button_down = false;

	void update_position(sf::Vector2f pos) { prev_position = position; position = pos; }

	const sf::Vector2f& get_position() const { return position; }
	const sf::Vector2f& get_prev_position() const { return prev_position; }

	bool get_left_button_down() const { return left_button_down; }
	void set_left_button(bool state) { left_button_down = state; }
	bool get_right_button_down() const { return right_button_down; }
	void set_right_button(bool state) { right_button_down = state; }

};
