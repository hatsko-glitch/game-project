#include <iostream>
#include <conio.h>

using namespace std;

const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string ORANGE = "\033[38;5;214m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
string colour_of_snake = GREEN;

#define SIZE  6
#define $ '$'

struct Point {
	int x;
	int y;
};

char field[SIZE][SIZE];
const int HEAD_DEFAULT = SIZE - 3;
int head_position_x;
int head_position_y;
const int TAIL_DEFAULT = SIZE - 3;
int counter_of_tails;
bool need_red;
Point tail[SIZE * SIZE];
Point apples[SIZE * SIZE];
Point old_pos[SIZE * SIZE];

void spawnApples();
void clearField();
void makeField();
void premove();
void move();
void clearSnakeAndPut();
void moveTail();
void grow();
void ind();
bool defeat1();
bool defeat2();
void showStatistic(int steps);
void menu();
void choice();
void controls();

void zmeika() {
	srand(time(NULL));
	menu();
	bool victory = true;
	clearField();
	ind();

	for (int counter_of_steps = 0; victory; counter_of_steps++) {

		if (counter_of_steps == 1) {
			field[TAIL_DEFAULT][TAIL_DEFAULT + 1] = '+';
		}
		makeField();
		premove();
		move();
		grow();
		clearSnakeAndPut();
		spawnApples();

		if (defeat1() || defeat2()) {
			victory = false;
			need_red = 1;
			makeField();
			cout << "============= YOU LOSE ==============";
			showStatistic(counter_of_steps);
			system("pause");
		}

		if (counter_of_tails == (SIZE * SIZE - 1)) {
			victory = false;
			cout << GREEN;
			makeField(); cout << GREEN;
			cout << "============= YOU WIN ==============";
			showStatistic(counter_of_steps);
			system("pause");
		}
	}
}

void menu() {
	system("cls");
	cout << "1:PLAY" << endl;
	cout << "2:CONTROLS" << endl;
	choice();
}

void choice() {
	char var;
	var = _getch();
	switch (var) {
	case'1':return; break;
	case'2':controls(); menu(); break;
	default: choice(); break;
	}
}

void controls() {
	system("cls");
	cout << "1 - GREEN" << endl
		<< "2 - ORANGE" << endl
		<< "3 - YELLOW" << endl
		<< "4 - MAGENTA" << endl
		<< "5 - BLUE" << endl
		<< "6 - CYAN" << endl
		<< "7 - CONTROLS" << endl
		<< "W - UP" << endl
		<< "S - DOWN" << endl
		<< "A - LEFT" << endl
		<< "D - RIGHT" << endl;
	system("pause");
}

void clearField() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i][j] = '.';
		}
	}
}

void premove() {

	for (int i = counter_of_tails - 1; i > 0; i--) {
		old_pos[i] = old_pos[i - 1];
	}

	old_pos[0].y = head_position_y;
	old_pos[0].x = head_position_x;
}

void move() {
	char movement;
	movement = _getch();

	switch (movement) {

	case'w': {
		if (head_position_y - 1 != tail[0].y) {
			head_position_y--;
		}
		else {
			move();
		}
		break;
	}

	case's': {
		if (head_position_y + 1 != tail[0].y) {
			head_position_y++;
		}
		else {
			move();
		}
		break;
	}

	case'd': {
		if (head_position_x + 1 != tail[0].x) {
			head_position_x++;
		}
		else {
			move();
		}
		break;
	}

	case'a': {
		if (head_position_x - 1 != tail[0].x) {
			head_position_x--;
		}
		else {
			move();
		}
		break;
	}
	case'1':colour_of_snake = GREEN; makeField(); move(); break;
	case'2':colour_of_snake = ORANGE; makeField(); move(); break;
	case'3':colour_of_snake = YELLOW; makeField(); move(); break;
	case'4':colour_of_snake = MAGENTA; makeField(); move(); break;
	case'5':colour_of_snake = BLUE; makeField(); move(); break;
	case'6':colour_of_snake = CYAN; makeField(); move(); break;
	case'7': {
		controls();
		makeField();
	}

	default: {
		move();
		break;
	}
	}
}


void moveTail() {

	for (int i = 0; i < SIZE * SIZE - 1; i++) {
		tail[i].x = old_pos[i].x;
		tail[i].y = old_pos[i].y;
		field[tail[i].y][tail[i].x] = '+';
	}

	for (int i = 0; i < SIZE * SIZE - 1; i++) {
		field[tail[i].y][tail[i].x] = '+';
	}
}


