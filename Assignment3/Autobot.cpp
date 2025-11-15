#include "Autobot.h"
#include <iostream>

void Autobot::scan() {};

int Autobot::getAutobotIndex() {
    return _autobotIndex;
};
void Autobot::setAutobotIndex(int autobotIndex) {
    _autobotIndex = autobotIndex;
};
bool Autobot::getIsPrime() {
    return _isPrime;
};
void Autobot::setIsPrime(bool isPrime) {
    _isPrime = isPrime;
};
Autobot::Autobot(std::string name, int level, int strength, int ammo, Engine eng, int autobotIndex, bool isPrime)
    : Transformer(name, level, strength, ammo, eng),
    _autobotIndex(autobotIndex),
    _isPrime(isPrime) {}
