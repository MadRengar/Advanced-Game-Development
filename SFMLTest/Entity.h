#pragma once
#include<SFML/Graphics.hpp>
#include"Window.h"

class Entity
{
public:
	Entity(const std::string& texturePath, Window* window, float speed);
	~Entity();

	void draw(Window& window);
	void update();
	sf::Vector2f getPosition() const;
private:
	sf::Texture texture; // 纹理负责存储纹理数据（图片），本身不会直接被渲染，而是提供给 sf::Sprite 使用，最终在窗口上绘制的对象
	/*sf::Vector2f movementSpeed;*/
	sf::Sprite sprite;// sprite 负责在窗口上显示纹理，并且可以控制位置、缩放、旋转等属性

	sf::Vector2f movementDirection; // 方向
	float movementSpeed; // 速度
};

