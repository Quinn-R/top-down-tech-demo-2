#ifndef CHARACTER_H
#define CHARACTER_H

#include "common.h"
#include "collideObject.h"

class character
{
private:
    
    int speed;
    int isNpc;
    
    //std::vector<>
    
    sf::RectangleShape characterShape;
    sf::RectangleShape bufferTop;
    sf::RectangleShape bufferBottom;
    sf::RectangleShape bufferLeft;
    sf::RectangleShape bufferRight;
    
public:
    
    character(int sp, int isN, sf::Vector2f charSize, sf::Vector2f charPos, sf::Color charCol, sf::Color bufCol);

    sf::RectangleShape getCharacter();
    
    void charMove(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects);
    void updateBuffer();

    int updateCollide(std::string direction, std::vector< std::vector<collideObject> > vecCollideObjects);
    
};

#endif
