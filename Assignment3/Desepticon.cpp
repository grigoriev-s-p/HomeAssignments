/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Desepticon.h"
#include <iostream>

void Desepticon::destroy() {
    std::cout << "Desepticon destroy\n";
};

void Desepticon::Fight() {
    std::cout << "Desepticon Fight\n";
}

int Desepticon::getDesepticonIndex() {
    return _DesepticonIndex;
};
void Desepticon::setDesepticonIndex(int DesepticonIndex) {
    _DesepticonIndex = DesepticonIndex;
};
bool Desepticon::getIsEvil() {
    return _isEvil;
};
void Desepticon::setIsEvil(bool isEvil) {
    _isEvil = isEvil;
};
Desepticon::Desepticon(std::string name, int level, int strength, int ammo, Engine* eng, int DesepticonIndex, bool isEvil)
    : Transformer(name, level, strength, ammo, eng),
    _DesepticonIndex(DesepticonIndex),
    _isEvil(isEvil) {}
Desepticon::Desepticon()
    : Transformer("DefaultAutobot", 1, 50, 10, nullptr),
    _DesepticonIndex(0), _isEvil(true) {
}
void Desepticon::print(std::ostream& os) const {
    Transformer::print(os);
}

