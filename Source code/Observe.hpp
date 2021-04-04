#include "Building.hpp"
#pragma once

class Observe {
public:
    Observe() = default;

    void add_building(Main_building &building) {
        vector_building.push_back(&building);
    }

    void up_number_warrior(Game &game) {
        for (int i = 0; i < vector_building.size(); i++) {
            vector_building[i]->up_number_warrior(game);
        }
    }

    auto get_building(int i) {
        return vector_building[i];
    }
private:
    vector<Main_building*> vector_building;
};