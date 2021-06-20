#include <SFML/Graphics.hpp>
#include "iostream"

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
    
    Sprite* sprtMosters[3];
    Sprite* sprtBackground;
    Sprite* sprtMira;

    Event* event;

    bool isGameOver;
    int fps;
};