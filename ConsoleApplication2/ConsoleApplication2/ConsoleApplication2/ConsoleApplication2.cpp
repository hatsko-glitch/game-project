#include <iostream>
#include "game_collection.h"   

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "=== КОЛЛЕКЦИЯ ИГР ===" << endl;
    cout << "Нажмите Enter для запуска..." << endl;
    system("pause");

   
    showGamesMenu();

    cout << "\nДо свидания!" << endl;
    return 0;
}
