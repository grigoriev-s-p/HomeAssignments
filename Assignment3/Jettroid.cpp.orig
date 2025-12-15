/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Jettroid.h"
#include <iostream>

void Jettroid::trade() {
    std::cout << "Jettroid trade\n";
}
void Jettroid::Fight() {
    std::cout << "Jettroid Fight\n";
}
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
Jettroid::Jettroid(std::string name, int level, int strength, int ammo, Engine* eng, int money, bool isRich)
    : Transformer(name, level, strength, ammo, eng),
    _money(money),
    _isRich(isRich) {}
Jettroid::Jettroid()
    : Transformer("DefaultAutobot", 1, 50, 10, nullptr),
    _money(0), _isRich(false) {
}
void Jettroid::print(std::ostream& os) const {
    Transformer::print(os);
}


