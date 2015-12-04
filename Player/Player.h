#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "../Garage/Car.h"
#include "../Garage/CarObject.h"
#include "../ResourceManager.h"
#include "Settings.h"
class Level;
typedef struct{
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key shoot;
    sf::Keyboard::Key aimLeft;
    sf::Keyboard::Key aimRight;
}Controls;
class Player{
    public:
        Player(int x,int y,CarObject *car,int index,Controls _controller,FontManager &fmanager);
        void update(CarObject *car);
        void render(sf::RenderWindow *window);
        CarObject *getCar();
        virtual ~Player();
    private:
        //Creates health bar
        void initHealthBar();
        //Handles all movement
        void handleMovements();
        void handleCollision(CarObject *_car);
        void handleWallCollision();
        //Updates all text on the screen
        void updateText();
        void renderText(sf::RenderWindow *window);
        //Movement functions
        void accelerate();
        void decelerate();
        void steerR();
        void steerL();
        //Car Object
        CarObject *_car;
        //Velocity that the car is traveling
        sf::Vector2f _velocity = sf::Vector2f(0,0);
        //Checks if the car is colliding with another car
        bool _colliding = false;
        Controls _controller;
        sf::Font _font;
        //Returns current steering state
        bool _steering = false;
        bool _steeringL = false;
        bool _steeringR = false;
        //Player number i.e: Player one
        int _index = 0;
        //Health bar rectangle
        sf::RectangleShape _healthBar;
        //Health text
        sf::Text _health;
};

#endif // PLAYER_H
