#include "CarObject.h"

CarObject::CarObject(Car *car){
    //Initialize car
    _car = car;
    //Initialize settings
    settings = _car->settings;
    //Set up texture
    _sprite->setTexture(_car->getTexture());
    //Set up bounding box
    _bounds = _sprite->getGlobalBounds();
    //Initialize size
    _size = sf::Vector2f(_sprite->getLocalBounds().width,_sprite->getLocalBounds().height);
}

bool CarObject::collidingWith(CarObject *car){
    //Check if car is intersecting with another car
    if(_bounds.intersects(car->_bounds)){
        return true;
    }else{
        return false;
    }
}

void CarObject::update(){
    //Tell the program if the car is alive
    if(_health < 0){
        _alive = false;
    }else{
        _alive = true;
    }
    updateVariables();
    updateKnockback();
    if(_alive){
        //Re-initialize corners
        _corners[0] = sf::Vector2f(_bounds.left,_bounds.top);
        _corners[1] = sf::Vector2f(_bounds.width + _bounds.left,_bounds.top);
        _corners[2] = sf::Vector2f(_bounds.width + _bounds.left,_bounds.height + _bounds.top);
        _corners[3] = sf::Vector2f(_bounds.left,_bounds.height + _bounds.top);
    }
}

void CarObject::updateVariables(){
    _position = _sprite->getPosition();
    _bounds = _sprite->getGlobalBounds();
    _size = sf::Vector2f(_bounds.width,_bounds.height);
}

void CarObject::updateKnockback(){
    //Knock the car to the right if hit
    if(_knockback.x > 0){
        _sprite->move(1,0);
        --_knockback.x;
    //Knock the car to the left if hit
    }else if(_knockback.x < 0){
        _sprite->move(-1,0);
        ++_knockback.x;
    //Knock the car back if hit
    }if(_knockback.y > 0){
        _sprite->move(0,1);
        --_knockback.y;
    //Knock the car forward if hit
    }else if(_knockback.y < 0){
        _sprite->move(0,-1);
        ++_knockback.y;
    }
}

void CarObject::render(sf::RenderWindow *window){
    window->draw(*_sprite);
}

void CarObject::displace(float x, float y){
    _sprite->move(x,y);
}

void CarObject::setPosition(sf::Vector2f pos){
    _sprite->setPosition(pos);
}
void CarObject::setPosition(float x, float y){
    setPosition(sf::Vector2f(x,y));
}

sf::Vector2f CarObject::getPosition(){
    return _position;
}

sf::FloatRect CarObject::getBounds(){
    return _bounds;
}

sf::Vector2f CarObject::getCorner(int crnr){
    //Return specified corner
    return _corners[crnr];
}

sf::Vector2f CarObject::getPower(){
    return _power;
}

void CarObject::increasePower(float x, float y){
    _power+=sf::Vector2f(x,y);
}

void CarObject::decreasePower(float x, float y){
    _power-=sf::Vector2f(x,y);
}

void CarObject::increasePower(sf::Vector2f pow){
    _power += pow;
}

void CarObject::decreasePower(sf::Vector2f pow){
    _power -= pow;
}

void CarObject::addHealth(float i){
    _health+=i;
}

void CarObject::removeHealth(float i){
    _health-=i;
}

void CarObject::destroy(){
    _alive = false;
}

void CarObject::setKnockback(float x, float y){
    _knockback = sf::Vector2f(x,y);
}

void CarObject::setKnockbackX(float i){
    _knockback.x = i;
}

void CarObject::setKnockbackY(float i){
    _knockback.y = i;
}

void CarObject::setRotationGoal(float i){
    _rotationGoal = i;
}

float CarObject::getHealth(){
    return _health;
}

bool CarObject::getAlive(){
    return _alive;
}

sf::Vector2f CarObject::getSize(){
    return _size;
}

CarObject::~CarObject(){
    delete _car;
    delete _sprite;
}
