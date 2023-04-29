#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>


struct Particle {
    // Data Members
    sf::Vector2f position;
    sf::Vector2f prev_position;
    float mass;

    // Constructor
    Particle(sf::Vector2f position, float mass) 
    : position(position), mass(mass), prev_position(position)
    {}

    // class methods
    void update(float delta_time);
    void stay();
};

void Particle::update(float delta_time)
{
    sf::Vector2f force(0.0f, 0.5f);
    sf::Vector2f acceleration(force.x / mass, force.y / mass);
    sf::Vector2f prev = position;

    position = position * 2.0f - prev_position + acceleration * (delta_time * delta_time);
    
    prev_position = prev;

    stay();
}

void Particle::stay()
{
    int height = 900;
    int width = 1600;
    if (position.y >= height) position.y = height;
    if (position.x >= width) position.x = width;
    if (position.y < 0) position.y = 0;
    if (position.x < 0) position.x = 0;
}


struct Constraint
{
    Particle *p1;
    Particle *p2;
    float length;
    
    
    Constraint(Particle *p1, Particle *p2, float length)
    :p1(p1), p2(p2), length(length)
    {}


};

float dist_points(Particle p1, Particle p2)
{
    sf::Vector2f vec = p2.position - p1.position;
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    sf::Clock clock;
    
    std::vector<Particle*> particles;
    Particle pa(sf::Vector2f{220, 20}, 10000.0f), pb(sf::Vector2f{220, 60}, 10000.0f);
    particles.push_back(&pa);
    particles.push_back(&pb);
    
    std::vector<Constraint*> constraints;
    Constraint AB(&pa, &pb, dist_points(pa, pb));
    constraints.push_back(&AB);
    
 
    float dt = 1.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear(sf::Color::Black);

        for (auto &p: particles)
        {
            p->update(dt);
            sf::CircleShape circle(10.0f);
            circle.setOrigin(circle.getRadius(), circle.getRadius());
            circle.setPosition(p->position);
            window.draw(circle);
        }


        for (auto &c: constraints)
        {
            float dif = dist_points(*c->p1, *c->p2);
            sf::Vector2f vec = c->p1->position - c->p2->position;
            float dif_factor = (c->length - dif) / dif * 0.5;
            sf::Vector2f offset = {vec.x * dif_factor, vec.y * dif_factor};

            std::cout << c->p1->position.y << std::endl;
            c->p1->position.x += offset.x;
            c->p1->position.y += offset.y;
            c->p2->position.x -= offset.x;
            c->p2->position.y -= offset.y;
        }

        window.display();
        
    }

    return 0;
}

//make
//.\main