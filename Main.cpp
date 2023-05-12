#include <iostream>
#include "Particle.h"
#include <vector>
#include "Renderer.h"
#include "Mouse.h"
#include "Application.h"


int main() {
	
	Application app;

	while (app.is_running())
	{
		app.input();
		app.update();
		app.draw();
	}

return 0;
}