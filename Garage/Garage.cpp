#include "Garage.h"

Garage::Garage(TextureManager &textures){
    TurretSettings _turret1;
    _turret1.firerate = 1;
    _turret1.torque = 3;
    _turrets.push_back(new Turret(textures,_turret1));
    //Car
    setNormalCar(textures);
    //Sports Car
    setConvertible(textures);

}
void Garage::setNormalCar(TextureManager &textures){
    CarSettings _car;
    _car.name = "Nothing Special";
    _car.speed = 5;
    _car.handling = 3;
    _cars.push_back(new Car(_car,_turrets[0],textures,Textures::CAR));
}
void Garage::setConvertible(TextureManager &textures){
    CarSettings convertible;
    convertible.name = "Beach Convertible";
    convertible.speed = 5;
    convertible.acceleration = 2;
    convertible.handling = 1;
    _cars.push_back(new Car(convertible,_turrets[0],textures,Textures::SPORTS_CAR));
}
Turret *Garage::getTurret(int i){
    return _turrets[i];
}
Car *Garage::getCar(int i){
    return _cars[i];
}
std::vector<Car*> &Garage::getCars(){
    return _cars;
}
Garage::~Garage(){
    for(_carIterator = _cars.begin();_carIterator != _cars.end();++_carIterator)
        delete (*_carIterator);
    for(_turretIterator = _turrets.begin();_turretIterator != _turrets.end();++_turretIterator)
        delete (*_turretIterator);
}
