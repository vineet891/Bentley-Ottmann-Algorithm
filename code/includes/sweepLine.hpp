#pragma once

#include "eventTree.hpp"
#include "statusTree.hpp"
using namespace std;

class SweepLine
{
private:
    StatusTree status;
    EventTree event;

public:
    SweepLine();
    void iterator();
};