#ifndef GARAGE_H
#define GARAGE_H
#include "Car.h"
#include "Turret.h"

class Garage{
    public:
        Garage(TextureManager &_manager);
        Turret *getTurret(int i);
        Car *getCar(int i);
        std::vector<Car*> &getCars();
        virtual ~Garage();
    private:
        void setNormalCar(TextureManager &textures);
        void setConvertible(TextureManager &textures);
        void setPickup();
        std::vector<Turret*> _turrets;
        std::vector<Turret*>::iterator _turretIterator;
        std::vector<Car*> _cars;
        std::vector<Car*>::iterator _carIterator;
};

#endif // GARAGE_H
