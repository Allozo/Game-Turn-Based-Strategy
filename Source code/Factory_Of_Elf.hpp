#include "Unit_Of_Elf.h"
#pragma once

// Фабрика эльфов
class Factory_elfs {
public:
    virtual Unit_of_elfs *Create() = 0;

    virtual ~Factory_elfs() = default;
};

class Elfs_infantry_factory : public Factory_elfs {
public:
    Unit_of_elfs *Create() override {
        return new Elfs_infantry;
    }
};

class Elfs_arbalesters_factory : public Factory_elfs {
public:
    Unit_of_elfs *Create() override {
        return new Elfs_arbalesters;
    }
};

class Elfs_cavalry_factory : public Factory_elfs {
public:
    Unit_of_elfs *Create() override {
        return new Elfs_cavalry;
    }
};
