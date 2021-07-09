#include <SFML/Graphics.hpp>
#include "iostream"

class Enemy{

public:
    Enemy(sf::Vector2f position);
    sf::Sprite getSprite();
    float getSeconds();

private:
    sf::Sprite* sprEnemy;
    sf::Clock *clock;
    sf::Time *time;
};