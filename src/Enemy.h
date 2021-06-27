#include <SFML/Graphics.hpp>
#include "iostream"

class Enemy{

public:
    Enemy(sf::Vector2f position);
    sf::Sprite getSprite();

private:
    sf::Sprite* sprEnemy;
};