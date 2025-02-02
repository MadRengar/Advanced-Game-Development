#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>

class Window
{
public:
	Window();

	Window(const std::string& title, const sf::Vector2u& size);

	~Window();

	void setup(const std::string& title, const sf::Vector2u& size);

	void beginDraw();

	void endDraw();

	void update();

	void toggleFullscreen();

	void draw(sf::Drawable& drawable);

	void redraw();

	bool isWindowDone() const { return isDone; }
	bool isWindowFullscreen() const { return isFullscreen; }
	inline void setSize(const sf::Vector2u& size) { windowSize = size; }
	const sf::Vector2u& getWindowSize() const { return windowSize; }
	inline void setTitle(const std::string& t) { windowTitle = t; }
	const std::string& getTitle() const { return windowTitle; }

private:
	void destroy();

	void create();

	sf::RenderWindow window;

	sf::Vector2u windowSize;

	std::string windowTitle;

	bool isDone;

	bool isFullscreen;
};

