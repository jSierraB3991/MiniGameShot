#include "Game.h"

Game::Game(Vector2f resolution, std::string title)
{
    this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
    this->isGameOver = false;
    this->fps = 60;
    this->window->setFramerateLimit(fps);

    this->gameLoop();
} 

void Game::gameLoop()
{
    while (!this->isGameOver)
    {
        this->window->clear();

        this->window->display();
    }
    
}

void Game::chargeGraphics()
{

}