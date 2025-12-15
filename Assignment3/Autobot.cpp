/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Autobot.h"
#include <iostream>

void Autobot::scan() {
    std::cout << "Autobot scan\n";
}
void Autobot::Fight() {
    std::cout << "Autobot Fight\n";
}
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
Autobot::Autobot(std::string name, int level, int strength, int ammo, Engine* eng, int autobotIndex, bool isPrime)
    : Transformer(name, level, strength, ammo, eng),
    _autobotIndex(autobotIndex),
    _isPrime(isPrime) {}
Autobot::Autobot()
    : Transformer("DefaultAutobot", 1, 50, 10, nullptr), 
    _autobotIndex(0), _isPrime(false) {
}
void Autobot::print(std::ostream& os) const {
    Transformer::print(os);
}