/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#ifndef AUTOBOT
#define AUTOBOT
#include "Transformer.h"
#include <string>

class Autobot : public Transformer {
public:
    void scan();

    int getAutobotIndex();
    void setAutobotIndex(int autobotIndex);
    bool getIsPrime();
    void setIsPrime(bool isPrime);

    Autobot(std::string name, int level, int strength, int ammo, Engine* eng, int autobotIndex, bool isPrime);

private:
    int _autobotIndex;
    bool _isPrime;
};

#endif
