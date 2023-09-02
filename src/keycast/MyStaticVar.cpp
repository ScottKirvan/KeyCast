#include "MyStaticVar.h"

bool keepMouseWheelUp = false;
bool keepMouseWheelDown = false;

bool MyStaticVar::skipMouseWheelUp()
{
    if (keepMouseWheelUp)
        return true;
    keepMouseWheelUp = true;
    keepMouseWheelDown = false;
    return false;
}

bool MyStaticVar::skipMouseWheelDown()
{
    if (keepMouseWheelDown)
        return true;
    keepMouseWheelUp = false;
    keepMouseWheelDown = true;
    return false;
}

void MyStaticVar::otherOperation()
{
    keepMouseWheelUp = false;
    keepMouseWheelDown = false;
}
