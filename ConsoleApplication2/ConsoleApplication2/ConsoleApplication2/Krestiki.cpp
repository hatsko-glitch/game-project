#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num;
            num++;
        }
    }
}

void showBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void playGame() {
    resetBoard();

    char player1 = 'X';
    int choice;
    bool gameOver = false;
    int draw = 0;

    cout << "\n=== НАЧАЛО НОВОЙ ИГРЫ ===\n";

    while (!gameOver) {
        showBoard();
        cout << "Игрок " << player1 << " выберите номер клетки от 1 до 9" << endl;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Ошибка! Введите ЧИСЛО от 1 до 9." << endl;
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Ошибка! Введите число от 1 до 9." << endl;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player1;
            draw++;
            cout << "Поставили " << player1 << " в клетку " << choice << endl;

            if (checkWin(player1)) {
                showBoard();
                cout << "========================\n";
                cout << "  Игрок " << player1 << " победил!\n";
                cout << "========================\n";
                gameOver = true;
            }
            else if (draw == 9) {
                showBoard();
                cout << "========================\n";
                cout << "        Ничья!\n";
                cout << "========================\n";
                gameOver = true;
            }
            else {
                if (player1 == 'X') {
                    player1 = 'O';
                }
                else {
                    player1 = 'X';
                }
            }
        }
        else {
            cout << "Клетка уже занята!" << endl;
        }
    }
}

void krestiki() {
    setlocale(LC_ALL, "Russian");
    int menuChoice;

    do {
        cout << "\n========================\n";
        cout << "    КРЕСТИКИ-НОЛИКИ\n";
        cout << "========================\n";
        cout << "1. Начать новую игру\n";
        cout << "2. Правила игры\n";
        cout << "3. Выйти\n";
        cout << "========================\n";
        cout << "Выберите пункт меню: ";
        cin >> menuChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            menuChoice = 0;
        }

        switch (menuChoice) {
        case 1:
            playGame();
            break;
        case 2:
            cout << "\n=== ПРАВИЛА ИГРЫ ===\n";
            cout << "1. Игроки ходят по очереди\n";
            cout << "2. Первый игрок - X, второй - O\n";
            cout << "3. Выигрывает тот, кто первым соберет\n";
            cout << "   3 своих символа в ряд (по горизонтали,\n";
            cout << "   вертикали или диагонали)\n";
            cout << "4. Если все клетки заполнены, но нет\n";
            cout << "   победителя - ничья\n";
            cout << "5. Для хода введите номер клетки (1-9)\n";
            cout << "========================\n\n";
            break;

        case 3:
            cout << "\nВыход из игры...\n";
            break;

        default:
            cout << "\nНеверный выбор! Введите 1, 2 или 3.\n";
        }

    } while (menuChoice != 3);

    cout << "Спасибо за игру!\n";
 
}