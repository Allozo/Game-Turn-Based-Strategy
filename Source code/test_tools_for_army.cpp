#include "composite_unit.hpp"
#include "tools_for_army.hpp"

int main() {
    // тесты на объединение армий
    if (true) {
        Director dir;                                                          // создали класс распорядитель

        // проверка совммещения армии
        Dwarves_army_builder dwarves_builder;                                  // будем создавать армию гномов
        Army *dwarves_army_1 = dir.createArmy(dwarves_builder, 10, 10,
                                              5);     // создали базовый комлект войнов для гномов
        Army *dwarves_army_2 = dir.createArmy(dwarves_builder, 5, 10,
                                              5);      // создали базовый комлект войнов для гномов
        cout << "Dwarves army: " << endl;
        cout << "Sum attack: " << dwarves_army_1->get_power_attack() << endl;
        cout << "Sum attack: " << dwarves_army_2->get_power_attack() << endl;
        Army *dwarves_army = association_army(dir, dwarves_army_1, dwarves_army_2);
        cout << "Sum attack: " << dwarves_army->get_power_attack() << endl;


        cout << endl;


        Men_army_builder men_builder;                                       // будем создавать армию людей
        Army *men_army_1 = dir.createArmy(men_builder, 10, 10, 5);          // создали базовый комлект войнов для людей
        Army *men_army_2 = dir.createArmy(men_builder, 5, 10,
                                          5);             // создали базовый комлект войнов для людей
        cout << "Men army:" << endl;
        cout << "Sum attack: " << men_army_1->get_power_attack() << endl;
        cout << "Sum attack: " << men_army_2->get_power_attack() << endl;
        association_army(dir, men_army_1, men_army_2);
        Army *men_army = association_army(dir, men_army_1, men_army_2);
        cout << "Sum attack: " << men_army->get_power_attack() << endl;


        cout << endl;


        Elfs_army_builder elfs_builder;                                       // будем создавать армию эльфов
        Army *elfs_army_1 = dir.createArmy(elfs_builder, 10, 10,
                                           5);          // создали базовый комлект войнов для эльфов
        Army *elfs_army_2 = dir.createArmy(elfs_builder, 5, 10,
                                           5);             // создали базовый комлект войнов для эльфов
        cout << "Men army:" << endl;
        cout << "Sum attack: " << elfs_army_1->get_power_attack() << endl;
        cout << "Sum attack: " << elfs_army_2->get_power_attack() << endl;
        association_army(dir, elfs_army_1, elfs_army_2);
        Army *elfs_army = association_army(dir, elfs_army_1, elfs_army_2);
        cout << "Sum attack: " << elfs_army->get_power_attack() << endl;
    }
    if (true) {
        cout << endl << "Was before the battle: " << endl;
        Director dir;                                                       // создали класс распорядитель
        Dwarves_army_builder dwarves_builder;                               // будем создавать армию гномов
        Men_army_builder men_builder;                                       // будем создавать армию людей
        Army *dwarves_army_1 = dir.createArmy(dwarves_builder, 1000, 10, 5);  // создали базовый комлект войнов для гномов
        cout << "Sum attack first army: " << dwarves_army_1->get_power_attack() << endl;
        Army *men_army_1 = dir.createArmy(men_builder, 1000, 10, 5);          // создали базовый комлект войнов для людей
        cout << "Sum attack second army: " << men_army_1->get_power_attack() << endl;
        Army *new_army = battle_army(dir, dwarves_army_1, men_army_1);
        cout << "Sum attack after battle: " << new_army->get_power_attack() << endl;
    }
}

