#ifndef COLLIDEOBJECT_H
#define COLLIDEOBJECT_H

#include "common.h"

class collideObject
{
private:
    
    sf::RectangleShape objectShape;
    
public:
    
    collideObject(sf::Vector2f objectSize, sf::Vector2f objectPos, sf::Color objectCol);
    
    sf::RectangleShape getObject();
    
};

#endif
