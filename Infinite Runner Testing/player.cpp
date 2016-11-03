#include "player.h"


bool jumpDown = false;

player::player() : player(sf::Vector2f(100, 540), "Textures/twilightlinkspritesheet3.png", "Textures/twilightlinkspritesheet5.png") {

}
//missing the end of this code 

player::player(sf::Vector2f position, std::string textFileLoc, std::string jumpFileLoc) {
	playerTexture.loadFromFile(textFileLoc);
	jumpingTexture.loadFromFile(jumpFileLoc);
	
	//series of rects for walking animation
	walkRect[0] = sf::IntRect(0, 0, 50, 50);
	walkRect[1] = sf::IntRect(50, 0, 50, 50);
	walkRect[2] = sf::IntRect(100, 0, 50, 50);
	walkRect[3] = sf::IntRect(150, 0, 50, 50);
	walkRect[4] = sf::IntRect(200, 0, 50, 50);
	walkRect[5] = sf::IntRect(250, 0, 50, 50);
	walkRect[6] = sf::IntRect(300, 0, 50, 50);

	//series of rects for jumping animation
	jumpRect[0] = sf::IntRect(0, 0, 50, 50);
	jumpRect[1] = sf::IntRect(50, 0, 50, 50);
	jumpRect[2] = sf::IntRect(100, 0, 50, 50);
	jumpRect[3] = sf::IntRect(150, 0, 50, 50);
	jumpRect[4] = sf::IntRect(200, 0, 50, 50);
	jumpRect[5] = sf::IntRect(250, 0, 50, 50);
	

	//initalize and place player sprite
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(walkRect[0]);
	playerSprite.setOrigin(15, 16);
	playerSprite.setScale(1.5, 1.5);
	playerSprite.setPosition(position.x, position.y);

	jumping = false;
	jumpState = 0;
	count = 0;
}


//function to cycle through animations based on whether the player is jumping or walking
int player::animatePlayer()
{
	if (!jumping) //! ? 19:10 it's what it has
	{
		if (count < 5) //this updates the sprite frame
		{
			count++;
		}
		else {
			count = 0;
		}
	}
	else {
		if (jumpState == 1)
		{
			if (count < 2)
			{
				count++;
			}
		}
		else if (jumpState == 2)
		{
			if (count < 4)
			{
				count++;
			}
		}
	}
	return count;
}

//function that makes the player jump, and displays the correct texture on the player sprite
void player::update()
{
	
	if (jumping)
	{
		playerSprite.setTextureRect(jumpRect[count]);
		//printf("start over ");
		if (jumpState == 1 && jumping)
		{
			playerSprite.setTexture(jumpingTexture);
			count = 0;
			//jumpState = 2; printf("jumpState2 ");
		}
		if (jumpState = 2 && jumping)
		{
			if (playerSprite.getPosition().y > 240)
			{
				//printf("moving up? ");
				
				playerSprite.move(0, -10);
				
			}
			else
			{
				
					jumpState = 3;
					jumping = false;

					//sf::sleep(sf::seconds(2));
					//printf("jumpState3 ");
				
			}
		}
	
			
		
	}
	else {
		jumping = false;
		if (playerSprite.getPosition().y < 540)  //if not holding jump, is fallind down 
		{
			playerSprite.move(0, 10);
		}
		else {
			playerSprite.setTexture(playerTexture);
			playerSprite.setTextureRect(walkRect[count]);
		}
	}
}