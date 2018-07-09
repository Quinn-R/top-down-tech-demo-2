#ifndef SFMLLOOP_H
#define SFMLLOOP_H

#include "common.h"
#include "character.h"
//#include "collideObject.h"
#include "stickers.h"

class sfmlLoop
{
private:
    
    sf::RenderWindow window;
    sf::Event event;
    
    std::vector< std::vector<collideObject> > vecCollideObjects;
    std::vector<collideObject> vecBuilding1;
    std::vector<character> vecCharacter;
    
public:
    
    sfmlLoop();
    void sfml();
    void buttonPressed();
    void events();
    void windowUpdate();
    void setCharacterObjects(int count);
    void setCollideObjects(int count);
    void drawCharacter();
    void drawCollideObjects();
};

#endif
