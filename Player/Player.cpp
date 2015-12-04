#include "Player.h"

Player::Player(int x, int y,CarObject *car,int index,Controls controller,FontManager &fmanager){
    _car = car;
    _index = index;
    _controller = controller;
    _car->setPosition(x,y);
    _font = fmanager.get(Fonts::FONT);
    initHealthBar();
    _health.setFont(_font);
    _health.setCharacterSize(14);
    _health.setColor(sf::Color::White);
    _health.setStyle(sf::Text::Italic|sf::Text::Bold);
}

void Player::update(CarObject *car){
    _car->update();
    updateText();
    //Sets healthbar size according to amount of health
    if(_car->getAlive()){
        _healthBar.setSize(sf::Vector2f(_car->getHealth()/2,10));
    }else{
        _healthBar.setSize(sf::Vector2f(0,10));
    }
    if(_car->getAlive()){
        handleCollision(car);
        handleMovements();
    }else{
        if(_velocity.y < 10){
            _velocity.y+=2;
        }
        _car->displace(_velocity.x,_velocity.y);
        //Leaves the car behind
    }
}
void Player::render(sf::RenderWindow *window){
    _car->render(window);
    window->draw(_healthBar);
    renderText(window);
}

void Player::handleMovements(){
    //Constantly move the car according to velocity values
    _car->displace(_velocity.x,_velocity.y);
    //Move forward
    if(sf::Keyboard::isKeyPressed(_controller.up)){
        accelerate();
    //Move backward
    }else if(sf::Keyboard::isKeyPressed(_controller.down)){
        decelerate();
    //Steady
    }else{
        if(_velocity.y > 0){
            _velocity.y-=0.5;
        }else if(_velocity.y < 0){
            _velocity.y+=0.5;
        }
    }
    ///STEERING
    //Turn left
    if(sf::Keyboard::isKeyPressed(_controller.left)){
        steerL();
    }else if(sf::Keyboard::isKeyPressed(_controller.right)){
        steerR();
    }else{
        //Steady
        _velocity.x = 0;
        if(_car->getPower().x > 0){
            _car->decreasePower(_car->getPower());
        }
        _steering = false;
        _steeringL = false;
        _steeringR = false;
    }

}
void Player::handleCollision(CarObject *car){
    handleWallCollision();
    //Collision detection
    if(_car->collidingWith(car)){
        ///RIGHT SIDE OF OV
        //Checks if the car is on the right side of the OV
        if(_car->getPosition().x >= car->getPosition().x){
            _car->setPosition(car->getPosition().x + car->getSize().x,_car->getPosition().y);
            //Checks if the car has more force
            if(_car->getPower().x > car->getPower().x){
                //Damage the opponent's vehicle
                car->removeHealth(_car->getPower().x/20);
                //Move the OV
                car->displace(-2,0);
            }
        ///LEFT SIDE OF OV
        //Checks if the car is on the left side of the OV
        }else if(_car->getPosition().x <= car->getPosition().x){
            _car->setPosition(car->getPosition().x - _car->getSize().x,_car->getPosition().y);
            //Checks if car has more force
            if(_car->getPower().x > car->getPower().x){
                //Damages the OV
                car->removeHealth(_car->getPower().x/20);
                //Move the OV
                car->displace(2,0);
            }
        }
        //Set velocity to 0 if colliding
        _velocity.y = 0;
        _velocity.x = 0;
        _colliding = true;
    }else{
        _colliding = false;
    }
}

void Player::handleWallCollision(){
    //Teleport the car to the opposite side if colliding with a wall
    if(_car->getCorner(1).x <= 0){
        _car->setPosition(WIDTH,_car->getPosition().y);
        //Remove all power
        _car->decreasePower(_car->getPower());
    //VICE VERSA TO ABOVE
    }else if(_car->getPosition().x >= WIDTH){
        _car->setPosition(-_car->getSize().x,_car->getPosition().y);
        _car->decreasePower(_car->getPower());
    }
}

void Player::renderText(sf::RenderWindow *window){
    window->draw(_health);
}
void Player::updateText(){
    //Create a string stream so that I can draw numbers as text
    std::stringstream hstr;
    //Add the health number to the stream
    hstr << _car->getHealth();
    //Set health text to the stream
    _health.setString(hstr.str());
}
CarObject*Player::getCar(){
    return _car;
}
//Steer left
void Player::steerL(){
    //Set all associated steering values to true
    _steering = true;
    _steeringL = true;
    //Move to the left if not colliding with OV
    if(_velocity.x > -_car->settings.speed && !_colliding){
        _velocity.x-=0.3;
    }
    //Prevent the velocity from going over the car's max
    if(_velocity.x < -_car->settings.speed){
        _velocity.x = -_car->settings.speed;
    }
    //Increase power
    _car->increasePower(1,0);
}
//Steer right
void Player::steerR(){
    //Set all associated steering values to true
    _steering = true;
    _steeringR = true;
    //Move to the right if not colliding with OV
    if(_velocity.x < _car->settings.speed && !_colliding){
        _velocity.x+=0.3;
    }
    //Prevent the velocity from going over the max
    if(_velocity.x > _car->settings.speed){
        _velocity.x = _car->settings.speed;
    }
}

void Player::accelerate(){
    //Slow the car's acceleration speed up if steering
    if(_steering){
        _velocity.y = -_car->settings.speed/2;
    }else{
        _velocity.y = -_car->settings.speed;
    }
    //Add power
    _car->increasePower(0,1);
}

void Player::decelerate(){
    //Slow the car's deceleration speeds
    if(_steering){
        _velocity.y = _car->settings.speed/2;
    }else{
        _velocity.y = _car->settings.speed;
    }
    //Remove power
    _car->decreasePower(0,1);
}

void Player::initHealthBar(){
    //Set color and size of health bar
    _healthBar.setFillColor(sf::Color(255,50,0,200));
    _healthBar.setSize(sf::Vector2f(_car->getHealth()/2,10));
    switch(_index){
        //If player one, set the health bar to the top-left corner
        case 0:
            _healthBar.setPosition(10,5);
        break;
        //If player two, set the health bar to the top-right corner
        case 1:
            _healthBar.setPosition(WIDTH - (10 + _healthBar.getSize().x),5);
        break;
    }
    //Set the health text position
    _health.setPosition(_healthBar.getPosition().x + _healthBar.getSize().x/2,0);
}
Player::~Player(){
    delete _car;
}
