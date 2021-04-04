#pragma once
#include "Unit_Of_Dwarve.h"

// Фабрика гномов
class Factory_dwarves {
public:
    virtual Unit_of_dwarves *Create() = 0;

    virtual ~Factory_dwarves() = default;
};

class Dwarves_infantry_factory : public Factory_dwarves {
public:
    Unit_of_dwarves *Create() override {
        return new Dwarves_infantry;
    }
};

class Dwarves_arbalesters_factory : public Factory_dwarves {
public:
    Unit_of_dwarves *Create() override {
        return new Dwarves_arbalesters;
    }
};

class Dwarves_cavalry_factory : public Factory_dwarves {
public:
    Unit_of_dwarves *Create() override {
        return new Dwarves_cavalry;
    }
};
