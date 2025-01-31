#pragma once
#include<SFML/Graphics.hpp>
#include"Window.h"

class Entity
{
public:
	Entity(const std::string& texturePath, const sf::Vector2f& position, const sf::Vector2f& movement);
	~Entity();

	void draw(Window& window);
	void move();
	sf::Vector2f getPosition() const;
private:
	sf::Texture texture;
	sf::Vector2f movementSpeed;
	sf::Sprite sprite;

};

