#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\System\Clock.hpp>
#include "player.h"
#include <sstream>
#include <iostream>
#include "obstacle.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 700), "Running!");
	sf::Texture background;
	sf::Texture background2; sf::Sprite bgSprite2; background2.loadFromFile("Textures/game_over___the_return_of_ganon_by_zekezurita-d6zqann.png");
	sf::Sprite bgSprite;

	sf::Texture obstacleTexture; sf::Texture obstacleTexture8;
	sf::Texture obstacleTexture0; sf::Texture obstacleTexture1; sf::Texture obstacleTexture2; sf::Texture obstacleTexture3; 
	sf::Texture obstacleTexture4; sf::Texture obstacleTexture5; sf::Texture obstacleTexture6; sf::Texture obstacleTexture7;
	obstacleTexture.loadFromFile("Textures/gem.png");
	obstacleTexture0.loadFromFile("Textures/Triforce3.png");
	obstacleTexture1.loadFromFile("Textures/120px-Triforce_Shard_1.png");
	obstacleTexture2.loadFromFile("Textures/120px-Triforce_Shard_2.png");
	obstacleTexture3.loadFromFile("Textures/120px-Triforce_Shard_3.png");
	obstacleTexture4.loadFromFile("Textures/120px-Triforce_Shard_4.png");
	obstacleTexture5.loadFromFile("Textures/120px-Triforce_Shard_5.png");
	obstacleTexture6.loadFromFile("Textures/120px-Triforce_Shard_6.png");
	obstacleTexture7.loadFromFile("Textures/120px-Triforce_Shard_7.png");
	obstacleTexture8.loadFromFile("Textures/120px-Triforce_Shard_8.png");

	
	sf::Texture completeTex0; sf::Texture completeTex1; sf::Texture completeTex2; sf::Texture completeTex3; sf::Texture completeTex4; 
	sf::Texture completeTex5; sf::Texture completeTex6; sf::Texture completeTex7; sf::Texture completeTex8;
	
	completeTex0.loadFromFile("Textures/Triforce_Complete0.png");
	completeTex1.loadFromFile("Textures/Triforce_Complete1.png");
	completeTex2.loadFromFile("Textures/Triforce_Complete2.png");
	completeTex3.loadFromFile("Textures/Triforce_Complete3.png");
	completeTex4.loadFromFile("Textures/Triforce_Complete4.png");
	completeTex5.loadFromFile("Textures/Triforce_Complete5.png");
	completeTex6.loadFromFile("Textures/Triforce_Complete6.png");
	completeTex7.loadFromFile("Textures/Triforce_Complete7.png");
	completeTex8.loadFromFile("Textures/Triforce_Complete8.png");
	sf::Sprite triforceSprite0; triforceSprite0.setTexture(completeTex0);triforceSprite0.setOrigin(32, 32);triforceSprite0.setScale(0.3, 0.3);triforceSprite0.setPosition(100, 100);
	sf::Sprite triforceSprite1; triforceSprite0.setTexture(completeTex1);triforceSprite1.setOrigin(32, 32);triforceSprite1.setScale(0.3, 0.3);triforceSprite1.setPosition(100, 100);
	sf::Sprite triforceSprite2; triforceSprite0.setTexture(completeTex2);triforceSprite2.setOrigin(32, 32);triforceSprite2.setScale(0.3, 0.3);triforceSprite2.setPosition(100, 100);
	sf::Sprite triforceSprite3; triforceSprite0.setTexture(completeTex3);triforceSprite3.setOrigin(32, 32);triforceSprite3.setScale(0.3, 0.3);triforceSprite3.setPosition(100, 100);
	sf::Sprite triforceSprite4; triforceSprite0.setTexture(completeTex4);triforceSprite4.setOrigin(32, 32);triforceSprite4.setScale(0.3, 0.3);triforceSprite4.setPosition(100, 100);
	sf::Sprite triforceSprite5; triforceSprite0.setTexture(completeTex5);triforceSprite5.setOrigin(32, 32);triforceSprite5.setScale(0.3, 0.3);triforceSprite5.setPosition(100, 100);
	sf::Sprite triforceSprite6; triforceSprite0.setTexture(completeTex6);triforceSprite6.setOrigin(32, 32);triforceSprite6.setScale(0.3, 0.3);triforceSprite6.setPosition(100, 100);
	sf::Sprite triforceSprite7; triforceSprite0.setTexture(completeTex7);triforceSprite7.setOrigin(32, 32);triforceSprite7.setScale(0.3, 0.3);triforceSprite7.setPosition(100, 100);
	sf::Sprite triforceSprite8; triforceSprite0.setTexture(completeTex8);triforceSprite8.setOrigin(32, 32);triforceSprite8.setScale(0.3, 0.3);triforceSprite8.setPosition(100, 100);
	obstacle triforceComplete0 = obstacle(sf::Vector2f(50, 50), &completeTex0);
	obstacle triforceComplete1 = obstacle(sf::Vector2f(50, 50), &completeTex1);
	obstacle triforceComplete2 = obstacle(sf::Vector2f(50, 50), &completeTex2);
	obstacle triforceComplete3 = obstacle(sf::Vector2f(50, 50), &completeTex3);
	obstacle triforceComplete4 = obstacle(sf::Vector2f(50, 50), &completeTex4);
	obstacle triforceComplete5 = obstacle(sf::Vector2f(50, 50), &completeTex5);
	obstacle triforceComplete6 = obstacle(sf::Vector2f(50, 50), &completeTex6);
	obstacle triforceComplete7 = obstacle(sf::Vector2f(50, 50), &completeTex7);
	obstacle triforceComplete8 = obstacle(sf::Vector2f(50, 50), &completeTex8);
	//loads the texture and calls the second constructor
	//pass in an initial position &texture variable name
	bool gameOver = false; //gamestate
	
	sf::Texture EvilObstacleTexture1; sf::Texture EvilObstacleTexture2;
	EvilObstacleTexture1.loadFromFile("Textures/Bubble_Figurine1.png");
	EvilObstacleTexture2.loadFromFile("Textures/Bubble_Figurine2.png");
	
	obstacle evilGem = obstacle(sf::Vector2f(500, 200), &EvilObstacleTexture1);
	obstacle evilGem2 = obstacle(sf::Vector2f(550, 400), &EvilObstacleTexture2);
	/*int randValueA = rand() % 2; 
	if (randValueA == 0)
	{
		evilGem.obstacleTexture = EvilObstacleTexture1;
		//chart.obstacleTexture = completeTex8;
	}
	else
		evilGem.obstacleTexture= EvilObstacleTexture2;
*/

	int score = 0;
	int secretScore = 0;
	int collection[8] = {0,0,0,0,0,0,0,0};
	sf::Text scoreText;
	sf::Font gameFont;
	gameFont.loadFromFile("font/ITCBLKAD.ttf");
	
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score)); scoreText.setCharacterSize(40);
	scoreText.setColor(sf::Color::Cyan);

	obstacle shard;
	obstacle chart;
	float initialxPos = 500;
	float initialyPos;
	int yRand = rand() % 3;
	if (yRand == 0 )
	{
		initialyPos = 550;
	}
	else if (yRand == 1)
	{
		initialyPos = 450;
	}
	else if (yRand == 2)
	{
		initialyPos = 350;
	}
	int randValue = shard.shardNumber();
	
	if (randValue == 0)
	{
		shard.obstacleTexture = obstacleTexture0;
		//chart.obstacleTexture = completeTex0;
	}
	if (randValue == 1)
	{
		shard.obstacleTexture = obstacleTexture1;
		//chart.obstacleTexture = completeTex1;
	}
	if (randValue == 2)
	{
		shard.obstacleTexture = obstacleTexture2;
		//chart.obstacleTexture = completeTex2;
	}
	if (randValue == 3)
	{
		shard.obstacleTexture = obstacleTexture3;
		//chart.obstacleTexture = completeTex3;
	}
	if (randValue == 4)
	{
		shard.obstacleTexture = obstacleTexture4;
		//chart.obstacleTexture = completeTex4;
	}
	if (randValue == 5)
	{
		shard.obstacleTexture = obstacleTexture5;
		//chart.obstacleTexture = completeTex5;
	}
	if (randValue == 6)
	{
		shard.obstacleTexture = obstacleTexture6;
		//chart.obstacleTexture = completeTex6;
	}
	if (randValue == 7)
	{
		shard.obstacleTexture = obstacleTexture7;
		//chart.obstacleTexture = completeTex7;
	}
	if (randValue == 8)
	{
		shard.obstacleTexture = obstacleTexture8;
		//chart.obstacleTexture = completeTex8;
	}
	
	shard = obstacle(sf::Vector2f(initialxPos, initialyPos), &shard.obstacleTexture);
	chart = obstacle(sf::Vector2f(200,0),&chart.obstacleTexture);
	

	
	int randomY;
	int thePosition[5];
	

	background.loadFromFile("Textures/botw_hyrule.png");//("Textures/city_background.png"); //background image goes here
	bgSprite.setTexture(background);
	bgSprite.setOrigin(100, 270);
	window.setFramerateLimit(40); //remove? 

	player thePlayer;

	sf::Clock animateClock; //add in a clock to control time
	float animateTimer = 0.0f;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed)  //jumping
			{
				if (event.key.code == sf::Keyboard::Space)

				{
					if (!thePlayer.jumping)
					{
					
						thePlayer.jumpState = 1;
						//printf("1");
						thePlayer.jumping = true;
					}

				}
				else
					thePlayer.jumping = false;
			}

			animateTimer = animateClock.getElapsedTime().asSeconds();
			if (animateTimer > 0.1f) //fps, not not trigger new animation 
			{
				thePlayer.animatePlayer();
				animateClock.restart();
			}

			thePlayer.update(); //update the player
			//anObstacle.update();
			window.clear();


			if (!gameOver)
			{
				window.draw(bgSprite); //draw background first

				shard.update(0);                                  //shard update

				if (randValue == 0)
				{
					shard.obstacleTexture = obstacleTexture0;
				}
				if (randValue == 1)
				{
					shard.obstacleTexture = obstacleTexture1;
					
				}
				if (randValue == 2)
				{
					shard.obstacleTexture = obstacleTexture2;
					
				}
				if (randValue == 3)
				{
					shard.obstacleTexture = obstacleTexture3;
					
				}
				if (randValue == 4)
				{
					shard.obstacleTexture = obstacleTexture4;
					
				}
				if (randValue == 5)
				{
					shard.obstacleTexture = obstacleTexture5;
					//chart.obstacleTexture = completeTex5;
				}
				if (randValue == 6)
				{
					shard.obstacleTexture = obstacleTexture6;
					//chart.obstacleTexture = completeTex6;
				}
				if (randValue == 7)
				{
					shard.obstacleTexture = obstacleTexture7;
					//chart.obstacleTexture = completeTex7;
				}
				if (randValue == 8)
				{
					shard.obstacleTexture = obstacleTexture8;
					//chart.obstacleTexture = completeTex8;
				}

				
				window.draw(shard.obstacleSprite); //draw gem on window

				if (thePlayer.playerSprite.getGlobalBounds().intersects(shard.obstacleSprite.getGlobalBounds()))
				{//get collision
					shard.reposition();
					secretScore += 1;
					if (collection[randValue] != 1)
					{
						//printf("got to the part where score should increase");
						score += 100;
						collection[randValue] = 1;

						scoreText.setString("Score: " + std::to_string(score));
						if (score >= 900)
							scoreText.setString("You win!");
					}

					randValue = shard.shardNumber();
				}

				if (shard.obstacleSprite.getPosition().x < 10) //randomizes the shard at edge of screen
				{
					randValue = shard.shardNumber();
				}
				
				
				window.draw(thePlayer.playerSprite);     //enemy update
				
				evilGem.update(1);
				evilGem2.update(2);
				

				window.draw(evilGem.obstacleSprite);
				window.draw(evilGem2.obstacleSprite);
				
				if (collection[0] == 1)
					window.draw(triforceComplete0.obstacleSprite);
				if (collection[1] == 1)
					window.draw(triforceComplete1.obstacleSprite);
				if (collection[2] ==1)
					window.draw(triforceComplete2.obstacleSprite);
				if (collection[3] ==1)
					window.draw(triforceComplete3.obstacleSprite);
				if (collection[4] == 1)
					window.draw(triforceComplete4.obstacleSprite);
				if (collection[5] == 1)
					window.draw(triforceComplete5.obstacleSprite);
				if (collection[6] == 1)
					window.draw(triforceComplete6.obstacleSprite);
				if (collection[7] == 1)
					window.draw(triforceComplete7.obstacleSprite);
				if (collection[8] == 1)
					window.draw(triforceComplete8.obstacleSprite);
				
				
				if (thePlayer.playerSprite.getGlobalBounds().intersects(evilGem.obstacleSprite.getGlobalBounds())|| thePlayer.playerSprite.getGlobalBounds().intersects(evilGem2.obstacleSprite.getGlobalBounds()))
				{
					evilGem.reposition();
					evilGem2.reposition();
					gameOver = true; //one hit one kill 
				}
				
			}
			else {
				if (score >= 900)
				{
					scoreText.setString("You win! Total Triforce Collected: " + std::to_string(secretScore));
					scoreText.setColor(sf::Color::Cyan);
					scoreText.setCharacterSize(48);
					scoreText.setPosition(200, 300);
				}
				else {
					window.clear();
					window.draw(bgSprite2);
					scoreText.setString("Game Over. Score: " + std::to_string(score));
					scoreText.setColor(sf::Color::Red);
					scoreText.setCharacterSize(48);
					scoreText.setPosition(300, 300); //the larger the second number, the lower down
					window.draw(scoreText);
					window.display();
				}
			}
			//window.draw(anObstacle.obstacleSprite);
			window.draw(scoreText);
			
			window.display();
		}
	}
}
	
