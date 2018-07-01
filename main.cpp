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
    
    character(int sp, sf::Vector2f charSize, sf::Vector2f charPos, sf::Color charCol, sf::Color bufCol)
    {
        
        speed = sp;
        
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
    
    sf::RectangleShape getCharacter()
    {
        return characterShape;
    }
    
    void charMove(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects)
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
    
    int updateCollide(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects)
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
    
};

class sfmlLoop
{
private:
    
    sf::RenderWindow window;
    sf::Event event;
    
    std::vector< std::vector<collideObject> > vecCollideObjects;
    std::vector<collideObject> vecBuilding1;
    std::vector<character> vecCharacter;
    
public:
    
    sfmlLoop()
    {
        window.create(sf::VideoMode(1680, 1050), "SFML works!"/*, sf::Style::None*/);
        window.setFramerateLimit(60);
        
        setCharacterObjects(1);
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

    void events()
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    
    void windowUpdate()
    {
        window.clear(sf::Color::White);
        drawCollideObjects();
        drawCharacter();
        window.display();
    }
    
    void setCharacterObjects(int count)
    {
        //character(4, sf::Vector2f(32, 32), sf::Color::Black, sf::Color::Green);
        for(int i = 0; i < count; i++)
        {
            vecCharacter.push_back(character(4, sf::Vector2f(32, 32), sf::Vector2f(450, 450), sf::Color::Black, sf::Color::Green));
        }
    }
    
    void setCollideObjects(int count)
    {
        int x = 500, y = 500;
        
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
    
    void drawCharacter()
    {
        for(int i = 0; i < vecCharacter.size(); i++)
        {
            window.draw(vecCharacter[i].getCharacter());
        }
    }
    
    void drawCollideObjects()
    {
        for(int i = 0; i < vecCollideObjects.size(); i++)
        {
            for(int j = 0; j < vecCollideObjects[i].size(); j++)
            {
                window.draw(vecCollideObjects[i][j].getObject());
            }
        }
    }
};

int main()
{
    sfmlLoop sfmlL;
    
	sfmlL.sfml();
	
	return 0;
}
