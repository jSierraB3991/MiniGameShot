#include "Game.h"

Game::Game(Vector2f resolution, std::string title)
{
    this->isGameOver = false;
    this->fps = 60;
    this->event = new Event;
    this->window = new RenderWindow(VideoMode(resolution.x, resolution.y), title);
    
    this->window->setFramerateLimit(fps);
    // No Show Mouse
    this->window->setMouseCursorVisible(false);

    this->chargeGraphics();
    this->gameLoop();
} 

void Game::gameLoop()
{
    while (!this->isGameOver)
    {
        this->window->clear();
        this->display();
        this->processEvent();
        this->window->display();
    }
    
}

void Game::display()
{
    this->window->draw(*sprtBackground);
    for (int i = 0; i < 3; i++)
    {
        this->window->draw(*this->sprtMosters[i]);
    }
    this->window->draw(*sprtMira);
}

void Game::chargeGraphics()
{
    std::string path = "images/enemy_";

    for (int i = 0; i < 3; i++)
    {
        Texture *txtMoster = new Texture;
        txtMoster->loadFromFile(path + std::to_string(i+1) + ".jpg");
        this->sprtMosters[i] = new Sprite;
        this->sprtMosters[i]->setTexture(*txtMoster);
        Vector2f sizeMonster(txtMoster->getSize().x, txtMoster->getSize().y);
        this->sprtMosters[i]->setScale(300.f / sizeMonster.x, 300.f / sizeMonster.y);
        
    }
    Texture* background = new Texture;
    background->loadFromFile("images/back.jpg");
    this->sprtBackground = new Sprite;
    this->sprtBackground->setTexture(*background);
    this->sprtBackground->setScale(
        (float)this->window->getSize().x/background->getSize().x,
        (float)this->window->getSize().y/background->getSize().y
    );
    
    Texture mira;
    mira.loadFromFile("images/mira.png");
    this->sprtMira = new Sprite;
    this->sprtMira->setTexture(mira);
    this->sprtMira->setOrigin(
        mira.getSize().x / 2.f,
        mira.getSize().y / 2.f
    );
    this->sprtMira->setScale(
        30.f/mira.getSize().x,
        30.f/mira.getSize().y
    );
    this->sprtMira->setColor(Color::White);
}


void Game::processEvent()
{
    while (this->window->pollEvent(*this->event))
    {
        switch (this->event->type)
        {
        case Event::MouseMoved:
            this->sprtMira->setPosition((Vector2f)Mouse::getPosition(*this->window));
            //std::cout << "x: " << Mouse::getPosition(*this->window).x << ", y: " << Mouse::getPosition(*this->window).y << std::endl;
            break;
        
        case Event::Closed:
            this->isGameOver = true;
            exit(0);
            break;

        default:
            break;
        }
    }
    
}