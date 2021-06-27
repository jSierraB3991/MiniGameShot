#include <SFML/Graphics.hpp>
#include "iostream"
#include "Enemy.h"

using namespace sf;

class Game
{

public:
    Game(Vector2f resolution, std::string title);
    void gameLoop();
    void chargeGraphics();
    void display();
    void processEvent();

private:
    RenderWindow* window;
    
    Sprite* sprtBackground;
    Sprite* sprtMira;

    Event* event;

    Clock* clock;
    Time* time;
    float floatTime;
    
    Enemy* enemy[4];

    bool isGameOver;
    bool slotsMonsters[4];
    int fps;
};