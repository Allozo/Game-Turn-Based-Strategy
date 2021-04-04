#include "tools_for_army.hpp"
#include "const_value_complexity_1.h"
#include "const_value_complexity_2.h"
#include "const_value_complexity_3.h"
#include "my_hero.hpp"
#include "game_map.hpp"
#include "Observe.hpp"
#include "Building.hpp"
#include "Enemy.hpp"


void change_1(Game &game);                           // функция для установки сложности - 1
void change_2(Game &game);                           // функция для установки сложности - 2
void change_3(Game &game);                           // функция для установки сложности - 3


class Game{
public:
    Game() {
        time = 0;
        complexity = complexity_game_1;     // начальная сложность
        flag_use_treasure = false;
        map_game.resize(3);
        for (int i = 0; i < 3; i++){
            map_game[i].resize(3);
        }

        /*Обозначили, что где есть на карте*/
        map_game[0][0] = "Замок";
        map_game[0][2] = "Сокровище";
        map_game[2][0] = "Казарма";
        map_game[2][2] = "Противник";
    }

    //// Сам процесс игры
    void start_game() {
        // начало игры
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|         Итак... Игра началась!           |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Выберите за какую рассу вы играете:      |" << endl;
        cout << "|  1) Люди                                 |" << endl;
        cout << "|  2) Эльфы                                |" << endl;
        cout << "|  3) Гномы                                |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                Men_hero my_hero;
                race_hero = "men";
                cout << endl << "Это карта игры." << endl;
                cout << "Ваша цель победить противника в верхнем правом углу." << endl;
                map_8_1();
                /*Добавили здания героя*/
                Men_kaserm kaserm_1;
                Men_castle castle_1;
                kaserm_1.zero_army();
                castle_1.zero_army();
                main_observe.add_building(kaserm_1);
                main_observe.add_building(castle_1);
                /*запуск*/
                play_game(my_hero);
                break;
            } else if (text == "2") {
                Elf_hero my_hero;
                race_hero = "elf";
                cout << endl << "Это карта игры." << endl;
                cout << "Ваша цель победить противника в верхнем правом углу." << endl;
                map_8_1();
                /*Добавили здания героя*/
                Elf_kaserm kaserm_1;
                Elf_castle castle_1;
                kaserm_1.zero_army();
                castle_1.zero_army();
                main_observe.add_building(kaserm_1);
                main_observe.add_building(castle_1);
                /*запуск*/
                play_game(my_hero);
                break;
            } else if (text == "3") {
                Dwarve_hero my_hero;
                race_hero = "dwarve";
                cout << endl << "Это карта игры." << endl;
                cout << "Ваша цель победить противника в верхнем правом углу." << endl;
                map_8_1();
                /*Добавили здания героя*/
                Dwarve_kaserm kaserm_1;
                Dwarve_castle castle_1;
                kaserm_1.zero_army();
                castle_1.zero_army();
                main_observe.add_building(kaserm_1);
                main_observe.add_building(castle_1);
                /*запуск*/
                play_game(my_hero);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }


    }                          // начало игры

    void game_exit() {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Вы уверны, что хотите выйти из игры?     |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| 1) Да           | 2) Нет                 |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                cout << "Всего доброго!!!" << endl;
                exit(0);
            } else if (text == "2") {
                cout << ">>>Отмена выхода." << endl << endl << endl;
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void play_game(Hero &my_hero) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|             Командная панель             |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Выберите действие:                       |" << endl;
        cout << "|   1) Перемещение по карте                |" << endl;
        cout << "|   2) Взаимодействие с объектом           |" << endl;
        cout << "|   3) Статистика вашего героя             |" << endl;
        cout << "|   4) Пропустить ход                      |" << endl;
        cout << "|   5) Выход из игры                       |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                cout << endl << endl;
                view_map(my_hero);
                movement_map(my_hero);
            } else if (text == "2") {
                use_object(my_hero);
            } else if (text == "3") {
                statistics(my_hero);
            } else if (text == "4") {
                next_move(my_hero);
            } else if (text == "5") {
                game_exit();
                play_game(my_hero);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void settings_game() {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|               Настройки.                 |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Сложность игры: " << complexity << "                        |" << endl;
        cout << "| Количество нейтральных игроков: 1        |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Введите '1' для изменения сложности.     |" << endl;
        cout << "| Введите '2' для возвращения к меню.      |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        bool flg_command = false;
        while (true) {
            string text;
            cout << "Введите команду: ";
            cin >> text;
            cout << endl << endl;
            if (text == "1") {
                change_complexity_game();
                break;
            } else if (text == "2") {
                menu();
                break;
            } else
                cout << "Команда не распознана. Введите еще раз." << endl;
        }
    }                       // настройки игры

    void menu() {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|                 Меню.                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Введите '1' для начала игры.           |" << endl;
        cout << "| Введите '2' для перехода к настройкам. |" << endl;
        cout << "| Введите '3' для выхода из игры.        |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Введите команду: ";
            cin >> text;
            cout << endl << endl;
            if (text == "1") {
                start_game();
                break;
            } else if (text == "2") {
                settings_game();
                break;
            } else if (text == "3") {
                game_exit();
                menu();
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }                                // меню игры

    void win(){
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|           Итак... ВЫ ПОБЕДИЛИ!!!         |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| На этом эта игра заканчивается...        |" << endl;
        cout << "| Надеемся, что вам понравилось...         |" << endl;
        cout << "| Ваши отзывы, пожелания оставлейте Allozo |" << endl;
        cout << "| Желаем всего доброго!!!                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        exit(0);
    }

    void defeat() {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|           Итак... Вы проиграли...        |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| На этом эта игра заканчивается...        |" << endl;
        cout << "| Вы всегда можете начать её заново...     |" << endl;
        cout << "| Желаем всего доброго!!!                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        exit(0);
    }

    void drawn_game() {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Итак... Ничья в этой игре...             |" << endl;
        cout << "| Противник оказался равен вам...          |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| На этом эта игра заканчивается...        |" << endl;
        cout << "| Вы всегда можете начать её заново...     |" << endl;
        cout << "| Желаем всего доброго!!!                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        exit(0);
    }

    //// Взаимодействие с объектами
    void get_treasure(Hero &my_hero) {
        if (my_hero.get_position_player() == make_pair(0, 2) and !flag_use_treasure) {
            my_hero.up_treasure();
            flag_use_treasure = true;
            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|           Вы нашли сокровище.            |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << endl;
        }
    }

    void inf_castle (Hero &my_hero) {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|                  Замок.                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Горнизон:                                |" << endl;
        Army* castle_army = main_observe.get_building(1)->get_army();
        vector<int> number_unit_first = castle_army->get_number_unit();
        cout << "| Кол-во пехоты:    " << number_unit_first[0] << endl;
        cout << "| Кол-во лучников:  " << number_unit_first[1] << endl;
        cout << "| Кол-во кавалерии: " << number_unit_first[2] << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Пополнить свою армию?                    |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| 1) Да           | 2) Нет                 |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                interaction_castle(my_hero);
                play_game(my_hero);
                break;
            } else if (text == "2") {
                cout << endl << endl;
                play_game(my_hero);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void inf_caserm(Hero &my_hero) {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|                Казарма.                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Горнизон:                                |" << endl;
        Army* caserm_army = main_observe.get_building(0)->get_army();
        vector<int> number_unit_first = caserm_army->get_number_unit();
        cout << "| Кол-во пехоты:    " << number_unit_first[0] << endl;
        cout << "| Кол-во лучников:  " << number_unit_first[1] << endl;
        cout << "| Кол-во кавалерии: " << number_unit_first[2] << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Пополнить свою армию?                    |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| 1) Да           | 2) Нет                 |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                interaction_caserm(my_hero);
                play_game(my_hero);
                break;
            } else if (text == "2") {
                cout << endl << endl;
                play_game(my_hero);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void interaction_castle(Hero &my_hero) {
        if (my_hero.get_position_player() == make_pair(0, 0)) {
            Army* hero_army = my_hero.get_army();
            Army* castle_army = main_observe.get_building(1)->get_army();
            Director dir;
            my_hero.new_army(association_army(dir, hero_army, castle_army));
            main_observe.get_building(1)->zero_army();
            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|           Вы пополнили армию.            |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << endl;
        }
    }

    void interaction_caserm(Hero &my_hero) {
        if (my_hero.get_position_player() == make_pair(2, 0)) {
            Army* hero_army = my_hero.get_army();
            Army* castle_army = main_observe.get_building(0)->get_army();
            Director dir;
            my_hero.new_army(association_army(dir, hero_army, castle_army));
            main_observe.get_building(0)->zero_army();
            cout << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|           Вы пополнили армию.            |" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << endl;
        }
    }

    void battle(Hero &my_hero){
        Enemy my_enemy;
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|           Итоговая битва.              |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Сила противника: " << my_enemy.get_power_army() <<  "                  |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|           Хотите напасть?              |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Введите '1' нападения.                 |" << endl;
        cout << "| Введите '2' возвращения.               |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            if (text == "1") {
                if (my_hero.get_power_army() > my_enemy.get_power_army())
                    win();
                else if (my_hero.get_power_army() == my_enemy.get_power_army())
                    drawn_game();
                else
                    defeat();
                break;
            } else if (text == "2") {
                cout << "Вы вернулись на поле." << endl;
                play_game(my_hero);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void use_object(Hero &my_hero) {
        int pos_x = my_hero.get_position_player().first;
        int pos_y = my_hero.get_position_player().second;
        if (pos_x == 0 && pos_y == 2) {
            get_treasure(my_hero);                   // получить сокровище
        }
        if (pos_x == 0 && pos_y == 0) {
            inf_castle(my_hero);             // зайти в замок
        }
        if (pos_x == 2 && pos_y == 0) {              // зайти в казарму
            inf_caserm(my_hero);
        }
        if (pos_x == 2 && pos_y == 2) {              // битва
            battle(my_hero);
        }
        play_game(my_hero);
    }


    //// Все стальное
    void view_map(Hero &my_hero) {
        int pos_x = my_hero.get_position_player().first;
        int pos_y = my_hero.get_position_player().second;
        if (!flag_use_treasure) {
            // сокровище не найдено
            if (pos_x == 0 and pos_y == 0) {
                map_7_1();
            }
            if (pos_x == 1 and pos_y == 0) {
                map_8_1();
            }
            if (pos_x == 2 and pos_y == 0) {
                map_9_1();
            }
            if (pos_x == 0 and pos_y == 1) {
                map_4_1();
            }
            if (pos_x == 1 and pos_y == 1) {
                map_5_1();
            }
            if (pos_x == 2 and pos_y == 1) {
                map_6_1();
            }
            if (pos_x == 0 and pos_y == 2) {
                map_1_1();
            }
            if (pos_x == 1 and pos_y == 2) {
                map_2_1();
            }
            if (pos_x == 2 and pos_y == 2) {
                map_3_1();
            }
        } else {
            // сокровище найдено
            if (pos_x == 0 and pos_y == 0) {
                map_7_2();
            }
            if (pos_x == 1 and pos_y == 0) {
                map_8_2();
            }
            if (pos_x == 2 and pos_y == 0) {
                map_9_2();
            }
            if (pos_x == 0 and pos_y == 1) {
                map_4_2();
            }
            if (pos_x == 1 and pos_y == 1) {
                map_5_2();
            }
            if (pos_x == 2 and pos_y == 1) {
                map_6_2();
            }
            if (pos_x == 0 and pos_y == 2) {
                map_1_2();
            }
            if (pos_x == 1 and pos_y == 2) {
                map_2_2();
            }
            if (pos_x == 2 and pos_y == 2) {
                map_3_2();
            }
        }
    }

    void movement_map(Hero &my_hero) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|         Перемещение по карте             |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Выберите действие:                       |" << endl;
        cout << "|   1) Переместиться вверх                 |" << endl;
        cout << "|   2) Переместиться влево                 |" << endl;
        cout << "|   3) Переместиться вправо                |" << endl;
        cout << "|   4) Переместиться вверх                 |" << endl;
        cout << "|   5) Вернуться командной панели          |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Ваш выбор: ";
            cin >> text;
            int pos_x = my_hero.get_position_player().first;
            int pos_y = my_hero.get_position_player().second;
            if (text == "1" or text == "w") {
                // движение вверх
                if (pos_y < 2) {
                    cout << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|           Вы сместились вверх.           |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << endl;
                    inc_time();
                    my_hero.change_position(pos_x, pos_y + 1);
                    view_map(my_hero);
                    movement_map(my_hero);
                    break;
                } else {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|      Вы не можете туда сместиться.       |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
            } else if (text == "2" or text == "a") {
                // движение влево
                if (pos_x > 0) {
                    cout << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|           Вы сместились влево.           |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << endl;
                    inc_time();
                    my_hero.change_position(pos_x - 1, pos_y);
                    view_map(my_hero);
                    movement_map(my_hero);
                    break;
                } else {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|      Вы не можете туда сместиться.       |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
            } else if (text == "3" or text == "d") {
                // движение вправо
                if (pos_x < 2) {
                    cout << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|          Вы сместились вправо.           |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << endl;
                    inc_time();
                    my_hero.change_position(pos_x + 1, pos_y);
                    view_map(my_hero);
                    movement_map(my_hero);
                    break;
                } else {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|      Вы не можете туда сместиться.       |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
            } else if (text == "4" or text == "s") {
                // движение вниз
                if (pos_y > 0) {
                    cout << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|           Вы сместились вниз.            |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << endl;
                    inc_time();
                    my_hero.change_position(pos_x, pos_y - 1);
                    view_map(my_hero);
                    movement_map(my_hero);
                    break;
                } else {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|      Вы не можете туда сместиться.       |" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
            } else if (text == "5") {
                cout << endl << endl;
                play_game(my_hero);
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
    }

    void next_move(Hero &my_hero) {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|            Вы пропустили ход.            |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl;
        inc_time();
        play_game(my_hero);
    }

    void new_week() {
        up_number_warrior();
    }

    void inc_time() {
        time++;
        if (time % 7 == 0){
            new_week();
            cout << "Население в строениях увеличилось!" << endl;
        }
    }

    void up_number_warrior() {
        main_observe.up_number_warrior(*this);
    }

    void change_complexity_game() {
        int new_complexity;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|        Изменение сложности игры.         |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Введите сложность игры. Число от 1 до 3. |" << endl;
        cout << "| По умолчанию сложность равна 1.          |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        while (true) {
            string text;
            cout << "Введите сложность игры: ";
            cin >> text;

            if (text == "1") {
                change_1(*this);
                break;
            } else if (text == "2") {
                change_2(*this);
                break;
            } else if (text == "3") {
                change_3(*this);
                break;
            } else
                cout << endl << "Команда не распознана. Введите еще раз." << endl;
        }
        cout << endl << endl;
        settings_game();
    }              // изменение сложности

    void change_complexity(int value) {
        complexity = value;
    }          // изменение значения сложности

    void statistics(Hero &my_hero) {
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Статистика:                              |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Имя вашего героя: " << my_hero.get_name_hero() << endl;
        cout << "| Прибавка к урону от сокровищ: " << my_hero.get_treasure() << "%" << endl;
        cout << "| Сила вашей армии:  " << my_hero.get_power_army()
             << " + " << my_hero.get_power_army() * 0.01 * my_hero.get_treasure()
             << " = " << my_hero.get_power_army() + my_hero.get_power_army() * 0.01 * my_hero.get_treasure() << endl;
        cout << "| Было сделано: " << time << " ходов." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "| Состав вашей армии:                        " << endl;
        vector<int> my_arm = my_hero.get_number_unit();
        cout << "|    Пехота:  " << my_arm[0] << endl;
        cout << "|    Лучники: " << my_arm[1] << endl;
        cout << "|    Конница: " << my_arm[2] << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        play_game(my_hero);
    }             // вывод статистики

    string get_race_hero() {
        return race_hero;
    }
private:
    string race_hero;
    int complexity;                                  // сложность игры
    bool flag_use_treasure;                          // взято ли сокровище
    vector<vector<string> > map_game;                // карта
    int time;
    Observe main_observe;                            // Отвечает за увеличение войнов в зданиях
};

#include "change_complexity.hpp"

int main() {
    Game game;
    game.menu();                                     // запуск игры
    return 0;
}