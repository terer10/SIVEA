#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"
#include "../Garage/Turret.h"
typedef struct{
    std::string name;
    float speed = 0;
    float handling = 0;
    float strength = 0;
    float acceleration = 0;
}CarSettings;
class Car{
    public:
        Car(CarSettings _settings,Turret *_turret,TextureManager &_manager,Textures::ID);
        sf::Texture &getTexture();
        CarSettings settings;
        ~Car();
    private:
        sf::Texture _texture;
        Turret *_turret;
};

#endif // CAR_H
