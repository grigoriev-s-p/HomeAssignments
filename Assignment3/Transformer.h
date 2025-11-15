#ifndef TRANSFORMER
#define TRANSFORMER
#include "Engine.h"
#include "TransformerModel.h"
#include <string>
#include <iostream>

class Transformer {
public:
    void Transform();
    void Fire();

    void setName(const std::string& name);
    std::string getName();
    void setLevel(int level);
    int getLevel();
    void setStrength(int strength);
    int getStrength();
    void setAmmo(int ammo);
    int getAmmo();
    void setEnginePower(int newPower);
    int getEnginePower();
    void setModel(std::string model);
    std::string getModel();

    Transformer(std::string name, int level, int strength, int ammo, Engine eng);
    ~Transformer();

private:
    std::string _name;
    int _level;
    int _strength;
    int _ammo;
    Engine _engine;
    TransformerModel _model;
};
#endif
