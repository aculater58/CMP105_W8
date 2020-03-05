#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Collision.h"
#include <SFML/Graphics.hpp>

class Ball : public GameObject
{
public:
	void update(float dt);
	void collisionResponse(GameObject* collider);

	Ball(sf::RenderWindow* hwnd);

	float scale;
	bool Direction, Collided;

	sf::Vector2f stepVelocity;

	sf::RenderWindow* window;
};