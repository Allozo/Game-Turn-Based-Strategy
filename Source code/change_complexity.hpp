#include <iostream>
#include "const_value_complexity_1.h"
#include "const_value_complexity_2.h"
#include "const_value_complexity_3.h"
#pragma once

using namespace std;

class Game;

void change_1(Game &game){
    cout << "Сложность игра - 1!" << endl;
    game.change_complexity(complexity_game_1);
}

void change_2(Game &game){
    cout << "Сложность игра - 2" << endl;
    game.change_complexity(complexity_game_2);
}

void change_3(Game &game){
    cout << "Сложность игра - 3" << endl;
    game.change_complexity(complexity_game_3);
}

/*
class Change_complexity {
public:
    //virtual ~Change_complexity() = 0;
    virtual void change_complexity(Game &game) = 0;
};

class Complexity_1 : public Change_complexity {
public:
    void change_complexity(Game &game) override {
        game.complexity = complexity_game_1;
    }
};

class Complexity_2 : public Change_complexity {
public:
    void change_complexity(Game &game) override {
        game.complexity = complexity_game_2;
    }
};

class Complexity_3 : public Change_complexity {
public:
    void change_complexity(Game &game) override {
        game.complexity = complexity_game_3;
    }
};
 */