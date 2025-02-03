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

	Window* getWindow(); // ���ش��ڵ�ָ��

	sf::Vector2f getEntityPosition(int index) const;

	sf::Time getElapsedTime() const; // ���ʱ���



private:
	void updateMushroomMovement();

	Window applicationWindow;
	//sf::Vector2f mushroomMovement;
	//sf::Texture mushroomTexture;
	//sf::Sprite mushroomSprite;
	//Entity* mushroom;
	std::vector<Entity*> entities; // �洢��� Entity ָ��

	bool isPaused; // �Ƿ���ͣ��Ϸ

	sf::Clock gameClock; // ��ʱ��
};

