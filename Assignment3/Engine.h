#ifndef ENGINE
#define ENGINE
#include <string>
class Engine {
public:
    Engine(int power);
    
    void setPower(int newPower);

    int getPower();

private:
    int _EnginePower;
};
#endif
