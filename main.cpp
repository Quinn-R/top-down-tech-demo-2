#include "inc/common.h"

class collideObject
{
private:
    
    sf::RectangleShape objectShape;
    
public:
    
    collideObject(sf::Vector2f objectSize, sf::Vector2f objectPos, sf::Color objectCol)
    {
        objectShape.setSize(objectSize);
        objectShape.setPosition(objectPos);
        objectShape.setFillColor(objectCol);
    }
    
    sf::RectangleShape getObject()
    {
        return objectShape;
    }
    
};

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
    
    sf::RectangleShape getCharacter()
    {
        return characterShape;
    }
    
    void charMove(std::string direction, std::vector<collideObject> vecCollideObjects)
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
    
    void updateBuffer()
    {
        bufferTop.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y - 1));
        bufferBottom.setPosition(sf::Vector2f(characterShape.getPosition().x, characterShape.getPosition().y + characterShape.getSize().y));
        bufferLeft.setPosition(sf::Vector2f(characterShape.getPosition().x - 1, characterShape.getPosition().y));
        bufferRight.setPosition(sf::Vector2f(characterShape.getPosition().x  + characterShape.getSize().x, characterShape.getPosition().y));
    }
    
    int updateCollide(std::string direction, std::vector<collideObject> vecCollideObjects)
    {
        if(direction == "up")
        {
            for(int i = 0; i < vecCollideObjects.size(); i++)
            {
                if(bufferTop.getGlobalBounds().intersects(vecCollideObjects[i].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
            return 0;
        }
        if(direction == "down")
        {
            for(int i = 0; i < vecCollideObjects.size(); i++)
            {
                if(bufferBottom.getGlobalBounds().intersects(vecCollideObjects[i].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
            return 0;
        }
        if(direction == "left")
        {
            for(int i = 0; i < vecCollideObjects.size(); i++)
            {
                if(bufferLeft.getGlobalBounds().intersects(vecCollideObjects[i].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
            return 0;
        }
        if(direction == "right")
        {
            for(int i = 0; i < vecCollideObjects.size(); i++)
            {
                if(bufferRight.getGlobalBounds().intersects(vecCollideObjects[i].getObject().getGlobalBounds()))
                {
                    return 1;
                }
            }
            return 0;
        }
    }
    
};

class sfmlLoop
{
private:
    
    sf::RenderWindow window;
    sf::Event event;
    
    
    character character1;
    std::vector<collideObject> vecCollideObjects;
    
public:
    
    sfmlLoop() : 
    character1(4, sf::Vector2f(32, 32), sf::Color::Black, sf::Color::Green)
    {
        window.create(sf::VideoMode(1680, 1050), "SFML works!"/*, sf::Style::None*/);
        window.setFramerateLimit(60);
        
        setCollideObjects(40);
    }
    
    void sfml()
    {

        while (window.isOpen())
        {
            buttonPressed();
            
            while (window.pollEvent(event))
            {
                events();
            }
            windowUpdate();
        }
    }
    
    void buttonPressed()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            character1.charMove("up", vecCollideObjects);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            character1.charMove("down", vecCollideObjects);
        }
        //
        //
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            character1.charMove("left", vecCollideObjects);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            character1.charMove("right", vecCollideObjects);
        }
    }

    void events()
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    
    void windowUpdate()
    {
        window.clear(sf::Color::White);
        window.draw(character1.getCharacter());
        drawCollideObjects();
        window.display();
    }
    
    void setCollideObjects(int count)
    {
        //wall(sf::Vector2f wallSize, sf::Vector2f wallPos, sf::Color wallCol)
        for(int i = 0; i < count; i++)
        {
            vecCollideObjects.push_back(collideObject(sf::Vector2f(32, 32), sf::Vector2f(512, 512), sf::Color::Blue));
        }
    }
    
    void drawCollideObjects()
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            window.draw(vecCollideObjects[i].getObject());
        }
    }
};

int main()
{
    sfmlLoop sfmlL;
    
	sfmlL.sfml();
	
	return 0;
}
