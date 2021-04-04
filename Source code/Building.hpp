#include "my_hero.hpp"
#include "tools_for_army.hpp"
#pragma once

class Game;

class Main_building {
public:
    Main_building() = default;

    void info() {
        cout << "Я отец зданий" << endl;
    }

    Army* get_army() {
        return warriors_in_build;
    }

    virtual void zero_army() = 0;

    virtual void up_number_warrior(Game &game) = 0;
protected:
    Director dir;                                    // создали класс распорядитель
    Army *warriors_in_build;                         // войны в казарме
};



class Kaserm : public Main_building{
public:
    Kaserm() = default;

    void info_building() {
        cout << "Казарма" << endl;
    }
};

class Castle : public Main_building {
public:
    Castle() = default;

    void info_building() {
        cout << "Замок" << endl;
    }
};


class Men_kaserm : public Kaserm {
public:
    void up_number_warrior(Game &game) override {
        Men_army_builder men_builder;
        Army* new_warriors_in_build = dir.createArmy(men_builder, 0, 10, 0);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
        cout << endl;
    }

    void zero_army() override {
        Men_army_builder men_builder;
        warriors_in_build = dir.createArmy(men_builder, 0, 0, 0);
    }
};

class Elf_kaserm : public Kaserm {
public:
    void up_number_warrior(Game &game) override {
        Elfs_army_builder elf_builder;
        Army* new_warriors_in_build = dir.createArmy(elf_builder, 0, 10, 0);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
    }

    void zero_army() override {
        Elfs_army_builder elf_builder;
        warriors_in_build = dir.createArmy(elf_builder, 0, 0, 0);
    }
};

class Dwarve_kaserm : public Kaserm {
public:
    void up_number_warrior(Game &game) override {
        Dwarves_army_builder dwarve_builder;
        Army* new_warriors_in_build = dir.createArmy(dwarve_builder, 0, 10, 0);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
        cout << endl;
    }

    void zero_army() override {
        Dwarves_army_builder dwarve_builder;
        warriors_in_build = dir.createArmy(dwarve_builder, 0, 0, 0);
    }
};



class Men_castle : public Castle {
public:
    void up_number_warrior(Game &game) override {
        Men_army_builder men_builder;
        Army* new_warriors_in_build = dir.createArmy(men_builder, 5, 5, 5);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
    }

    void zero_army() override {
        Men_army_builder men_builder;
        warriors_in_build = dir.createArmy(men_builder, 0, 0, 0);
    }
};

class Elf_castle : public Castle {
public:
    void up_number_warrior(Game &game) override {
        Elfs_army_builder elf_builder;
        Army* new_warriors_in_build = dir.createArmy(elf_builder, 5, 5, 5);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
    }

    void zero_army() override  {
        Elfs_army_builder elf_builder;
        warriors_in_build = dir.createArmy(elf_builder, 0, 0, 0);
    }
};

class Dwarve_castle : public Castle {
public:
    void up_number_warrior(Game &game) override {
        Dwarves_army_builder dwarve_builder;
        Army* new_warriors_in_build = dir.createArmy(dwarve_builder, 5, 5, 5);
        warriors_in_build = association_army(dir, warriors_in_build, new_warriors_in_build);
    }

    void zero_army() override {
        Dwarves_army_builder dwarve_builder;
        warriors_in_build = dir.createArmy(dwarve_builder, 0, 0, 0);
    }
};

