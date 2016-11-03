#include "obstacle.h"


//create an empty default constructor 
obstacle::obstacle() {}

obstacle::obstacle(sf::Vector2f position, sf::Texture* obstacleTexture)
{
	obstacleSprite.setTexture(*obstacleTexture);
	obstacleSprite.setScale(0.2, 0.2);  //change back to 0.5 later
	obstacleSprite.setPosition(position.x, position.y);

	srand(time(NULL));
}

//random seed will come into play later
//create a second constructor, set the obstacle's texture, scale, and position
//add srand(time(NULL));

void obstacle::update(int type)
{
	if (type == 1)
	{

		obstacleSprite.move(-5, 0);  //evilgem
		//moves the obstacles across the screen towards the player
		if (obstacleSprite.getPosition().x < 0)
		{

			obstacleSprite.setPosition(1052, randomizeYPos());

			//if it goes off the left side, set it to the right side
		}
	}
	if (type == 2)  //evilgem2
	{

		obstacleSprite.move(-3, 0);
		//moves the obstacles across the screen towards the player
		if (obstacleSprite.getPosition().x < 0)
		{

			obstacleSprite.setPosition(1052, randomizeYPos());

			//if it goes off the left side, set it to the right side
		}
	}/*
	if (type == 3)
	{

		obstacleSprite.move(-4, 0);
		//moves the obstacles across the screen towards the player
		if (obstacleSprite.getPosition().x < 0)
		{

			obstacleSprite.setPosition(1052, randomizeYPos());

			//if it goes off the left side, set it to the right side
		}
	}*/
	if( type == 0)
	{
		obstacleSprite.move(-15, 0);
		//moves the obstacles across the screen towards the player
		if (obstacleSprite.getPosition().x < 0)
		{

			obstacleSprite.setPosition(1052, randomizeYPos());

			//if it goes off the left side, set it to the right side
		}
	}
}

void obstacle::reposition()
{
	obstacleSprite.setPosition(sf::Vector2f(1052, randomizeYPos()));
}

int obstacle::shardNumber()
{
	int randValue = rand() % 9;
	
	return randValue;
}

int obstacle::randomizeYPos()
{
	int randomY;
	int thePosition = 0;
	randomY = rand() % 3;
	if (randomY == 0)
	{
		thePosition = 550;
	}
	else if (randomY == 1)
	{
		thePosition = 450;
	}
	else if (randomY == 2)
	{
		thePosition = 350;
	}
	return thePosition;
}