#include "Game.h"

Game::Game(int entityCount, float entitySpeed)
	: applicationWindow("Game Window", sf::Vector2u(800, 600)),
	isPaused(false) {
	// 创建 Entity 实例
	for (int i = 0; i < entityCount; i++)
	{
		entities.push_back(new Entity("mushroom50-50.png", &applicationWindow, entitySpeed));
	}
}


Game::~Game()
{ 
	//delete mushroom;
	for (Entity* entity : entities) {
		delete entity; // 释放每个 entity
	}
	entities.clear(); // 清空 vector
}


void Game::userInput()
{
	/*暂停*/
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

	/*实体更新 + 窗口更新*/
	for (Entity* entity : entities)
	{
		entity->update();//move()改名为updat()以符合 Game Loop 设计模式
	}
	applicationWindow.update();
}


void Game::render()
{
	applicationWindow.beginDraw();
	//applicationWindow.draw(mushroomSprite);  // 绘制蘑菇
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
