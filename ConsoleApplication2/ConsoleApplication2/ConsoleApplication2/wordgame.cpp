#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "wordgame.h"

using namespace std;

#define GREEN "\033[32m"
#define ORANGE "\033[38;5;214m"
#define WHITE "\033[37m"
#define BLACK "\033[30m"

string words[] = {
    "аптека","береза","бревно","версия","провод","ворона","газета","гитара","горшок",
    "дракон","жемчуг","замена","запись","запуск","звонок","змейка","золото","иголка",
    "камень","кабель","картон","каштан","колесо","комета","коралл","корова","кресло",
    "кустик","лавина","листва","лосьон","малина","маркер","металл","молоко","гитхаб",
    "нагрев","неделя","нейрон","ноябрь","обедня","огонек","одежда","окунек","отпуск",
    "пикник","плотик","пленка","погода","подвал","полено","прапор","работа","ракета",
    "ракуша","ревень","регион","редька","резина","ремень","речник","рогожа","романс",
    "рутина","рыбина","память","свечка","седина","сельдь","сенсор","скелет","скрепа",
    "скрипт","слойка","случай","сметка","снежок","солома","соната","сорока","спинка",
    "спичка","стакан","стадия","статуя","стихия","столик","струна","стюард","сырник",
    "танкер","теннис","тополь","торшер","тряпка","трубка","умение","усилие","учебка",
    "фасоль","фляжка","формат","форсаж","футбол","чеснок","шарфик","шесток","шляпка",
    "штатив","эскимо","эшелон","яблоко","ястреб","бандит","банкир","барьер","бульон",
    "бункер","вампир","вершок","воздух","войлок","выброс","гаджет","галера","гибрид",
    "грабля","гранат","графин","грелка","гречка","гроздь","грифон","датчик","дизель",
    "добыча","домино","дынька","запрет","зодиак","кабаре","кадило","каймак","кальян",
    "каньон","карман","клевер","клинок","клюква","кобель","кожура","колтун","кольцо",
    "контур","корыто","костюм","кружка","кустар","куплет","курган","курица","лайнер",
    "ливень","люстра","медаль","бутыль","сафари","бусина","болтун","гитхаб","решето"
};

string key_word;
string colours[6];
int counter_of_steps;

// Прототипы внутренних функций
void takeWord();
void showRules();
void inputAndCheck();
void checkLet(const string& el);
bool itsContinue();

void wordGame() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    showRules();

    bool victory, break_cycle;

    do {
        victory = false;
        break_cycle = false;

        for (int i = 6; i > 0; i--) {
            counter_of_steps = i;
            if (i == 6) takeWord();

            cout << "У вас осталось " << i << " попыток" << endl;
            inputAndCheck();

            bool allGreen = true;
            for (int j = 0; j < 6; j++) {
                if (colours[j] != GREEN) {
                    allGreen = false;
                    break;
                }
            }

            if (allGreen) {
                victory = true;
                break_cycle = true;
            }

            if (break_cycle) break;
        }

        if (victory)
            cout << GREEN << "============ ПОБЕДА ==============" << WHITE << endl;
        else
            cout << "============ ПОРАЖЕНИЕ ==============" << endl
            << "Загаданное слово: " << key_word << endl;

    } while (itsContinue());
}

void takeWord() {
    int random_var = rand() % (sizeof(words) / sizeof(words[0]));
    key_word = words[random_var];
}

void showRules() {
    cout << "ПРАВИЛА:" << endl
        << "Необходимо ввести слово из 6 букв" << endl
        << ORANGE << "Желтый цвет - буква есть в слове, но не на этом месте" << endl
        << GREEN << "Зеленый цвет - буква на правильной позиции" << WHITE << endl << endl;
}

void inputAndCheck() {
    while (true) {
        setlocale(LC_ALL, "ru");
        string input;
        cout << "Введите слово: ";
        cin >> input;

        if (input.size() == 6) {
            checkLet(input);
            break;
        }
        else {
            cout << "Слово должно быть 6 букв!" << endl;
        }
    }
}

void checkLet(const string& el) {
    for (int i = 0; i < 6; i++) colours[i] = WHITE;

    for (int i = 0; i < 6; i++) {
        if (el[i] == key_word[i]) {
            colours[i] = GREEN;
        }
        else {
            for (int j = 0; j < 6; j++) {
                if (el[i] == key_word[j] && i != j) {
                    colours[i] = ORANGE;
                    break;
                }
            }
        }
    }

    cout << "         ";
    for (int i = 0; i < 6; i++)
        cout << colours[i] << el[i] << WHITE;
    cout << endl << endl;
}

bool itsContinue() {
    cout << "Хотите продолжить?" << endl
        << "1 - Да, 2 - Нет: ";
    char choice;
    while (true) {
        choice = _getch();
        if (choice == '1') { system("cls"); return true; }
        if (choice == '2') return false;
    }
}
