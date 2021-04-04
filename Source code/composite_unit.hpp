#include <vector>
#include "Unit_Of_Men.h"
#include "Unit_Of_Elf.h"
#include "Unit_Of_Dwarve.h"
#pragma once

// Composite for men
class Composite_Unit_of_men : public Unit_of_men {
public:
    int getStrength() {
        int total = 0;
        for (int i = 0; i < c.size(); ++i)
            total += c[i]->getStrength();
        return total;
    }

    void info() final {};

    void attack() final {};

    void defend() final {};

    void addUnit(Unit_of_men *p) final {
        c.push_back(p);
    }

    ~Composite_Unit_of_men() final {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

private:
    std::vector<Unit_of_men *> c;
};

// Composite for elfs
class Composite_Unit_of_elfs : public Unit_of_elfs {
public:
    int getStrength() {
        int total = 0;
        for (int i = 0; i < c.size(); ++i)
            total += c[i]->getStrength();
        return total;
    }

    void info() final {};

    void attack() final {};

    void defend() final {};

    void addUnit(Unit_of_elfs *p) final {
        c.push_back(p);
    }

    ~Composite_Unit_of_elfs() final {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

private:
    std::vector<Unit_of_elfs *> c;
};

// Composite for dwarves
class Composite_Unit_of_dwarves : public Unit_of_dwarves {
public:
    int getStrength() {
        int total = 0;
        for (int i = 0; i < c.size(); ++i)
            total += c[i]->getStrength();
        return total;
    }

    void info() final {};

    void attack() final {};

    void defend() final {};

    void addUnit(Unit_of_dwarves *p) final {
        c.push_back(p);
    }

    ~Composite_Unit_of_dwarves() final {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

private:
    std::vector<Unit_of_dwarves *> c;
};


// Вспомогательная функция для создания легиона людей
Composite_Unit_of_men *create_legion_men(int x, int y, int z) {
    // Легион людей содержит:
    Composite_Unit_of_men *legion = new Composite_Unit_of_men;
    for (int i = 0; i < x; ++i)
        legion->addUnit(new Men_infantry);
    for (int i = 0; i < y; ++i)
        legion->addUnit(new Men_arbalesters);
    for (int i = 0; i < z; ++i)
        legion->addUnit(new Men_cavalry);

    return legion;
}

// Вспомогательная функция для создания легиона эльфов
Composite_Unit_of_elfs *create_legion_elfs(int x, int y, int z) {
    // Легион людей содержит:
    Composite_Unit_of_elfs *legion = new Composite_Unit_of_elfs;
    for (int i = 0; i < x; ++i)
        legion->addUnit(new Elfs_infantry);
    for (int i = 0; i < y; ++i)
        legion->addUnit(new Elfs_arbalesters);
    for (int i = 0; i < z; ++i)
        legion->addUnit(new Elfs_cavalry);

    return legion;
}

// Вспомогательная функция для создания легиона гномов
Composite_Unit_of_dwarves *create_legion_dwarves(int x, int y, int z) {
    // Легион людей содержит:
    Composite_Unit_of_dwarves *legion = new Composite_Unit_of_dwarves;
    for (int i = 0; i < x; ++i)
        legion->addUnit(new Dwarves_infantry);
    for (int i = 0; i < y; ++i)
        legion->addUnit(new Dwarves_arbalesters);
    for (int i = 0; i < z; ++i)
        legion->addUnit(new Dwarves_cavalry);

    return legion;
}
