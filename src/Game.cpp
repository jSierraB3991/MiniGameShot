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

    for (int i = 0; i < 4; i++) {
        this->slotsMonsters[i] = false;
        enemy[i] = NULL;
    }
    
    clock = new Clock;
    floatTime = 0;
    this->chargeGraphics();
    this->gameLoop();
} 

void Game::gameLoop()
{
    while (!this->isGameOver)
    {
        this->window->clear();
        *time = this->clock->getElapsedTime();
        this->display();
        this->processEvent();
        this->window->display();

        if(time->asSeconds() > 5 + floatTime){

            floatTime = time->asSeconds();
            int result = rand() % 100 + 1;
            if(result < 30){
                // No create Moster
            }
            else{
                auto slotOcupe = false;
                while(!slotOcupe)
                {
                    int numSlot = rand() % 3 + 0;
                    if(slotsMonsters[numSlot] == false){
                        slotsMonsters[numSlot] = true;
                        enemy[numSlot] = new Enemy({200.f * numSlot, 30});
                        slotOcupe = true;
                    }
                }
            }
        }
    }
    
}

void Game::display()
{
    this->window->draw(*sprtBackground);
    for (int i = 0; i < 4; i++) {
        if(enemy[i] != NULL){
            this->window->draw(enemy[i]->getSprite());
        }
    }
    this->window->draw(*sprtMira);
}

void Game::chargeGraphics()
{
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
}


void Game::processEvent()
{
    while (this->window->pollEvent(*this->event))
    {
        switch (this->event->type)
        {
        case Event::MouseMoved:
            this->sprtMira->setPosition((Vector2f)Mouse::getPosition(*this->window));
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