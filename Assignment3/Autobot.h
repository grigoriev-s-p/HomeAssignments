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
    virtual void scan();

    void Fight() override;

    int getAutobotIndex();
    void setAutobotIndex(int autobotIndex);
    bool getIsPrime();
    void setIsPrime(bool isPrime);

    Autobot(std::string name, int level, int strength, int ammo, Engine* eng, int autobotIndex, bool isPrime);
    Autobot();
    void print(std::ostream& os) const override;

private:
    int _autobotIndex;
    bool _isPrime;
};

#endif
