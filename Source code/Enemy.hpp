#include "tools_for_army.hpp"
#include "Unit_Of_Dwarve.h"
#include "Unit_Of_Elf.h"
#include "Unit_Of_Men.h"
#include "Factory_Of_Dwarves.hpp"
#include "Factory_Of_Elf.hpp"
#include "Factory_Of_Men.hpp"
#include "composite_unit.hpp"
#include "Army_builder.hpp"

class Enemy {
public:
    Enemy() {
        Men_army_builder men_army;
        warrior = dir.createArmy(men_army, 1000, 1000, 1000);
    }

    int get_power_army(){
        return warrior->get_power_attack();
    }

private:
    Director dir;
    Army* warrior;
};