void makeField() {

	system("cls");
	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			if ((field[i][j] != '@') && field[i][j] != '+' && (field[i][j] != $)) {
				field[i][j] = '.';
			}

			if (((field[i][j] == '@') || (field[i][j] == '+')) && (!need_red)) {
				cout << colour_of_snake << field[i][j] << WHITE << " ";
			}

			else if (need_red) {
				cout << RED << field[i][j] << " ";
			}

			else {
				cout << field[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void clearSnakeAndPut() {

	for (int i = 0; i < SIZE; i++) {

		for (int j = 0; j < SIZE; j++) {

			if ((field[i][j] == '@') || field[i][j] == '+') {
				field[i][j] = '.';
			}

			if (i == head_position_y && j == head_position_x) {
				field[i][j] = '@';
			}
			for (int m = 0; m < SIZE * SIZE - 1; m++) {

				if ((tail[m].y == i) && (tail[m].x == j)) {
					moveTail();
				}
			}
		}
	}
}

int counter_of_apples = 0;

void spawnApples() {

	if (((rand() % 10) <= 1)) {
		for (bool is_spawn = false; !is_spawn;) {
			bool object_in = false, all_object_fill = true;
			int y = rand() % SIZE, x = rand() % SIZE;

			for (int i = 0; i <= counter_of_apples; i++) {
				if (((apples[i].x == x) && (apples[i].y == y))
					|| ((head_position_x == x) && (head_position_y == y))
					|| ((tail[i].x == x) && (tail[i].y == y))) {
					object_in = true;
				}
			}

			for (int i = 0; i <= SIZE; i++) {

				for (int j = 0; j <= SIZE; j++) {

					if (field[i][j] == '.') {
						all_object_fill = false;
					}
				}
			}

			if (all_object_fill) {
				is_spawn = true;
				continue;
			}

			if (object_in) {
				continue;
			}
			field[y][x] = $;
			apples[counter_of_apples].y = y;
			apples[counter_of_apples].x = x;
			counter_of_apples++;
			is_spawn = true;
		}
	}
}

void grow() {

	for (int i = 0; i < SIZE * SIZE - 1; i++) {

		if ((head_position_x == apples[i].x) && (head_position_y == apples[i].y)) {
			tail[counter_of_tails].x = old_pos[counter_of_tails].x;
			tail[counter_of_tails].y = old_pos[counter_of_tails].y;
			counter_of_tails++;
			apples[i].x = -52;
		}
	}
}

void ind() {

	counter_of_tails = SIZE - 4;
	head_position_x = HEAD_DEFAULT;
	head_position_y = HEAD_DEFAULT;
	need_red = false;

	for (int i = 0; i < SIZE * SIZE - 1; i++) {
		tail[i].x = 42;
		tail[i].y = 228;
	}

	tail[0].y = TAIL_DEFAULT;
	tail[0].x = TAIL_DEFAULT + 1;
	tail[1].y = TAIL_DEFAULT;
	tail[1].x = TAIL_DEFAULT + 2;

	for (int i = 0; i < SIZE * SIZE - 1; i++) {
		apples[i].x = 1488;
		apples[i].y = 1488;
	}

	for (int i = 0; i < SIZE * SIZE - 1; i++) {
		old_pos[i].x = 67;
		old_pos[i].y = 67;

	}
	field[tail[1].y][tail[1].x] = '+';
	field[tail[0].y][tail[0].x] = '+';
	field[HEAD_DEFAULT][HEAD_DEFAULT] = '@';
}

bool defeat1() {
	bool defeat = false;

	if (head_position_x > SIZE - 1) {
		defeat = true;
	}

	else if (head_position_x < 0) {
		defeat = true;
	}

	else if (head_position_y > SIZE - 1) {
		defeat = true;
	}

	else if (head_position_y < 0) {
		defeat = true;
	}
	return defeat;
}

bool defeat2() {
	bool defeat = false;

	for (int i = 0; i < counter_of_tails; i++) {

		if ((head_position_x == old_pos[i].x) && (head_position_y == old_pos[i].y)) {
			defeat = true;
		}
	}
	return defeat;
}

void showStatistic(int steps) {
	cout << endl << endl << "    STATISTIC"
		<< endl << "apples eated: " << counter_of_tails - 2 << endl
		<< "length of snake: " << counter_of_tails + 1 << endl
		<< "walked steps: " << steps << WHITE << endl;
}