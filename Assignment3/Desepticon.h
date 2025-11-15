#ifndef DESEPTICON
#define DESEPTICON
#include "Transformer.h"
#include <string>

class Desepticon : public Transformer {
public:
    void destroy();

    int getDesepticonIndex();
    void setDesepticonIndex(int DesepticonIndex);
    bool getIsEvil();
    void setIsEvil(bool isEvil);

    Desepticon(std::string name, int level, int strength, int ammo, Engine eng, int DesepticonIndex, bool isEvil);

private:
    int _DesepticonIndex;
    bool _isEvil;
};

#endif
