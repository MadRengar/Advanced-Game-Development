#include "Game.h"

Game::Game(int entityCount, float entitySpeed)
	: applicationWindow("Game Window", sf::Vector2u(800, 600)),
	isPaused(false) {
	// ���� Entity ʵ��
	for (int i = 0; i < entityCount; i++)
	{
		entities.push_back(new Entity("mushroom50-50.png", &applicationWindow, entitySpeed));
	}
}


Game::~Game()
{ 
	//delete mushroom;
	for (Entity* entity : entities) {
		delete entity; // �ͷ�ÿ�� entity
	}
	entities.clear(); // ��� vector
}


void Game::userInput()
{
	/*��ͣ*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isPaused = !isPaused;
	}
}

void Game::update()
{
	if (isPaused)
	{
		return;
	}
	//updateMushroomMovement();
	//mushroom->move();

	/*ʵ����� + ���ڸ���*/
	for (Entity* entity : entities)
	{
		entity->update();//move()����Ϊupdat()�Է��� Game Loop ���ģʽ
	}
	applicationWindow.update();
}


void Game::render()
{
	applicationWindow.beginDraw();
	//applicationWindow.draw(mushroomSprite);  // ����Ģ��
	for (Entity* entity : entities) {
		entity->draw(applicationWindow);
	}
	applicationWindow.endDraw();
}

Window* Game::getWindow()
{
	return &applicationWindow;
}

//void Game::updateMushroomMovement()
//{
//	sf::Vector2f position = getMushroomPosition();
//	sf::Vector2u windowSize = applicationWindow.getWindowSize();
//	sf::Vector2u textureSize = mushroomTexture.getSize();
//	float xRightLimit = static_cast<float>(windowSize.x - textureSize.x);
//	float yBottomLimit = static_cast<float>(windowSize.y - textureSize.y);
//	bool bouncesRight = (position.x > xRightLimit && mushroomMovement.x > 0);
//	bool bouncesLeft = (position.x < 0 && mushroomMovement.x < 0);
//	if (bouncesRight || bouncesLeft)
//	{
//		mushroomMovement.x = -mushroomMovement.x;
//	}
//	
//	bool bouncesBottom = (position.y > yBottomLimit && mushroomMovement.y > 0);
//	bool bouncesTop = (position.y < 0 && mushroomMovement.y < 0);
//	if (bouncesBottom || bouncesTop)
//	{
//		mushroomMovement.y = -mushroomMovement.y;
//	}
//	mushroomSprite.move(mushroomMovement.x, mushroomMovement.y);
//
//}

sf::Time Game::getElapsedTime() const {
	return gameClock.getElapsedTime();
}


sf::Vector2f Game::getEntityPosition(int index) const {
	if (index < 0 || index >= static_cast<int>(entities.size())) {
		throw std::runtime_error("Invalid entity index: " + std::to_string(index));
	}
	return entities[index]->getPosition();
}
