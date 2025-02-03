#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>  // 添加 time 头文件
#include <cstdlib> // 添加 srand 和 rand 头文件
#include <iostream>


// Check here APIs for the SFML classes to be used in this LAB (all in here: https://www.sfml-dev.org/documentation/2.5.1/annotated.php):
//   sf::RenderWindow -  https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
//   sf::Vector2u - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Vector2.php
//   sf::Style - https://www.sfml-dev.org/documentation/1.6/namespacesf_1_1Style.php
//   sf::Drawable - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php
//   sf::Texture - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Texture.php 
//   sf::Sprite - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
int simpleLoop(Game& game)
{
    sf::Clock frameClock;

    sf::Time startTime = frameClock.getElapsedTime();// 记录循环开始时间

    game.userInput();
    game.update();
    game.render();

    sf::Time endTime = frameClock.getElapsedTime();// 记录循环结束时间

    // 计算帧时间（秒）
    float elapsedSeconds = endTime.asSeconds() - startTime.asSeconds();
    int fps = (elapsedSeconds > 0) ? static_cast<int>(1.0f / elapsedSeconds) : 0;

    std::cout << "Frame Time: " << elapsedSeconds * 1000.0f << " ms, FPS: " << fps << std::endl;
    return fps;
}


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    Game game(100, 0.1f);

    int frameCount = 0;
    float averageFPS = 0.0f;

    while (!game.getWindow()->isWindowDone())
    {
        int currentFPS = simpleLoop(game);
        frameCount++;
        averageFPS = averageFPS + (currentFPS - averageFPS) / frameCount;
        
        std::cout << "Average FPS: " << static_cast<int>(averageFPS) << std::endl;// 打印最终的平均 FPS
    }
    return 0;
}
