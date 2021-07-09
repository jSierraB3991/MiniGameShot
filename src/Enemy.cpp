#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy(sf::Vector2f position)
{
    int numEnemy = rand() % 3 + 1;

    std::string path = "images/enemy_" + std::to_string(numEnemy) + ".jpg";
    sf::Texture* txtEnemy = new sf::Texture;
    txtEnemy->loadFromFile(path);
    this->sprEnemy = new sf::Sprite;
    this->sprEnemy->setTexture(*txtEnemy);
    sf::Vector2f sizeMonster(txtEnemy->getSize().x, txtEnemy->getSize().y);
    this->sprEnemy->setScale(200.f / sizeMonster.x, 500.f / sizeMonster.y);


    this->sprEnemy->setPosition(position);
    this->clock = new sf::Clock;
    this->time = new sf::Time;
    *this->time = this->clock->getElapsedTime();
}

sf::Sprite Enemy::getSprite()
{
    return *this->sprEnemy;
}

float Enemy::getSeconds()
{
    *this->time = this->clock->getElapsedTime();
    return this->time->asSeconds();
}