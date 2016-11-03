//#pragma once
#include <SFML\Graphics.hpp>

class obstacle { //you can inherit from it later different types of collectable or avoidable obstacles
public:
	sf::Texture obstacleTexture;
	sf::Sprite obstacleSprite;
	float yPos;

	obstacle(); //default constructor
	//it takes two arguments, one for position
	//the other is a pointer ot the obstacle's texture
	obstacle(sf::Vector2f position, sf::Texture *obstacleTexture);
	//function prototypes
	void update(int type); //control movement
	void reposition(); //wrap objects around the screen
	int shardNumber(); //determines which triforce shard is chosen 
	int randomizeYPos(); //used in the reposition funciton


};