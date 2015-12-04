#include "StateManager.h"

void StateManager::addState(State *state,ID id){
    _states.insert(std::make_pair(id,state));
}
void StateManager::setCurrentState(ID id){
    _currentState = _states[id];
}
State *StateManager::getCurrentState(){
    return _currentState;
}
void StateManager::removeState(ID id){
    _states.erase(id);
}
void StateManager::emptyQueue(){
    //Loop through all the states
    for(_stateIterator = _states.begin();_stateIterator != _states.end();++_stateIterator){
        if((*_stateIterator).second != NULL)
            //Delete all state pointers
            delete (*_stateIterator).second;
    }
    //Clear the queue
    _states.clear();
}
StateManager::~StateManager(){
    //Clean queuef
    emptyQueue();
}
