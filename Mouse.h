#pragma once
#include "SFML/Graphics.hpp"

struct Mouse
{
	sf::Vector2i position;
	sf::Vector2i prev_position;

	Mouse() :position({ 0,0 }), prev_position({ 0,0 }) {}

	float cursor_size = 20;

	bool left_button_down = false;
	bool right_button_down = false;

	void update_position(sf::Vector2i pos) { prev_position = position; position = pos; }

	const sf::Vector2i& get_position() const { return position; }
	const sf::Vector2i& get_prev_position() const { return prev_position; }

	bool get_left_button_down() const { return left_button_down; }
	void set_left_button(bool state) { left_button_down = state; }
	bool get_right_button_down() const { return right_button_down; }
	void set_right_button(bool state) { right_button_down = state; }

};
