#include "Unit_Of_Men.h"
#pragma once

// Фабрика людей
class Factory_men {
public:
    virtual Unit_of_men *Create() = 0;

    virtual ~Factory_men() = default;
};

class Men_infantry_factory : public Factory_men {
public:
    Unit_of_men *Create() override {
        return new Men_infantry;
    }
};

class Men_arbalesters_factory : public Factory_men {
public:
    Unit_of_men *Create() override {
        return new Men_arbalesters;
    }
};

class Men_cavalry_factory : public Factory_men {
public:
    Unit_of_men *Create() override {
        return new Men_cavalry;
    }
};
