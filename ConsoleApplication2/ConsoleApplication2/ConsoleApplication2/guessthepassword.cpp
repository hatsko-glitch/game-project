#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "guessthepassword.h"

using namespace std;

#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define RESET  "\033[0m"

const int SIZE = 5;
const int MAX_TRIES = 10;

void chooseAlphabet(char alphabet[], int& alphabetSize);
void generateSecret(char secret[], char alphabet[], int alphabetSize);
bool readGuess(char guess[]);
void printResult(const char secret[], const char guess[]);
bool checkWin(const char secret[], const char guess[]);

void guessthepassword() {
    setlocale(LC_CTYPE, "Rus");
    srand(time(0));

    char alphabet[100];
    int alphabetSize;

    chooseAlphabet(alphabet, alphabetSize);

    char secret[SIZE];
    char guess[SIZE];

    generateSecret(secret, alphabet, alphabetSize);

    cout << "\nУгадайте последовательность из 5 символов\n";

    for (int attempt = 1; attempt <= MAX_TRIES; attempt++) {
        cout << "\nПопытка " << attempt << ": ";

        if (!readGuess(guess)) {
            attempt--;
            continue;
        }

        printResult(secret, guess);

        if (checkWin(secret, guess)) {
            cout << "\n(WIN) Вы угадали!\n";
            return;
        }
    }

    cout << "\n(LOSE) Вы проиграли. Ответ: ";
    for (int i = 0; i < SIZE; i++)
        cout << secret[i];
    cout << endl;
}

void chooseAlphabet(char alphabet[], int& alphabetSize) {
    char digits[] = "0123456789";
    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$%^&*()~";

    int difficulty;
    cout << "Выберите сложность:\n";
    cout << "1 - Только цифры\n";
    cout << "2 - Цифры + буквы\n";
    cout << "3 - Цифры + буквы + спецсимволы\n";
    cout << "Ваш выбор: ";
    cin >> difficulty;

    alphabetSize = 0;

    switch (difficulty) {
    case 1:
        for (int i = 0; digits[i]; i++)
            alphabet[alphabetSize++] = digits[i];
        break;
    case 2:
        for (int i = 0; digits[i]; i++)
            alphabet[alphabetSize++] = digits[i];
        for (int i = 0; letters[i]; i++)
            alphabet[alphabetSize++] = letters[i];
        break;
    case 3:
        for (int i = 0; digits[i]; i++)
            alphabet[alphabetSize++] = digits[i];
        for (int i = 0; letters[i]; i++)
            alphabet[alphabetSize++] = letters[i];
        for (int i = 0; symbols[i]; i++)
            alphabet[alphabetSize++] = symbols[i];
        break;
    default:
        cout << "Неверная сложность!\n";
        exit(0);
    }
}

void generateSecret(char secret[], char alphabet[], int alphabetSize) {
    for (int i = 0; i < SIZE; i++) {
        secret[i] = alphabet[rand() % alphabetSize];
    }
}

bool readGuess(char guess[]) {
    char input[SIZE + 1];
    cin >> input;

    if (strlen(input) != SIZE) {
        cout << "Введите ровно 5 символов!\n";
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        guess[i] = input[i];
    }

    return true;
}

void printResult(const char secret[], const char guess[]) {
    bool usedSecret[SIZE] = { false };
    bool usedGuess[SIZE] = { false };

    for (int i = 0; i < SIZE; i++) {
        if (guess[i] == secret[i]) {
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (usedGuess[i]) {
            cout << GREEN << guess[i] << RESET;
        }
        else {
            bool found = false;
            for (int j = 0; j < SIZE; j++) {
                if (!usedSecret[j] && guess[i] == secret[j]) {
                    usedSecret[j] = true;
                    found = true;
                    break;
                }
            }
            cout << (found ? YELLOW : RED) << guess[i] << RESET;
        }
    }
    cout << endl;
}

bool checkWin(const char secret[], const char guess[]) {
    for (int i = 0; i < SIZE; i++) {
        if (secret[i] != guess[i])
            return false;
    }
    return true;
}
