#ifndef CAROBJECT_H
#define CAROBJECT_H
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Car.h"

class CarObject{
    public:
        CarObject(Car *car);
        //Return living state
        bool getAlive();
        //Return collision state
        bool collidingWith(CarObject *car);
        void render(sf::RenderWindow *_window);
        //Render the health bar
        void update();
        //Update all variables
        void updateVariables();
        //Knock the car accordingly
        void updateKnockback();
        //Displace the car based on the x/y variables
        void displace(float x,float y);

        void setPosition(sf::Vector2f pos);
        void setPosition(float x, float y);

        sf::Vector2f getSize();
        void setKnockback(float x, float y);
        void setKnockbackX(float i);
        void setKnockbackY(float i);
        //Set the goal that the car's rotation
        void setRotationGoal(float i);
        sf::Vector2f getPosition();
        sf::FloatRect getBounds();
        sf::Vector2f getCorner(int crnr);
        void addHealth(float i);
        void removeHealth(float i);
        //Remove all of the car's health
        void destroy();
        float getHealth();
        sf::Vector2f getPower();
        void increasePower(float x, float y);
        void decreasePower(float x, float y);
        void increasePower(sf::Vector2f pow);
        void decreasePower(sf::Vector2f pow);
        //Make the car invincible for a set duration of time
        void setInvincible(float time);
        virtual ~CarObject();
        CarSettings settings;
    private:
        //Car object
        Car *_car;
        sf::Sprite *_sprite = new sf::Sprite;
        sf::Vector2f _position;
        sf::Vector2f _size;
        //Vertices for the car
        sf::Vector2f _corners[4];
        //Bounding box
        sf::FloatRect _bounds;
        sf::Vector2f _power;
        //A set position that the car will automatically go to
        sf::Vector2f _knockback;
        //The limit to how much to car is going to rotate
        float _rotationGoal = 0;
        float _health = 300;
        bool _alive = true;
        bool _invincible = false;

};

#endif // CAROBJECT_H
