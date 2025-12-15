/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * fourth task
*/
#ifndef DESEPTICON
#define DESEPTICON
#include "Transformer.h"
#include <string>

class Desepticon : public Transformer {
public:
    virtual void destroy();

    void Fight() override;

    int getDesepticonIndex();
    void setDesepticonIndex(int DesepticonIndex);
    bool getIsEvil();
    void setIsEvil(bool isEvil);

    Desepticon(std::string name, int level, int strength, int ammo, Engine* eng, int DesepticonIndex, bool isEvil);
    Desepticon();
    void print(std::ostream& os) const override;

private:
    int _DesepticonIndex;
    bool _isEvil;
};

#endif
