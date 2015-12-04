#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"
#include "../State.h"
#include "../Player/Player.h"
#include "../Garage/Car.h"
#include "../Garage/Garage.h"

class Level : public State{
    public:
        Level(TextureManager &_textures,FontManager &fmanager);
        void update();
        void render(sf::RenderWindow *_window);
        void setupControllers();
        void loadPlayers(TextureManager &_texture,FontManager &fmanager);
        virtual ~Level();
    private:
        Garage *_garage;
        sf::Texture _texture;
        sf::Sprite *_roads[2];
        std::vector<Player*> _players;
        std::vector<Player*>::iterator _playerIterator;
        Controls _controller1;
        Controls _controller2;
};

#endif // LEVEL_H
