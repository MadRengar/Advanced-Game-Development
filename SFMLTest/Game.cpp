#include "Game.h"

// CONSTRUCTOR AND DESTRUCTOR

// 1. The default constructor must initialize the window with a string (window title) and an sf::Vector2u(800,600) for its size
//    Also the movement vector for the mushroom should be initalized to x=4.0f, y=4.0f.
//    Both the vector and the window must be set with a "member initializers list" (https://en.cppreference.com/w/cpp/language/constructor)
//    The body of the constructor must:
//      * Load the texture file (mushroom50-50.png) into the sf::Texture member variable using the loadFromFile function of the sf::Texture class.
//      * Set the sf::Texture variable as the texture of the sf::Sprite member (using the sf::Sprite::setTexture(sf::Texture) function).
Game::Game()
	: applicationWindow("Game Window", sf::Vector2u(800, 600)), // 初始化窗口
	mushroomMovement(200.0f, 200.0f)                          // 初始化蘑菇移动速度
{
	// 加载蘑菇的纹理
	if (!mushroomTexture.loadFromFile("mushroom50-50.png")) {
		// 错误处理
		throw std::runtime_error("Failed to load mushroom texture!");
	}
	// 设置蘑菇精灵的纹理
	mushroomSprite.setTexture(mushroomTexture);
	mushroomSprite.setPosition(375.0f, 275.0f); // 设置初始位置
}



// 2.  Define an empty default destructor.
Game::~Game()
{
	//TODO: delete
}



// MEMBER FUNCTIONS:

// 3. For handling the input. This logic will not handle any input yet, so define an empty handling function.
void Game::userInput()
{
	//TODO: Achieve logic of mushroomMove
}


// 4. For updating tha game state:
//	  a) Call the private function of this class that executes the logic (mushroom movement).
//    b) Call the update function of the window (the window does handle input in the update function. This is not really orthodox, 
//       but it will work for now).
void Game::update()
{
	updateMushroomMovement();
	//mushroom->move();
	applicationWindow.update();
}



// 5. Function for rendering the game:
//    a) Our window object offers functionality for clearing the screen. Call the method that starts the draw on the window member first.
//    b) Draw the mushroom on screen, by calling the draw function in window that receives a reference to a sf::Drawable& reference.
//    c) Our window also offers functionality for displaying all that has been drawn since the last clear. Call the method that ends the draw on the window now.
void Game::render()
{
	applicationWindow.beginDraw();
	applicationWindow.draw(mushroomSprite);  // 绘制蘑菇
	applicationWindow.endDraw();
}


// 6. Define the function that returns a pointer to the window member variable of this class.
Window* Game::getWindow()
{
	return &applicationWindow;
}




// 7. Define the function for updating the movement of the mushroom.
//    The following is pseudocode (as I don't know how you named your member variables):
//
//    # Some initializations:
//    windowSize <- window.getWindowSize 
//    textureSize <- mushroomTexture.getSize
//    xRightLimit <- windowSize.width - textureSize.width
//    yBottomLimit <- windowSize.height - textureSize.height
//
//    # Check if we are bouncing off the right or left edges:
//    bouncesRight <- (mushroom.xPosition > xRightLimit AND mushroom.movement.x > 0)
//    bouncesLeft <- (mushroom.xPosition < 0 AND mushroom.movement.x < 0)
//    if bouncesRight OR bouncesLeft
//       { change sign of mushroom.movement.x }
//    
//    # Same for top or bottom edges:
//    bouncesBottom <- (mushroom.yPosition > yBottomLimit AND mushroom.movement.y > 0)
//    bouncesTop <- (mushroom.yPosition < 0 AND mushroom.movement.y < 0)
//    if bouncesBottom OR bouncesTop
//       { change sign of mushroom.movement.y }
//
//	  mushroom.setPosition(mushroom.xPosition + mushroom.movement.x, mushroom.yPosition + mushroom.movement.y)

void Game::updateMushroomMovement()
{
	sf::Vector2f position = getMushroomPosition();
	sf::Vector2u windowSize = applicationWindow.getWindowSize();
	sf::Vector2u textureSize = mushroomTexture.getSize();
	float xRightLimit = static_cast<float>(windowSize.x - textureSize.x);
	float yBottomLimit = static_cast<float>(windowSize.y - textureSize.y);
	bool bouncesRight = (position.x > xRightLimit && mushroomMovement.x > 0);
	bool bouncesLeft = (position.x < 0 && mushroomMovement.x < 0);
	if (bouncesRight || bouncesLeft)
	{
		mushroomMovement.x = -mushroomMovement.x;
	}
	
	bool bouncesBottom = (position.y > yBottomLimit && mushroomMovement.y > 0);
	bool bouncesTop = (position.y < 0 && mushroomMovement.y < 0);
	if (bouncesBottom || bouncesTop)
	{
		mushroomMovement.y = -mushroomMovement.y;
	}
	mushroomSprite.move(mushroomMovement.x, mushroomMovement.y);

}

sf::Vector2f Game::getMushroomPosition() const
{
	return mushroomSprite.getPosition();
}