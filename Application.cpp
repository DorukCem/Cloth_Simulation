#include "Application.h"

Application::Application() : cloth(34, 34, 20, 100, 100) {}

void Application::update()
{
    float time_elapsed = clock.restart().asSeconds();
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

            mouse.update_position({ event.mouseMove.x, event.mouseMove.y });
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

    renderer.draw_constraints(cloth.get_constraints());
    //renderer.draw_particles(cloth.get_particles());

    renderer.window.display();
    
}