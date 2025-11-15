#ifndef JETTROID
#define JETTROID
#include "Transformer.h"
#include <string>

class Jettroid : public Transformer {
public:
    void trade();

    int getMoney();
    void setMoney(int money);
    bool getIsRich();
    void setIsRich(bool isRich);

    Jettroid(std::string name, int level, int strength, int ammo, Engine eng, int money, bool isRich);

private:
    int _money;
    bool _isRich;
};

#endif
