//#include "inc/common.h"
#include "../inc/collideObject.h"

collideObject::collideObject(sf::Vector2f objectSize, sf::Vector2f objectPos, sf::Color objectCol)
{
    objectShape.setSize(objectSize);
    objectShape.setPosition(objectPos);
    objectShape.setFillColor(objectCol);
}

sf::RectangleShape collideObject::getObject()
{
    return objectShape;
}
