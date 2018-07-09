//#include "inc/common.h"
#include "../inc/character.h"

character::character(int sp, int isN, sf::Vector2f charSize, sf::Vector2f charPos, sf::Color charCol, sf::Color bufCol)
{
    
    speed = sp;
    isNpc = isN;
    
    characterShape.setSize(charSize);
    bufferTop.setSize(sf::Vector2f(characterShape.getSize().x, 1));
    bufferBottom.setSize(sf::Vector2f(characterShape.getSize().x, 1));
    bufferLeft.setSize(sf::Vector2f(1, characterShape.getSize().y));
    bufferRight.setSize(sf::Vector2f(1, characterShape.getSize().y));
    
    characterShape.setPosition(charPos);
    
    characterShape.setFillColor(charCol);
    bufferTop.setFillColor(bufCol);
    bufferBottom.setFillColor(bufCol);
    bufferLeft.setFillColor(bufCol);
    bufferRight.setFillColor(bufCol);
    
}

sf::RectangleShape character::getCharacter()
{
    return characterShape;
}

void character::charMove(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects)
{
    if(direction == "up")
    {
        for(int i = 0; i < speed; i++)
        {
            updateBuffer();
            if(updateCollide(direction, vecCollideObjects) == 0)
            {
                characterShape.move(0, -1);
            }
        }
    }
    if(direction == "down")
    {
        for(int i = 0; i < speed; i++)
        {
            updateBuffer();
            if(updateCollide(direction, vecCollideObjects) == 0)
            {
                characterShape.move(0, 1);
            }
        }
    }
    if(direction == "left")
    {
        for(int i = 0; i < speed; i++)
        {
            updateBuffer();
            if(updateCollide(direction, vecCollideObjects) == 0)
            {
                characterShape.move(-1, 0);
            }
        }
    }
    if(direction == "right")
    {
        for(int i = 0; i < speed; i++)
        {
            updateBuffer();
            if(updateCollide(direction, vecCollideObjects) == 0)
            {
                characterShape.move(1, 0);
            }
        }
    }
}

void character::updateBuffer()
{
    bufferTop.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y - 1));
    bufferBottom.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y + characterShape.getSize().y));
    bufferLeft.setPosition(sf::Vector2f(characterShape.getPosition().x - 1, characterShape.getPosition().y));
    bufferRight.setPosition(sf::Vector2f(characterShape.getPosition().x  + characterShape.getSize().x, characterShape.getPosition().y));
}

int character::updateCollide(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects)
{
    if(direction == "up")
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            for(int j = 0; j < vecCollideObjects[i].size(); j++)
            {
                if(bufferTop.getGlobalBounds().intersects(vecCollideObjects[i][j].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    if(direction == "down")
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            for(int j = 0; j < vecCollideObjects[i].size(); j++)
            {
                if(bufferBottom.getGlobalBounds().intersects(vecCollideObjects[i][j].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    if(direction == "left")
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            for(int j = 0; j < vecCollideObjects[i].size(); j++)
            {
                if(bufferLeft.getGlobalBounds().intersects(vecCollideObjects[i][j].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    if(direction == "right")
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            for(int j = 0; j < vecCollideObjects[i].size(); j++)
            {
                if(bufferRight.getGlobalBounds().intersects(vecCollideObjects[i][j].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
}
