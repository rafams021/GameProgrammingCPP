#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class myWindow {
private:
	int windowW;
	int windowH;
public:
	myWindow(const int width, const int height) {
		windowW = width;
		windowH = height;
	}

	const int getWindowWidth() {
		return windowW;
	}

	const int getWindowHeight() {
		return windowH;
	}

	~myWindow() { }
};

class myFont {
private:
	std::string fontFile;
	int size;
	int cRed;
	int cGreen;
	int cBlue;

public:
	myFont(std::string &fileRoot, const int sizeFont, const int colorRed, const int colorGreen, const int colorBlue) {
		fontFile = fileRoot;
		size = sizeFont;
		cRed = colorRed;
		cGreen = colorGreen;
		cBlue = colorBlue;
	}

	const std::string getfileRoot() {
		return fontFile;
	}

	const int getFontsize() {
		return size;
	}

	const std::vector<int> getColor() {
		std::vector<int> vecColor{ cRed, cGreen, cBlue };
		return vecColor;
	}

	~myFont() { }
};

class myCircInfo {
private:
	std::string name_shape;
	int cRed;
	int cGreen;
	int cBlue;
	float speedX = 0.0;
	float speedY = 0.0;
	float positionX = 0.0;
	float positionY = 0.0;
	float radiusMyshape = 0.0;
public:
	myCircInfo(std::string &name, const float pX, const float pY, const float sX, const float sY, const int colorR, const int colorG, const int ColorB, const int rad) {
		name_shape = name;
		positionX = pX;
		positionY = pY;
		speedX = sX;
		speedY = sY;
		cRed = colorR;
		cGreen = colorG;
		cBlue = ColorB;
		radiusMyshape = rad;
	}

	const std::string getNameShape() {
		return name_shape;
	}

	const std::vector<float> getInitialPosition() {
		std::vector<float> positionX_Y{ positionX, positionY };
		return positionX_Y;
	}

	const std::vector<float> getInitialSpeed() {
		std::vector<float> speedX_Y{ speedX, speedY };
		return speedX_Y;
	}

	const std::vector<int> getColor() {
		std::vector<int> vecColor{ cRed, cGreen, cBlue };
		return vecColor;
	}

	const float getRadius() {
		return radiusMyshape;
	}

	~myCircInfo() { }
};

class myRectInfo {
private:
	std::string name_shape;
	int cRed;
	int cGreen;
	int cBlue;
	float speedX = 0.0;
	float speedY = 0.0;
	float positionX = 0.0;
	float positionY = 0.0;
	float widthMyShape = 0.0;
	float heightMyShape = 0.0;
public:
	myRectInfo(const std::string name, const float pX, const float pY, const float sX, const float sY, const int colorR, const int colorG, const int ColorB, const float width, const float height) {
		name_shape = name;
		positionX = pX;
		positionY = pY;
		speedX = sX;
		speedY = sY;
		cRed = colorR;
		cGreen = colorG;
		cBlue = ColorB;
		widthMyShape = width;
		heightMyShape = height;
	}

	const std::string getNameShape() {
		return name_shape;
	}

	const std::vector<float> getInitialPosition() {
		std::vector<float> positionX_Y{ positionX, positionY };
		return positionX_Y;
	}

	const std::vector<float> getInitialSpeed() {
		std::vector<float> speedX_Y{ speedX, speedY };
		return speedX_Y;
	}

	const std::vector<int> getColor() {
		std::vector<int> vecColor{ cRed, cGreen, cBlue };
		return vecColor;
	}

	const std::vector<float> getwidthHeight() {
		std::vector<float> vecWidthHeight{ widthMyShape, heightMyShape };
		return vecWidthHeight;
	}

	~myRectInfo() { }

};

class Constrction {
private:
	std::vector<myWindow> my_Window;
	std::vector<myFont> my_font;
	std::vector<myCircInfo> my_circ_shape;
	std::vector<myRectInfo> my_rect_shape;
public:
	Constrction() {}

	void addWindow(myWindow window) {
		my_Window.push_back(window);
	}

	std::vector<myWindow> getWindow() {
		return my_Window;
	}

	void addFont(myFont font) {
		my_font.push_back(font);
	}

	std::vector<myFont> getFont() {
		return my_font;
	}

	void addCircle(myCircInfo circ) {
		my_circ_shape.push_back(circ);
	}

	std::vector<myCircInfo> getCircShape() {
		return my_circ_shape;
	}
	void addRect(myRectInfo rect) {
		my_rect_shape.push_back(rect);
	}

	std::vector<myRectInfo> getRectShape() {
		return my_rect_shape;
	}

