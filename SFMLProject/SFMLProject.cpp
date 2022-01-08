#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Brick.h"
#include <iostream>
#include <algorithm>
#include "Sounds.h"

extern const int WIDTH = 800;
extern const int HEIGHT = 600;

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BreakOut");

    sf::Font font;
    if (!font.loadFromFile("verdanab.ttf"))
    {
        std::cerr << "Error Loading Font" << std::endl;
    }

    sf::Text text;

    //register sounds;

    Sounds::RegisterSound("win", "sfx-piano-coda4.wav");
    Sounds::RegisterSound("loss", "sfx-piano-mystery2.wav");

    // select the font
    text.setFont(font);

    unsigned int numberOfBricks = 6;
    unsigned int numberOfRows = 3;

    int totalNumberOfBricks = numberOfBricks * numberOfRows;

    //create sprites
    Player ship(400, 550, "Paddle.png");
    Ball ball(425, 525, "Ball.png");

    //initialize bricks
    std::vector<Brick*> bricks;

    float brickPosX = (WIDTH / 2) - (numberOfBricks > 0 ? 50*(numberOfBricks-1) + 10.f : 0);
    float brickPosY = 100;

    for (unsigned int rows = 0; rows < numberOfRows; ++rows)
    {
        for (unsigned int brickCount = 0; brickCount < numberOfBricks; ++brickCount)
        {
            bricks.push_back(new Brick(brickPosX, brickPosY, "brick.png"));

            brickPosX += bricks.back()->GetTextureWidth() + 5;
        }
        brickPosX = (WIDTH / 2) - (numberOfBricks > 0 ? 50 * (numberOfBricks - 1) + 10.f : 0);
        brickPosY += bricks.back()->GetTextureHeight() + 5;
    }

    bool pause{ false };


    sf::Clock clock;
    while (window.isOpen())
    {
        //event handling
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        
        if (!pause)
        {
            window.clear();

            //calculate delta time
            sf::Time elapsedTime = clock.restart();
            float deltaTime = elapsedTime.asSeconds();

            //std::cout << deltaTime << std::endl;

            ship.Update(deltaTime);
            ball.Update(deltaTime);
            ball.CheckCollision(ship);

            window.draw(ship.GetSprite());
            window.draw(ball.GetSprite());

            for (auto brick : bricks)
            {
                if (!brick->GetIsDestroyed())
                {
                    brick->Update(deltaTime);
                    brick->CheckCollision(ball);
                    ball.CheckCollision(*brick);
                    window.draw(brick->GetSprite());
                }
                else
                {
                    bricks.erase(std::remove(bricks.begin(), bricks.end(), brick), bricks.end());
                    --totalNumberOfBricks;
                    std::cout << "brick Remaining :" << totalNumberOfBricks << "\n";
                }

            }

            window.display();
        }
       
        //check win conditions
        if (ball.GetIsBallOutOfBounds())
        {
            Sounds::PlayerRegisteredSound("loss");
            pause = true;

            ball.SetIsBallOutOfBounds(false);

            text.setString("Game Over");
            text.setCharacterSize(78);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setPosition(sf::Vector2f(WIDTH / 2 - text.getGlobalBounds().width / 2, HEIGHT / 2 - text.getGlobalBounds().height));

            window.draw(text);
            window.display();
           
            //game over
        }
        else if (totalNumberOfBricks == 0)
        {
            //win
            Sounds::PlayerRegisteredSound("win");
            totalNumberOfBricks = numberOfBricks * numberOfRows;
            pause = true;
            text.setString("Victory");
            text.setCharacterSize(78);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setPosition(sf::Vector2f(WIDTH / 2 - text.getGlobalBounds().width / 2, HEIGHT / 2 - text.getGlobalBounds().height));

            window.draw(text);
            window.display();
        }
        
       
    }

    return 0;
}
