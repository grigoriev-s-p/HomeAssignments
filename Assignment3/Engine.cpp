/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Engine.h"

Engine::Engine(int power) : _EnginePower(power) {};
void Engine::setPower(int power){
    _EnginePower=power;
};

int Engine::getPower(){
    return _EnginePower;
}



