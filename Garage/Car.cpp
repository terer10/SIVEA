#include "Car.h"

Car::Car(CarSettings _settings,Turret *_turret,TextureManager &_textures,Textures::ID _id){
    Car::_turret = _turret;
    Car::settings = _settings;
    _texture = _textures.get(_id);
}
sf::Texture &Car::getTexture(){
    return _texture;
}
Car::~Car(){
    delete _turret;
}
