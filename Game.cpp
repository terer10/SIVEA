#include "Game.h"

sf::RenderWindow *Game::_window;
Game::Game(){
    //Initialize window
    _window = new sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT,32),"The Game I'll Most Likely Never Finish");
    //Load textures
    loadTextures();
    //Load the font onto the global font manager
    _fonts.load("res/BGOTHL.ttf",Fonts::FONT);
    //Initialize the road
    _level = new Level(_textures,_fonts);
    //Add the GAME state to the global State Manager
    _stateManager->addState(_level,GAME);
    //Set the state to the GAME state
    _stateManager->setCurrentState(GAME);
    //Start the game loop
    run();
}
void Game::update(){
    _stateManager->getCurrentState()->update();
}
void Game::render(){
    _window->clear(sf::Color::White);
    _stateManager->getCurrentState()->render(_window);
    _window->display();
}
void Game::processEvents(){
    sf::Event e;
    while(_window->pollEvent(e)){
        if(e.type == sf::Event::Closed){
            _window->close();
        }
    }
}
void Game::run(){
    sf::Clock _clock;
    sf::Time _delta = sf::Time::Zero;
    const sf::Time UPDATE_TIME = sf::seconds(1.0f/60.0f);
    while(_window->isOpen()){
        _delta += _clock.restart();
        processEvents();
        if(_delta > UPDATE_TIME){
            update();
            _delta -= UPDATE_TIME;
        }
        render();
    }
}
void Game::loadTextures(){
    std::clog << "Loading textures..." << std::endl;
    _textures.load("res/Cars/car.png",Textures::CAR);
    _textures.load("res/Cars/convertable.png",Textures::SPORTS_CAR);
    _textures.load("res/road.png",Textures::ROAD);
    _textures.load("res/turret1.png",Textures::TURRET);
}
Game::~Game(){
    delete _window;
    //Deletes all of the states
    delete _stateManager;
}
