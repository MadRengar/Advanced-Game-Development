#pragma once
#include "Window.h"
#include "Vector2.h"
#include "Entity.h"

class Game
{
public:
	Game(int entityCount, float entitySpeed = 0.1f);

	~Game();

	void userInput();

	void update();

	void render();

	Window* getWindow(); // 返回窗口的指针

	sf::Vector2f getEntityPosition(int index) const;

	sf::Time getElapsedTime() const; // 获得时间戳



private:
	void updateMushroomMovement();

	Window applicationWindow;
	//sf::Vector2f mushroomMovement;
	//sf::Texture mushroomTexture;
	//sf::Sprite mushroomSprite;
	//Entity* mushroom;
	std::vector<Entity*> entities; // 存储多个 Entity 指针

	bool isPaused; // 是否暂停游戏

	sf::Clock gameClock; // 计时器
};

