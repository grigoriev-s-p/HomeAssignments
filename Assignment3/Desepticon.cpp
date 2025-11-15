#include "Desepticon.h"
#include <iostream>

void Desepticon::destroy() {};

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
Desepticon::Desepticon(std::string name, int level, int strength, int ammo, Engine eng, int DesepticonIndex, bool isEvil)
    : Transformer(name, level, strength, ammo, eng),
    _DesepticonIndex(DesepticonIndex),
    _isEvil(isEvil) {}



