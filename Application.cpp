#include "Application.h"
#include <iostream>

Application::Application() : cloth(40, 30, 25 , 500, 50) {} // (node ammount width, node ammount height, spacing, start x, start y)

void Application::update()
{
    // Dragging
    if (mouse.get_left_button_down())
    {
        const sf::Vector2f mouse_speed = mouse.get_position() - mouse.get_prev_position();
        cloth.apply_force_on_cloth(mouse.get_position(), 100.0f, mouse_speed * 8000.0f);
    }

    // Tearing
    if (mouse.get_right_button_down())
    {
        cloth.tear_cloh(mouse.get_position(), 10.0f);
    }

    cloth.update(1.0f / 60.0f);

}

void Application::input()
{
    sf::Event event;
    sf::Window* window = renderer.get_window();
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            running = false;
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window->close();
                running = false;
            }
            break;

        case sf::Event::MouseMoved:

            mouse.update_position({ static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) });
            break;

        case sf::Event::MouseButtonPressed:

            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mouse.set_left_button(true);
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                mouse.set_right_button(true);
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mouse.set_left_button(false);
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                mouse.set_right_button(false);
            }
            break;

        default:
            break;
        }
    }
}

void Application::draw()
{
    renderer.window.clear();

    renderer.draw_constraints(cloth.get_particles());

    renderer.window.display();
    
}