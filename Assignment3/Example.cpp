#include "Transformer.h"
#include "Engine.h"
#include "TransformerModel.h"
#include <iostream>

int main() {
    Engine coreEngine(100); 
    TransformerModel model("Default");
    Transformer autobot("Optimus", 50, 10, 5, coreEngine);
    autobot.setModel(model.getModel());
    std::cout << "Name: " << autobot.getName() << "\n";
    std::cout << "Level: " << autobot.getLevel() << "\n";
    std::cout << "Strength: " << autobot.getStrength() << "\n";
    std::cout << "Ammo: " << autobot.getAmmo() << "\n";
    std::cout << "Engine Power: " << autobot.getEnginePower() << "\n";
    std::cout << "Model: " << autobot.getModel() << "\n";
    autobot.setModel("Advanced");
    autobot.setEnginePower(200);
    std::cout << "\nAfter upgrade:\n";
    std::cout << "Engine Power: " << autobot.getEnginePower() << "\n";
    std::cout << "Model: " << autobot.getModel() << "\n";
    return 0;
}
