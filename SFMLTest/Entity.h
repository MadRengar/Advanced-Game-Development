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
	sf::Texture texture; // ������洢�������ݣ�ͼƬ����������ֱ�ӱ���Ⱦ�������ṩ�� sf::Sprite ʹ�ã������ڴ����ϻ��ƵĶ���
	/*sf::Vector2f movementSpeed;*/
	sf::Sprite sprite;// sprite �����ڴ�������ʾ�������ҿ��Կ���λ�á����š���ת������

	sf::Vector2f movementDirection; // ����
	float movementSpeed; // �ٶ�
};

