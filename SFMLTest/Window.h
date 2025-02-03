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

	// 获得-FPS文字对象
	sf::Text& getGUIText();
	// 测试提交

	// 标志-窗口关闭
	bool isWindowDone() const { return isDone; }
	// 标志-窗口全屏
	bool isWindowFullscreen() const { return isFullscreen; }
	// 设置-窗口大小
	inline void setSize(const sf::Vector2u& size) { windowSize = size; }
	// 获得-窗口大小
	const sf::Vector2u& getWindowSize() const { return windowSize; }
	// 设置-窗口名称
	inline void setTitle(const std::string& t) { windowTitle = t; }
	// 获得-窗口名称
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

