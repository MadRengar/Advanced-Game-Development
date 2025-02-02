#include <SFML/Graphics.hpp>
#include "Game.h"
#include <ctime>  // ��� time ͷ�ļ�
#include <cstdlib> // ��� srand �� rand ͷ�ļ�


// Check here APIs for the SFML classes to be used in this LAB (all in here: https://www.sfml-dev.org/documentation/2.5.1/annotated.php):
//   sf::RenderWindow -  https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php
//   sf::Vector2u - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Vector2.php
//   sf::Style - https://www.sfml-dev.org/documentation/1.6/namespacesf_1_1Style.php
//   sf::Drawable - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php
//   sf::Texture - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Texture.php 
//   sf::Sprite - https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Game game(10, 0.5f);
    while (!game.getWindow()->isWindowDone())
    {
        game.userInput(); // ��������
        game.update();    // ������Ϸ״̬
        game.render();    // ��Ⱦ����
    }
    return 0;
}