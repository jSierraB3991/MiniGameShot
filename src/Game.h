#include <SFML/Graphics.hpp>

using namespace sf;

class Game
{

public:
    Game(Vector2f resolution, std::string title);
    void gameLoop();
    void chargeGraphics();

private:
    RenderWindow* window;
    
    Sprite* mosters[3];
    Sprite* background;
    
    bool isGameOver;
    int fps;
    
};