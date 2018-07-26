//#include "inc/common.h"
#include "../inc/sfmlLoop.h"


sfmlLoop::sfmlLoop()
{
    window.create(sf::VideoMode(1680, 1050), "SFML works!"/*, sf::Style::None*/);
    window.setFramerateLimit(60);
    
    setCharacterObjects(1);
    setCollideObjects(40);
}

void sfmlLoop::sfml()
{

    while (window.isOpen())
    {
        buttonPressed();
        vecCharacter[0].gravity(vecCollideObjects);
        
        while (window.pollEvent(event))
        {
            events();
        }
        windowUpdate();
    }
}

void sfmlLoop::buttonPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vecCharacter[0].charMove("up", vecCollideObjects);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vecCharacter[0].charMove("down", vecCollideObjects);
    }
    //
    //
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vecCharacter[0].charMove("left", vecCollideObjects);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vecCharacter[0].charMove("right", vecCollideObjects);
    }
}

void sfmlLoop::events()
{
    if (event.type == sf::Event::Closed)
        window.close();
}

void sfmlLoop::windowUpdate()
{
    window.clear(sf::Color::White);
    drawCollideObjects();
    drawCharacter();
    window.display();
}

void sfmlLoop::setCharacterObjects(int count)
{
    //character(4, sf::Vector2f(32, 32), sf::Color::Black, sf::Color::Green);
    for(int i = 0; i < count; i++)
    {
        vecCharacter.push_back(character(4, 0, sf::Vector2f(32, 32), sf::Vector2f(0, 0), sf::Color::Black, sf::Color::Green));
    }
}

void sfmlLoop::setCollideObjects(int count)
{
    int x = 10, y = 500;
    
    //wall(sf::Vector2f wallSize, sf::Vector2f wallPos, sf::Color wallCol)
    for(int i = 0; i < count; i++)
    {
        
        if(i < 10)
        {
            x = x + 32;
        }
        else if(i < 20)
        {
            y = y + 32;
            if(i == 11 || i == 12)
            {
                continue;
            }
        }
        else if(i < 30)
        {
            x = x - 32;
        }
        else if(i < 40)
        {
            y = y - 32;
        }
        vecBuilding1.push_back(collideObject(sf::Vector2f(32, 32), sf::Vector2f(x, y), sf::Color::Blue));
    }
    vecCollideObjects.push_back(vecBuilding1);
}

void sfmlLoop::drawCharacter()
{
    for(int i = 0; i < vecCharacter.size(); i++)
    {
        window.draw(vecCharacter[i].getCharacter());
    }
}

void sfmlLoop::drawCollideObjects()
{
    for(int i = 0; i < vecCollideObjects.size(); i++)
    {
        for(int j = 0; j < vecCollideObjects[i].size(); j++)
        {
            window.draw(vecCollideObjects[i][j].getObject());
        }
    }
}
