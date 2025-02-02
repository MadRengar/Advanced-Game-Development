#include "Entity.h"
#include<stdexcept>
#include<iostream>

Entity::Entity(const std::string& texturePath, Window* window, float speed)
    : movementSpeed(speed) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture: " + texturePath);
    }
    sprite.setTexture(texture);
    //sprite.setPosition(position);
    if (window)// ���ָ���Ƿ�Ϊ�գ����������Ч�ڴ�
    {
        sf::Vector2u windowSize = window->getWindowSize();
        float randomX = static_cast<float>(rand() % (windowSize.x - texture.getSize().x));
        float randomY = static_cast<float>(rand() % (windowSize.y - texture.getSize().y));
        sprite.setPosition(randomX, randomY);
        std::cout << "Entity initial position: (" << randomX << ", " << randomY << ")\n";
    }
    else {
        throw std::runtime_error("window pointer is nullptr!");
    }

    // ������ɷ�������
    float angle = static_cast<float>(rand()) / RAND_MAX * 2 * 3.14159265f; // �Ƕȷ�Χ [0, 2��]
    movementDirection = sf::Vector2f(std::cos(angle), std::sin(angle));
}

Entity::~Entity(){}

void Entity::draw(Window& window)
{
    window.draw(sprite);// sprite �� window �ϱ����ƣ������� texture
}

void Entity::update()
{
    sprite.move(movementDirection.x * movementSpeed, movementDirection.y * movementSpeed);
    /*sprite.move(movementSpeed.x, movementSpeed.y);*/
}

sf::Vector2f Entity::getPosition() const
{
    return sprite.getPosition();
}
