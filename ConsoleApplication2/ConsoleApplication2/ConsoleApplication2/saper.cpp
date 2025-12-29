#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 5;   // размер поля
const int M = 5;   // количество мин

char field[N][N];      // игровое поле
bool mines[N][N];      // где мины
bool firstMove = true; // флаг первого хода
int opened = 0;        // сколько клеток открыто

void init() { // инициализация поля
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            field[i][j] = '*';
            mines[i][j] = false; // мин пока нет
        }
}

void placeMines(int safeX, int safeY) { // расстановка мин
    int placed = 0; // счетчик для размещенных мин
    while (placed < M) {
        int x = rand() % N, y = rand() % N;
        if ((x == safeX && y == safeY) || mines[x][y]) continue; // пропускаем если это первый код или в этой клетке уже есть мина
        mines[x][y] = true;
        placed++;
    }
}

int countMines(int x, int y) { // подсчет мин вокруг клетки
    int c = 0; // счетчик мин
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && mines[nx][ny]) c++;
        }
    return c; // возвращаем количество соседних мин
}

void printField() { // вывод поля на экран
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << field[i][j] << " ";
        cout << "\n";
    }
}

void saper() {
    setlocale(LC_CTYPE, "Russian");
    srand(time(0));
    init();
    while (true) { // бесконечный игровой цикл
        printField();
        int x, y;
        cout << "Введите координаты через пробел 0-4 (y x): ";
        cin >> x >> y;
        if (firstMove) {
            placeMines(x, y); // расставляем мины после первого хода
            firstMove = false;
        }
        if (mines[x][y]) {
            cout << "Бум! Вы проиграли.\n";
            break;
        }
        else if (field[x][y] == '*') {
            field[x][y] = '0' + countMines(x, y);
            opened++;
        }
        if (opened == N * N - M) {
            printField();
            cout << "Победа!\n";
            break;
        }
    }
 
}
