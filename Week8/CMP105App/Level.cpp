#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in) : Ball1(hwnd), Ball2(hwnd)
{
	

	window = hwnd;
	input = in;

	// initialise game objects
	TBall.loadFromFile("gfx/Beach_Ball.png");

	Ball1.setTexture(&TBall);
	Ball1.setSize(sf::Vector2f(100, 100));
	Ball1.setPosition(0, 300);

	Ball2.setTexture(&TBall);
	Ball2.setSize(sf::Vector2f(100, 100));
	Ball2.setPosition(1100, 300);
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	Ball1.update(dt);
	Ball2.update(dt);
	if (Collision::checkBoundingCircle(&Ball1, &Ball2)) 
	{ 
	Ball1.collisionResponse(NULL); 
	Ball2.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(Ball1);
	window->draw(Ball2);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}