	void loadFromFileTxT(const std::string& filename) {
		std::ifstream fileIn(filename);
		std::string firstS;
		std::string fontFileRoot;
		std::string nameShape;
		float speedInX;
		float speedInY;
		float positionInX;
		float positionInY;
		float widthOfShape;
		float heightOfShape;
		float radiusOfShape;
		int windowWidth;
		int windowHeight;
		int fontSize;
		int colorRed;
		int colorGreen;
		int colorBlue;

		while (fileIn >> firstS) {
			if (firstS == "Window") {
				fileIn >> windowWidth >> windowHeight;
				addWindow(myWindow(windowWidth, windowHeight));
			}
			else if (firstS == "Font") {
				fileIn >> fontFileRoot >> fontSize >> colorRed >> colorGreen >> colorBlue;
				addFont(myFont(fontFileRoot, fontSize, colorRed, colorGreen, colorBlue));
			}
			else if (firstS == "Circle") {
				fileIn >> nameShape >> positionInX >> positionInY >> speedInX >> speedInY >> colorRed >> colorGreen >> colorBlue >> radiusOfShape;
				addCircle(myCircInfo(nameShape, positionInX, positionInY, speedInX, speedInY, colorRed, colorGreen, colorBlue, radiusOfShape));
			}
			else if (firstS == "Rectangle") {
				fileIn >> nameShape >> positionInX >> positionInY >> speedInX >> speedInY >> colorRed >> colorGreen >> colorBlue >> widthOfShape >> heightOfShape;
				addRect(myRectInfo(nameShape, positionInX, positionInY, speedInX, speedInY, colorRed, colorGreen, colorBlue, widthOfShape, heightOfShape));
			}
		}
	}
};

struct Rectangles {
	sf::RectangleShape rectangle;
	float speedX;
	float speedY;
};

struct Circles {
	sf::CircleShape circle;
	float speedX;
	float speedY;
};
 
int main(int argc, char* argv[]) {

	Constrction myCons;
	myCons.loadFromFileTxT("libs/config.txt");

	// Create a new window of size w*h pixels.
	// top-left of the window is (0,0) and bottom-right is (w,h).
	const int wWidth = myCons.getWindow()[0].getWindowWidth();
	const int wHeight = myCons.getWindow()[0].getWindowHeight();
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
	sf::FloatRect windowBounds({ 0.f, 0.f }, window.getDefaultView().getSize());

	// Let's make circles shapes that we will draw to the screen.
	std::vector<Circles> circles;
	for (auto& value : myCons.getCircShape()) {
		sf::CircleShape circle(value.getRadius()); // Create a circle shape with radius X.
		circle.setFillColor(sf::Color(value.getColor()[0], value.getColor()[1], value.getColor()[2])); // Set the circle color.
		circle.setPosition(value.getInitialPosition()[0], value.getInitialPosition()[1]); // Set top-left position of the circle.
		struct Circles circ = { circle, value.getInitialSpeed()[0], value.getInitialSpeed()[1] };
		circles.push_back(circ);
	}

	// Let's make rectangle shapes that we will draw to the screen.
	std::vector<Rectangles> rectangles;
	for (auto& value : myCons.getRectShape()) {
		sf::Vector2f rSize(value.getwidthHeight()[0], value.getwidthHeight()[1]);
		sf::RectangleShape rectangle(rSize);
		rectangle.setFillColor(sf::Color(value.getColor()[0], value.getColor()[1], value.getColor()[2])); // Create a rectangle shape with radius X.
		rectangle.setPosition(value.getInitialPosition()[0], value.getInitialPosition()[1]); // Set the rectangle color.
		struct Rectangles rect = { rectangle, value.getInitialSpeed()[0], value.getInitialSpeed()[1] }; // Set top-left position of the rectangle.
		rectangles.push_back(rect);
	}

	// Let's load a font so we can display some text.
	sf::Font myFont;

	// Attempt to load the foant from file.
	if (!myFont.loadFromFile(myCons.getFont()[0].getfileRoot())) {
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
					//circleMoveSpeed *= -1.0f;
				}
			}
		}
		
		// Basic rendering fuctions calls.
		window.clear();
		for (auto& circle : circles) {
			sf::FloatRect circleBounds = circle.circle.getGlobalBounds();
			float* circMoveX = &circle.speedX;
			float* circMoveY = &circle.speedY;

			// Left
			if (circleBounds.left <= 0.f) {
				*circMoveX *= -1.0f;
			}
			// Top
			if (circleBounds.top <= 0.f) {
				*circMoveY *= -1.0f;
			}
			// Right
			if (circleBounds.left + circleBounds.width >= windowBounds.width) {
				*circMoveX *= -1.0f;
			}
			// Bottom
			if (circleBounds.top + circleBounds.height >= windowBounds.height) {
				*circMoveY *= -1.0f;
			}

			circle.circle.setPosition(circle.circle.getPosition().x - *circMoveX, circle.circle.getPosition().y - *circMoveY); // Basic animation - move the each frame if it's still in the frame.
			window.draw(circle.circle);
		}
		for (auto& rectangle : rectangles) {
			sf::FloatRect rentangleBounds = rectangle.rectangle.getGlobalBounds();
			float *rectMoveX =  &rectangle.speedX;
			float *rectMoveY =  &rectangle.speedY;

			// Left
			if (rentangleBounds.left <= 0.f) {
				*rectMoveX *= -1.0f;
			}
			// Top
			if (rentangleBounds.top <= 0.f) {
				*rectMoveY *= -1.0f;
			}
			// Right
			if (rentangleBounds.left + rentangleBounds.width >= windowBounds.width) {
				*rectMoveX *= -1.0f;
			}
			// Bottom
			if (rentangleBounds.top + rentangleBounds.height >= windowBounds.height) {
				*rectMoveY *= -1.0f;
			}

			rectangle.rectangle.setPosition(rentangleBounds.left - *rectMoveX, rentangleBounds.top - *rectMoveY); // Basic animation - move the each frame if it's still in the frame.
			window.draw(rectangle.rectangle);
		}
		window.draw(text);
		window.display();
	}

	return 0;
}