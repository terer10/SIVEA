#include "Level.h"

Level::Level(TextureManager &_textures,FontManager &fmanager){
    //Add controllers to the players
    setupControllers();
    loadPlayers(_textures,fmanager);
    //Setup road texture
    _texture = _textures.get(Textures::ROAD);
    //Assign texture to the roads
    for(int i = 0;i < 2;i++){
        _roads[i] = new sf::Sprite;
        _roads[i]->setTexture(_texture);
    }
    //Set the second road at the bottom
    _roads[1]->setPosition(0,-640);
}
void Level::update(){
    //Update the cars
    _players[0]->update(_players[1]->getCar());
    _players[1]->update(_players[0]->getCar());
    //Move the road
    for(int i = 0;i < 2;i++){
        _roads[i]->move(0,10);
        //Reset road position when off screen
        if(_roads[i]->getPosition().y > 640){
            _roads[i]->setPosition(0,-630);
        }
    }
}
void Level::render(sf::RenderWindow *_window){
    //Draw roads
    for(int i = 0;i < 2;++i){
        _window->draw(*_roads[i]);
    }
    //Draw cars
    for(_playerIterator = _players.begin();_playerIterator != _players.end();++_playerIterator){
        (*_playerIterator)->render(_window);
    }
}
void Level::setupControllers(){
    //Set up controller 1
    _controller1.up = sf::Keyboard::W;
    _controller1.down = sf::Keyboard::S;
    _controller1.left = sf::Keyboard::A;
    _controller1.right = sf::Keyboard::D;
    _controller1.shoot = sf::Keyboard::Z;
    _controller1.aimLeft = sf::Keyboard::Q;
    _controller1.aimRight = sf::Keyboard::E;
    //Set up controller 2
    _controller2.up = sf::Keyboard::Up;
    _controller2.down = sf::Keyboard::Down;
    _controller2.left = sf::Keyboard::Left;
    _controller2.right = sf::Keyboard::Right;
    _controller2.shoot = sf::Keyboard::Return;
}
void Level::loadPlayers(TextureManager &_textures,FontManager &fmanager){
    std::clog << "Loading players..." << std::endl;
    //Create the car garage
    _garage = new Garage(_textures);
    _players.push_back(new Player(100,320,new CarObject(_garage->getCar(0)),0,_controller1,fmanager));
    _players.push_back(new Player(380,320,new CarObject(_garage->getCar(1)),1,_controller2,fmanager));
}
 Level::~Level(){
    delete _roads[0];
    delete _roads[1];
    //Delete all the players
    for(_playerIterator = _players.begin();_playerIterator != _players.end();++_playerIterator){
        delete (*_playerIterator);
    }
}
