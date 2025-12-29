 #ifndef GAME_COLLECTION_H
#define GAME_COLLECTION_H

 
#include "quiz.h"
#include "saper.h"
#include "head_zmeika.h"
#include "wordgame.h"
#include "Krestiki.h"
#include "guessthepassword.h"

using namespace std;

void showGamesMenu() {
    int choice;

    do {
        system("cls");
        cout << "=== ВЫБЕРИТЕ ИГРУ ===" << endl;
        cout << "1.  Викторина" << endl;
        cout << "2.  Сапер" << endl;
        cout << "3.  Крестики-нолики" << endl;
        cout << "4.  Взлом кода" << endl;
        cout << "5.  Угадай слово" << endl;
        cout << "6.  Змейка" << endl;
        cout << "0.  Выход" << endl;
        cout << "\nВыбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            quiz();           
            break;
        case 2:
            saper();    
            break;
        case 3:
            krestiki();
            break;
        case 4:
            guessthepassword();
            break;
        case 5:
            wordGame();
            break;
        case 6:
            zmeika();
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
            system("pause");
        }
    } while (choice != 0);
}

#endif