/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#ifndef JETTROID
#define JETTROID
#include "Transformer.h"
#include <string>

class Jettroid : public Transformer {
public:
    virtual void trade();
    void Fight() override;

    int getMoney();
    void setMoney(int money);
    bool getIsRich();
    void setIsRich(bool isRich);

    Jettroid(std::string name, int level, int strength, int ammo, Engine*eng, int money, bool isRich);
    Jettroid();
    void print(std::ostream& os) const override;

private:
    int _money;
    bool _isRich;
};

#endif
