#include <iostream>
#include "Army_builder.hpp"
#include "tools_for_army.hpp"
#include "composite_unit.hpp"

using namespace std;

int main() {
    //-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//
    //используем компоновщик для армии людей
    // Армия людей состоит из 4-х легионов
    Composite_Unit_of_men *army_men = new Composite_Unit_of_men;
    for (int i = 0; i < 4; ++i)
        army_men->addUnit(create_legion_men(1000, 500, 300));

    cout << "Men army damaging strength is "
         << army_men->getStrength() << endl << endl;
    delete army_men;

    //-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//
    //используем компоновщик для армии эльфов
    // Армия эльфов состоит из 4-х легионов
    Composite_Unit_of_elfs *army_elfs = new Composite_Unit_of_elfs;
    for (int i = 0; i < 4; ++i)
        army_elfs->addUnit(create_legion_elfs(1000, 500, 300));

    cout << "Elfs army damaging strength is "
         << army_elfs->getStrength() << endl << endl;
    delete army_elfs;

    //-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-//
    //используем компоновщик для армии гномов
    // Армия гномов состоит из 4-х легионов
    Composite_Unit_of_dwarves *army_dwarves = new Composite_Unit_of_dwarves;
    for (int i = 0; i < 4; ++i)
        army_dwarves->addUnit(create_legion_dwarves(1000, 500, 300));

    cout << "Dwarves army damaging strength is "
         << army_dwarves->getStrength() << endl << endl;
    delete army_dwarves;
    return 0;
}