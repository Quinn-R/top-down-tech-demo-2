#include "inc/common.h"

void sfml();

class character
{
private:
    
    int speed;
    
    //std::vector<>
    
    sf::RectangleShape characterShape;
    sf::RectangleShape bufferTop;
    sf::RectangleShape bufferBottom;
    sf::RectangleShape bufferLeft;
    sf::RectangleShape bufferRight;
    
public:
    
    character(int sp, sf::Vector2f charSize, sf::Color charCol, sf::Color bufCol)
    {
        
        speed = sp;
        
        characterShape.setSize(charSize);
        bufferTop.setSize(sf::Vector2f(characterShape.getSize().x, 1));
        bufferBottom.setSize(sf::Vector2f(characterShape.getSize().x, 1));
        bufferLeft.setSize(sf::Vector2f(1, characterShape.getSize().y));
        bufferRight.setSize(sf::Vector2f(1, characterShape.getSize().y));
        
        characterShape.setFillColor(charCol);
        bufferTop.setFillColor(bufCol);
        bufferBottom.setFillColor(bufCol);
        bufferLeft.setFillColor(bufCol);
        bufferRight.setFillColor(bufCol);
        
    }
    
    void move(std::string direction)
    {
        if(direction == "up")
        {
            for(int i = 0; i < speed; i++)
            {
                updateBuffer();
                //updateCollide(direction);
                characterShape.move(0, -1);
            }
        }
        if(direction == "down")
        {
            for(int i = 0; i < speed; i++)
            {
                updateBuffer();
                //updateCollide(direction);
                characterShape.move(0, 1);
            }
        }
        if(direction == "left")
        {
            for(int i = 0; i < speed; i++)
            {
                updateBuffer();
                //updateCollide(direction);
                characterShape.move(-1, 0);
            }
        }
        if(direction == "right")
        {
            for(int i = 0; i < speed; i++)
            {
                updateBuffer();
                //updateCollide(direction);
                characterShape.move(1, 0);
            }
        }
    }
    
    void updateBuffer()
    {
        bufferTop.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y - 1));
        bufferBottom.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y + characterShape.getSize().y));
        bufferLeft.setPosition(sf::Vector2f(characterShape.getPosition().x - 1, characterShape.getPosition().y));
        bufferRight.setPosition(sf::Vector2f(characterShape.getPosition().x  + characterShape.getSize().x, characterShape.getPosition().y));
    }
    
    /*int updateCollide(std::string direction)
    {
        if(direction == "up")
        {
            
        }
        if(direction == "down")
        {
            
        }
        if(direction == "left")
        {
            
        }
        if(direction == "right")
        {
            
        }
    }*/
    
};

int main()
{
	sfml();
	
	return 0;
}

void sfml()
{
    
}
