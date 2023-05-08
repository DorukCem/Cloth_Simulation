#pragma once

#include "Renderer.h"
#include "Mouse.h"
#include "Cloth.h"

struct Application {
    Renderer renderer;
    Mouse mouse;
    Cloth cloth;
    sf::Clock clock;

    bool running = true;
    bool is_running() {return running;}

    Application();

    void update();
    void input();
    void draw();
};