#include <vector>
#include "Unit_Of_Dwarve.h"
#include "Unit_Of_Elf.h"
#include "Unit_Of_Men.h"
#include "Factory_Of_Dwarves.hpp"
#include "Factory_Of_Elf.hpp"
#include "Factory_Of_Men.hpp"
#include "composite_unit.hpp"
#include "Army_builder.hpp"


#pragma once

using namespace std;

class Game;

class Hero {
public:
    Hero() {
        cout << "Введите имя героя: ";
        cin >> name;
        cout << endl;
        value_treasure = 0;
        now_position = make_pair(1, 0);
    }

    virtual void info_race() = 0;

    virtual int get_power_army() = 0;

    void up_treasure() {
        value_treasure += treasure_game_1;
    };

    vector<int> get_number_unit(){
        return warriors->get_number_unit();
    }

    string get_name_hero(){
        return name;
    }

    int get_treasure() {
        return value_treasure;
    }

    pair<int, int> get_position_player() {
        return now_position;
    };

    void change_position(int x, int y) {
        now_position = make_pair(x, y);
    }

    void new_army(Army* arm) {

        warriors = arm;
    }

    Army* get_army() {
        return warriors;
    }

protected:
    string name;                                                // имя героя
    Director dir;                                               // создали класс распорядитель
    Army *warriors;                                             // армия героя
    int value_treasure;                                         // увеличение мощи сокровищем
    pair<int, int> now_position;                                // текущая позиция игрока (x, y)
};

class Elf_hero : public Hero {
public:
    Elf_hero(){
        Elfs_army_builder elfs_builder;
        warriors = dir.createArmy(elfs_builder, 10, 10, 5);     // создали базовый комлект войнов для эльфов
    }

    void info_race() override {
        cout << "Я эльф, дитя природы..." << endl;
    }

    int get_power_army() override {
        return warriors->get_power_attack();
    }
};

class Men_hero : public Hero {
public:
    Men_hero(){
        Men_army_builder men_builder;
        warriors = dir.createArmy(men_builder, 10, 10, 5);     // создали базовый комлект войнов для эльфов
    }

    void info_race() override {
        cout << "Я человек, я хочу власти..." << endl;
    }

    int get_power_army() override {
        return warriors->get_power_attack();
    }
};

class Dwarve_hero : public Hero {
public:
    Dwarve_hero(){
        Dwarves_army_builder dwarves_builder;
        warriors = dir.createArmy(dwarves_builder, 10, 10, 5);     // создали базовый комлект войнов для эльфов
    }

    void info_race() override {
        cout << "Я гном, дитя гор..." << endl;
    }

    int get_power_army() override {
        return warriors->get_power_attack();
    }
};