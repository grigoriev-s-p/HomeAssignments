/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Jettroid.h"
#include <iostream>

void Jettroid::trade() {};

int Jettroid::getMoney() {
    return _money;
};
void Jettroid::setMoney(int money) {
    _money = money;
};
bool Jettroid::getIsRich() {
    return _isRich;
};
void Jettroid::setIsRich(bool isRich) {
    _isRich = isRich;
};
Jettroid::Jettroid(std::string name, int level, int strength, int ammo, Engine eng, int money, bool isRich)
    : Transformer(name, level, strength, ammo, eng),
    _money(money),
    _isRich(isRich) {}



