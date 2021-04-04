#include <iostream>
#pragma once

using namespace std;

// Юниты эльфов
class Unit_of_elfs {
public:
    virtual void info() = 0;

    virtual void attack() = 0;

    virtual void defend() = 0;

    virtual int getStrength() = 0;

    virtual void addUnit(Unit_of_elfs* p) {
        assert( false);
    }

    virtual ~Unit_of_elfs() = default;

};

class Elfs_infantry : public Unit_of_elfs {
public:
    void info() override {
        cout << "  This is Elfs_infantry" << endl;
    }

    void attack() override {
        cout << "Elfs_infantry attacking in closely battle!" << endl;
    }

    void defend() override {
        cout << "Elfs_infantry defend!" << endl;
    }

    virtual int getStrength() {
        return 1;
    }

};

class Elfs_arbalesters : public Unit_of_elfs {
public:
    void info() override {
        cout << "  This is Elfs_arbalesters" << endl;
    }

    void attack() override {
        cout << "Elfs_arbalesters attacking in a long battle!" << endl;
    }

    void defend() override {
        cout << "Elfs_arbalesters defend!" << endl;
    }

    virtual int getStrength() {
        return 3;
    }
};

class Elfs_cavalry : public Unit_of_elfs {
public:
    void info() override {
        cout << "  This is Elfs_cavalry" << endl;
    }

    void attack() override {
        cout << "Elfs_cavalry attacking in a long battle!" << endl;
    }

    void defend() override {
        cout << "Elfs_cavalry defend!" << endl;
    }

    virtual int getStrength() {
        return 5;
    }
};