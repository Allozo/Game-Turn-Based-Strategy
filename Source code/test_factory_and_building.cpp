#include "Army_builder.hpp"
#include "Factory_Of_Men.hpp"
#include "Factory_Of_Dwarves.hpp"
#include "Factory_Of_Elf.hpp"

using namespace std;

int main() {
    /* Реализация через "фабрику" */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Men army:" << endl;
    Men_infantry_factory men_infantry;                          // Переменные для каждого юнита
    Men_arbalesters_factory men_arbalesters;
    Men_cavalry_factory men_cavalry;

    Factory_men *men_infant = &men_infantry;                    // Указатели на юнитов нужных типов
    Factory_men *men_arbalest = &men_arbalesters;
    Factory_men *men_cavalr = &men_cavalry;

    vector<Unit_of_men *> army_infantry_men;
    cout << "Number men infantry is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_men *infantry = foo(men_infant);                // Создали пехотинца
        army_infantry_men.emplace_back(infantry);               // добавили его в вектор
        infantry->info();                                       // вывели кого мы создали
    }
    vector<Unit_of_men *> army_arbalesters_men;
    cout << "Number men arbalesters is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_men *arbalesters = foo(men_arbalest);           // Создали арбалетчика
        army_arbalesters_men.emplace_back(arbalesters);         // добавили его в вектор
        arbalesters->info();                                    // вывели кого мы создали
    }
    vector<Unit_of_men *> army_cavalry_men;
    cout << "Number men cavalry is " << 5 << endl;
    for (int i = 0; i < 5; i++) {
        Unit_of_men *cavalry = foo(men_cavalr);                 // Создали кавалерия
        army_cavalry_men.emplace_back(cavalry);                 // добавили его в вектор
        cavalry->info();                                        // вывели кого мы создали
    }

    for (int i = 0; i < 10; i++) {                              // удаляем всех юнитов
        auto f = army_infantry_men[i];
        delete f;
    }
    for (int i = 0; i < 10; i++) {
        auto f = army_arbalesters_men[i];
        delete f;
    }
    for (int i = 0; i < 5; i++) {
        auto f = army_cavalry_men[i];
        delete f;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "and" << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Dwarves army:" << endl;
    Dwarves_infantry_factory dwarves_infantry;                  // Переменные для каждого юнита
    Dwarves_arbalesters_factory dwarves_arbalesters;
    Dwarves_cavalry_factory dwarves_cavalry;

    Factory_dwarves *dwarves_infant = &dwarves_infantry;        // Указатели на юнитов нужных типов
    Factory_dwarves *dwarves_arbalest = &dwarves_arbalesters;
    Factory_dwarves *dwarves_caval = &dwarves_cavalry;

    vector<Unit_of_dwarves *> army_infantry_dwarves;
    cout << "Number dwarves infantry is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_dwarves *infantry = foo(dwarves_infant);        // Создали пехотинца
        army_infantry_dwarves.emplace_back(infantry);           // добавили его в вектор
        infantry->info();                                       // вывели кого мы создали
    }
    vector<Unit_of_dwarves *> army_arbalesters_dwarves;
    cout << "Number dwarves arbalesters is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_dwarves *arbalesters = foo(dwarves_arbalest);   // Создали арбалетчика
        army_arbalesters_dwarves.emplace_back(arbalesters);     // добавили его в вектор
        arbalesters->info();                                    // вывели кого мы создали
    }
    vector<Unit_of_dwarves *> army_cavalry_dwarves;
    cout << "Number dwarves cavalry is " << 5 << endl;
    for (int i = 0; i < 5; i++) {
        Unit_of_dwarves *cavalry = foo(dwarves_caval);          // Создали кавалерия
        army_cavalry_dwarves.emplace_back(cavalry);             // добавили его в вектор
        cavalry->info();                                        // вывели кого мы создали
    }

    for (int i = 0; i < 10; i++) {                              // удаляем всех юнитов
        auto f = army_infantry_dwarves[i];
        delete f;
    }
    for (int i = 0; i < 10; i++) {
        auto f = army_arbalesters_dwarves[i];
        delete f;
    }
    for (int i = 0; i < 5; i++) {
        auto f = army_cavalry_dwarves[i];
        delete f;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "and" << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Elfs army:" << endl;
    Elfs_infantry_factory elfs_infantry;                        // Переменные для каждого юнита
    Elfs_arbalesters_factory elfs_arbalesters;
    Elfs_cavalry_factory elfs_cavalry;

    Factory_elfs *elfs_infant = &elfs_infantry;                 // Указатели на юнитов нужных типов
    Factory_elfs *elfs_arbalest = &elfs_arbalesters;
    Factory_elfs *elfs_caval = &elfs_cavalry;

    vector<Unit_of_elfs *> army_infantry_elfs;
    cout << "Number elfs infantry is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_elfs *infantry = foo(elfs_infant);              // Создали пехотинца
        army_infantry_elfs.emplace_back(infantry);              // добавили его в вектор
        infantry->info();                                       // вывели кого мы создали
    }
    vector<Unit_of_elfs *> army_arbalesters_elfs;
    cout << "Number elfs arbalesters is " << 10 << endl;
    for (int i = 0; i < 10; i++) {
        Unit_of_elfs *arbalesters = foo(elfs_arbalest);         // Создали арбалетчика
        army_arbalesters_elfs.emplace_back(arbalesters);        // добавили его в вектор
        arbalesters->info();                                    // вывели кого мы создали
    }
    vector<Unit_of_elfs *> army_cavalry_elfs;
    cout << "Number elfs cavalry is " << 5 << endl;
    for (int i = 0; i < 5; i++) {
        Unit_of_elfs *cavalry = foo(elfs_caval);                // Создали кавалерия
        army_cavalry_elfs.emplace_back(cavalry);                // добавили его в вектор
        cavalry->info();                                        // вывели кого мы создали
    }

    for (int i = 0; i < 10; i++) {                              // удаляем всех юнитов
        auto f = army_infantry_elfs[i];
        delete f;
    }
    for (int i = 0; i < 10; i++) {
        auto f = army_arbalesters_elfs[i];
        delete f;
    }
    for (int i = 0; i < 5; i++) {
        auto f = army_cavalry_elfs[i];
        delete f;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "else" << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /* Реализация через "строителя"*/
    Director dir;                                                        // создали класс распорядитель

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Men_army_builder men_builder;                                        // будем создавать армию людей
    Army *men_army = dir.createArmy(men_builder, 10, 10, 5);             // создали базовый комлект войнов для людей
    cout << "Men army:" << endl;
    men_army->info();                                                    // перекличка

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "and" << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Dwarves_army_builder dwarves_builder;                                // будем создавать армию гномов
    Army *dwarves_army = dir.createArmy(dwarves_builder, 10, 10, 5);     // создали базовый комлект войнов для гномов
    cout << "Dwarves army:" << endl;
    dwarves_army->info();                                                // перекличка

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl << "and  " << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Elfs_army_builder elfs_builder;                                      // будем создавать армию эльфов
    Army *elfs_army = dir.createArmy(elfs_builder, 10, 10, 5);           // создали базовый комлект войнов для эльфов
    cout << "Elfs army:" << endl;
    elfs_army->info();                                                   // перекличка

    return 0;
}
