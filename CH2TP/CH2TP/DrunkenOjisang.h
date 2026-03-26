#pragma once
#include "Monster.h"
#include <string>
#include <random>

class DrunkenOjisang : public Monster
{
public:
    DrunkenOjisang();  

    void StartText() override;  
    void DeadText() override;   

private:
    void setStats(); 
};