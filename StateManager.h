#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
    enum ID{
        GAME
    };
class State;
class StateManager{
    public:
        //Add a state to the state manager
        void addState(State *_state,ID _id);
        //Bring the specified state to the front
        void setCurrentState(ID);
        //Return the front state
        State *getCurrentState();
        //Remove a state from the state manager
        void removeState(ID _id);
        //Empty the manager of all states
        void emptyQueue();
        virtual ~StateManager();
    private:
        State *_currentState;
        std::map<ID,State*> _states;
        std::map<ID,State*>::iterator _stateIterator;

};

#endif // STATEMANAGER_H
