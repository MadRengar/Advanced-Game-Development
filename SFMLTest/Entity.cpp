#include "Entity.h"
#include<stdexcept>

Entity::Entity(const std::string& texturePath, const sf::Vector2f& position, const sf::Vector2f& movement)
    : movementSpeed(movement) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture: " + texturePath);
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Entity::~Entity(){}

void Entity::draw(Window& window)
{
    window.draw(sprite);
}

void Entity::move()
{
    sprite.move(movementSpeed.x, movementSpeed.y);
}

sf::Vector2f Entity::getPosition() const
{
    return sprite.getPosition();
}
