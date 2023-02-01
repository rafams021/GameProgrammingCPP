#include <iostream>
#include <SFML/Graphics.hpp>
 
int main(int argc, char* argv[]) {
	// Create a new window of size w*h pixels.
	// top-left of the window is (0,0) and bottom-right is (w,h).
	const int wWidth = 1280;
	const int wHeight = 720;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");

	// Let's make a shape that we will draw to the screen.
	sf::CircleShape circle(50); // Create a circle shape with radius 50.
	circle.setFillColor(sf::Color::Green); // Set the circle color to green.
	circle.setPosition(300.0f, 300.0f); // Set top-left position of the circle.
	float circleMoveSpeed = 0.01f; // We will use this to move the circle later.

	// Let's load a font so we can display some text.
	sf::Font myFont;

	// Attempt to load the foant from file.
	if (!myFont.loadFromFile("libs/fonts/tech.ttf")) {
		std::cerr << "Could not load font!" << std::endl;
		exit(-1);
	}

	// Set up the next object that will be drawn to the screen.
	sf::Text text("Sample Text", myFont, 24);

	// Position the top-left corner of the text so that the text aligns on the bottom.
	// Text character size is in pixels, so move the text up from the bottom by its height.
	text.setPosition(0, wHeight - (float)text.getCharacterSize());

	// Main loop - continues for each frame while window is open
	while (window.isOpen()) {
		// Event handling
		sf::Event event;
		while (window.pollEvent(event)) {
			// This event triggers when the window is closed
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// This event is triggered when a key is pressed.
			if (event.type == sf::Event::KeyPressed) {
				// Print the key that was pressed to the console.
				std::cout << "Key pressed with code = " << event.key.code << std::endl;

				if (event.key.code == sf::Keyboard::X) {
					// Reverse the direction of the circle on the screen.
					circleMoveSpeed *= -1.0f;
				}
			}
		}

		// Basic animation - move the each frame if it's still in the frame.
		circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);

		// Basic rendering fuctions calls.
		window.clear();
		window.draw(circle);
		window.draw(text);
		window.display();
	}

	return 0;
}