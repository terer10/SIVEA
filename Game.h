#ifndef GAME_H
#define GAME_H
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ResourceManager.h"
#include "StateManager.h"
#include "Play/Level.h"
#include "Settings.h"
class Level;
class Game{
public:
    Game();
    virtual ~Game();
private:
    static sf::RenderWindow *_window;
    void loadTextures();
    void run();
    void processEvents();
    void update();
    void render();
    //Global state manager
    StateManager *_stateManager = new StateManager;
    TextureManager _tempTextures;
    FontManager _tempFonts;
    //Global texture manager
    TextureManager &_textures = _tempTextures;
    //Global font manager
    FontManager &_fonts = _tempFonts;
    //Start level
    Level *_level;
};

#endif // GAME_H
