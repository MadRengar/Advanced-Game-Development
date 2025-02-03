#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>  // ��� time ͷ�ļ�
#include <cstdlib> // ��� srand �� rand ͷ�ļ�
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

    sf::Time startTime = frameClock.getElapsedTime();// ��¼ѭ����ʼʱ��

    game.userInput();
    game.update();
    game.render();

    sf::Time endTime = frameClock.getElapsedTime();// ��¼ѭ������ʱ��

    // ����֡ʱ�䣨�룩
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
        
        std::cout << "Average FPS: " << static_cast<int>(averageFPS) << std::endl;// ��ӡ���յ�ƽ�� FPS
    }
    return 0;
}
