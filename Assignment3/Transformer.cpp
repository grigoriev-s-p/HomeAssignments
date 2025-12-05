/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#include "Transformer.h"
#include "TransformerModel.h"
#include "Engine.h"

void Transformer::Fire() {
    return;
}

void Transformer::Transform() {
    return;
}

void Transformer::setName(const std::string& name) {
    _name = name;
}
std::string Transformer::getName() {
    return _name;
}
void Transformer::setLevel(int level) {
    _level = level;
}
int Transformer::getLevel() {
    return _level;
}
void Transformer::setStrength(int strength) {
    _strength = strength;
}
int Transformer::getStrength() {
    return _strength;
}
void Transformer::setAmmo(int ammo) {
    _ammo = ammo;
}

int Transformer::getAmmo() {
    return _ammo;
}
void Transformer::setEnginePower(int power) {
    _engine->setPower(power);
}
int Transformer::getEnginePower() {
    return _engine->getPower();
}
void Transformer::setModel(std::string model) {
    _model.setModel(model);
}
std::string Transformer::getModel() {
    return _model.getModel();
}

Transformer::Transformer(std::string name, int level, int strength, int ammo, Engine* eng)
    : _name(name),
      _level(level),
      _strength(strength),
      _ammo(ammo),
      _engine(eng),
      _model("standart"){}

Transformer::~Transformer() {};
