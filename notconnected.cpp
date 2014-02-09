#include "notconnected.h"

NotConnected::NotConnected() : QException()
{
}

void NotConnected::raise()
{
    throw this;
}
