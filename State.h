#ifndef STATE_H
#define STATE_H
#include "StateManager.h"
class StateManager;
class State{
    public:
        virtual void update() = 0;
        virtual void render(sf::RenderWindow *_window) = 0;
};

#endif // STATE_H
