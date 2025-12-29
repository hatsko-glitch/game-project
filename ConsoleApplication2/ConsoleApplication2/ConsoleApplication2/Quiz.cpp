#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetColor() {
    setColor(7);
}

void quiz()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int a[45], n, k = 0;
    srand(time(NULL));

    cout << "============================================================================================================================================================" << endl;
    cout << endl;
    cout << endl;
    cout << "                                                                                ВИКТОРИНА" << endl;
    cout << "     Выберите тему:(1)Животные" << endl;
    cout << "                   (2)Здоровье" << endl;
    cout << "                   (3)Спорт" << endl;
    cout << endl;
    cout << endl;
    cout << "============================================================================================================================================================" << endl;
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "============================================================================================================================================================" << endl;
        cout << "        /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\          /\\_/\\" << endl;
        cout << "       ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )        ( o.o )" << endl;
        cout << "        > ^ <          > ^ <          > ^ <          > ^ <          > ^ <          > ^ <          > ^ <          > ^ <          > ^ <          > ^ <" << endl;
        cout << "============================================================================================================================================================" << endl;

        for (int i = 0; i < 5; i++)
        {
            a[i] = 1 + rand() % 10;

            bool duplicateFound = false;

            for (int j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    i--;
                    duplicateFound = true;
                    break;
                }
            }

            if (!duplicateFound) {
                cout << "\n[Вопрос " << (i + 1) << " из 5]" << endl;


                if (a[i] == 1) {
                    int g;
                    cout << "У какого животного есть полосы не только на шерсти, но и на коже?" << endl;
                    cout << "(1) У тигра" << endl;
                    cout << "(2) У льва" << endl;
                    cout << "(3) У бобра" << endl;
                    cout << "(4) У вороны" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }

                else if (a[i] == 4) {
                    int g;
                    cout << "Какого цвета кровь осьминога?" << endl;
                    cout << "(1) Зеленая" << endl;
                    cout << "(2) Красная" << endl;
                    cout << "(3) Желтая" << endl;
                    cout << "(4) Синяя" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 4) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 5) {
                    int g;
                    cout << "У кого самый густой мех из всех млекопитающих?" << endl;
                    cout << "(1) У овцы" << endl;
                    cout << "(2) У морской выдры" << endl;
                    cout << "(3) У речной выдры" << endl;
                    cout << "(4) У кита" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 6) {
                    int g;
                    cout << "Сколько сердец у осьминога?" << endl;
                    cout << "(1) 1" << endl;
                    cout << "(2) 2" << endl;
                    cout << "(3) 3" << endl;
                    cout << "(4) 4" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 7) {
                    int g;
                    cout << "Какое ракообразное может рычать, запугивая своих врагов?" << endl;
                    cout << "(1) Рак речной" << endl;
                    cout << "(2) Рак морской" << endl;
                    cout << "(3) Краб убийца" << endl;
                    cout << "(4) Краб призрак" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 4) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 8) {
                    int g;
                    cout << "Какой цвет кожи у белого медведя?" << endl;
                    cout << "(1) белый" << endl;
                    cout << "(2) черный" << endl;
                    cout << "(3) розовый" << endl;
                    cout << "(4) зеленый" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 9) {
                    int g;
                    cout << "Какое животное может есть только тогда, когда его голова перевернута?" << endl;
                    cout << "(1) Медведь" << endl;
                    cout << "(2) Лошадь" << endl;
                    cout << "(3) пингвин" << endl;
                    cout << "(4) фламинго" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 4) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 10) {
                    int g;
                    cout << "Какие сельскохозяйственные животные могут загорать?" << endl;
                    cout << "(1) Лошади" << endl;
                    cout << "(2) Овцы" << endl;
                    cout << "(3) Свиньи" << endl;
                    cout << "(4) Курицы" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 2) {
                    int g;
                    cout << "Какое животное самое быстрое на суше?" << endl;
                    cout << "(1) Гепард" << endl;
                    cout << "(2) Лев" << endl;
                    cout << "(3) Волк" << endl;
                    cout << "(4) Лошадь" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 3) {
                    int g;
                    cout << "Какое животное спит стоя?" << endl;
                    cout << "(1) Лошадь" << endl;
                    cout << "(2) Корова" << endl;
                    cout << "(3) Свинья" << endl;
                    cout << "(4) Собака" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }

                if (i < 4) {
                    cout << "\nНажмите Enter для следующего вопроса...";
                    cin.ignore();
                    cin.get();
                }
            }
        }


        cout << "\n==========================================" << endl;
        cout << "ВИКТОРИНА ЗАВЕРШЕНА!" << endl;
        cout << "Правильных ответов: " << k << " из 5" << endl;
        cout << "==========================================" << endl;

        break;

    case 2:
        cout << "============================================================================================================================================================" << endl;
        cout << "   <3     <3        <3     <3     <3         <3            <3            <3      <3       <3        <3             <3              <3              <3     <3" << endl;
        cout << " <3     <3      <3       <3    <3         <3          <3          <3        <3      <3        <3             <3              <3              <3         <3" << endl;
        cout << "     <3       <3      <3     <3     <3         <3            <3            <3      <3       <3        <3             <3              <3              <3     <3" << endl;
        cout << "============================================================================================================================================================" << endl;

        for (int i = 0; i < 5; i++)
        {
            a[i] = 1 + rand() % 10;

            bool duplicateFound = false;

            for (int j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    i--;
                    duplicateFound = true;
                    break;
                }
            }

            if (!duplicateFound) {
                cout << "\n[Вопрос " << (i + 1) << " из 5]" << endl;

                if (a[i] == 1) {
                    int g;
                    cout << "Сколько литров воды в день рекомендуется выпивать взрослому человеку?" << endl;
                    cout << "(1) 1-1.5 литра" << endl;
                    cout << "(2) 2-2.5 литра" << endl;
                    cout << "(3) 3-3.5 литра" << endl;
                    cout << "(4) 4-4.5 литра" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 2) {
                    int g;
                    cout << "Сколько часов сна нужно взрослому человеку в сутки?" << endl;
                    cout << "(1) 4-5 часов" << endl;
                    cout << "(2) 6-7 часов" << endl;
                    cout << "(3) 7-9 часов" << endl;
                    cout << "(4) 10-12 часов" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 3) {
                    int g;
                    cout << "Какие фрукты содержат больше всего витамина C?" << endl;
                    cout << "(1) Яблоки" << endl;
                    cout << "(2) Апельсины" << endl;
                    cout << "(3) Бананы" << endl;
                    cout << "(4) Груши" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 4) {
                    int g;
                    cout << "Сколько минут в день рекомендуется заниматься физической активностью?" << endl;
                    cout << "(1) 15 минут" << endl;
                    cout << "(2) 30 минут" << endl;
                    cout << "(3) 60 минут" << endl;
                    cout << "(4) 90 минут" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 5) {
                    int g;
                    cout << "Какая температура тела считается нормальной у человека?" << endl;
                    cout << "(1) 35.5°C" << endl;
                    cout << "(2) 36.6°C" << endl;
                    cout << "(3) 37.5°C" << endl;
                    cout << "(4) 38.0°C" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 6) {
                    int g;
                    cout << "Сколько раз в день нужно чистить зубы?" << endl;
                    cout << "(1) 1 раз" << endl;
                    cout << "(2) 2 раза" << endl;
                    cout << "(3) 3 раза" << endl;
                    cout << "(4) 4 раза" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 7) {
                    int g;
                    cout << "Какие овощи полезны для зрения?" << endl;
                    cout << "(1) Морковь" << endl;
                    cout << "(2) Картофель" << endl;
                    cout << "(3) Капуста" << endl;
                    cout << "(4) Лук" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 8) {
                    int g;
                    cout << "Сколько нужно мыть руки с мылом для эффективной очистки?" << endl;
                    cout << "(1) 5 секунд" << endl;
                    cout << "(2) 10 секунд" << endl;
                    cout << "(3) 20 секунд" << endl;
                    cout << "(4) 30 секунд" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 9) {
                    int g;
                    cout << "Какой витамин вырабатывается при воздействии солнечного света?" << endl;
                    cout << "(1) Витамин A" << endl;
                    cout << "(2) Витамин C" << endl;
                    cout << "(3) Витамин D" << endl;
                    cout << "(4) Витамин E" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 10) {
                    int g;
                    cout << "Сколько шагов в день рекомендуется проходить для здоровья?" << endl;
                    cout << "(1) 5,000 шагов" << endl;
                    cout << "(2) 8,000 шагов" << endl;
                    cout << "(3) 10,000 шагов" << endl;
                    cout << "(4) 15,000 шагов" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }

                if (i < 4) {
                    cout << "\nНажмите Enter для следующего вопроса...";
                    cin.ignore();
                    cin.get();
                }
            }
        }

        cout << "\n==========================================" << endl;
        cout << "ВИКТОРИНА ЗАВЕРШЕНА!" << endl;
        cout << "Правильных ответов: " << k << " из 5" << endl;
        cout << "==========================================" << endl;

        break;
    case 3:
        cout << "============================================================================================================================================================" << endl;
        cout << ":D          :D        :D     :D               :D         :D          :D           :D    :D             :D              :D    :D          :D          :D   :D" << endl;
        cout << "   :D          :D    :D     :D             :D         :D          :D           :D           :D             :D       :D           :D          :D    :D   :D" << endl;
        cout << ":D       :D           :D        :D           :D             :D          :D        :D           :D         :D              :D    :D        :D      :D  :D" << endl;

        cout << "============================================================================================================================================================" << endl;

        for (int i = 0; i < 5; i++)
        {
            a[i] = 1 + rand() % 10;

            bool duplicateFound = false;

            for (int j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    i--;
                    duplicateFound = true;
                    break;
                }
            }

            if (!duplicateFound) {
                cout << "\n[Вопрос " << (i + 1) << " из 5]" << endl;

                if (a[i] == 1) {
                    int g;
                    cout << "Сколько игроков в футбольной команде на поле?" << endl;
                    cout << "(1) 9" << endl;
                    cout << "(2) 10" << endl;
                    cout << "(3) 11" << endl;
                    cout << "(4) 12" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 2) {
                    int g;
                    cout << "Какой вид спорта называют 'королевой спорта'?" << endl;
                    cout << "(1) Футбол" << endl;
                    cout << "(2) Легкая атлетика" << endl;
                    cout << "(3) Плавание" << endl;
                    cout << "(4) Гимнастика" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 3) {
                    int g;
                    cout << "Сколько периодов в хоккейном матче?" << endl;
                    cout << "(1) 2" << endl;
                    cout << "(2) 3" << endl;
                    cout << "(3) 4" << endl;
                    cout << "(4) 5" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 4) {
                    int g;
                    cout << "В каком виде спорта используется ракетка и волан?" << endl;
                    cout << "(1) Теннис" << endl;
                    cout << "(2) Бадминтон" << endl;
                    cout << "(3) Сквош" << endl;
                    cout << "(4) Настольный теннис" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 5) {
                    int g;
                    cout << "Сколько кругов составляет марафонская дистанция?" << endl;
                    cout << "(1) 42 км 195 м" << endl;
                    cout << "(2) 21 км 97 м" << endl;
                    cout << "(3) 10 км" << endl;
                    cout << "(4) 5 км" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 6) {
                    int g;
                    cout << "Какой мяч самый большой в спорте?" << endl;
                    cout << "(1) Футбольный" << endl;
                    cout << "(2) Баскетбольный" << endl;
                    cout << "(3) Волейбольный" << endl;
                    cout << "(4) Медицинбол" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 7) {
                    int g;
                    cout << "Сколько очков дает трехочковый бросок в баскетболе?" << endl;
                    cout << "(1) 1 очко" << endl;
                    cout << "(2) 2 очка" << endl;
                    cout << "(3) 3 очка" << endl;
                    cout << "(4) 4 очка" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 3) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 8) {
                    int g;
                    cout << "В каком виде спорта используется шайба?" << endl;
                    cout << "(1) Футбол" << endl;
                    cout << "(2) Хоккей" << endl;
                    cout << "(3) Гандбол" << endl;
                    cout << "(4) Водное поло" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 9) {
                    int g;
                    cout << "Какой цвет имеет пояс высшего мастерства в дзюдо?" << endl;
                    cout << "(1) Черный" << endl;
                    cout << "(2) Красный" << endl;
                    cout << "(3) Белый" << endl;
                    cout << "(4) Коричневый" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 1) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }
                else if (a[i] == 10) {
                    int g;
                    cout << "Сколько игроков в волейбольной команде на площадке?" << endl;
                    cout << "(1) 5" << endl;
                    cout << "(2) 6" << endl;
                    cout << "(3) 7" << endl;
                    cout << "(4) 8" << endl;
                    cout << "Ваш ответ: ";
                    cin >> g;

                    if (g == 2) {
                        setColor(10);
                        cout << " ПРАВИЛЬНО!" << endl;
                        k++;
                        resetColor();
                    }
                    else {
                        setColor(12);
                        cout << " НЕПРАВИЛЬНО!" << endl;
                        resetColor();

                    }
                }

                if (i < 4) {
                    cout << "\nНажмите Enter для следующего вопроса...";
                    cin.ignore();
                    cin.get();
                }
            }
        }

        cout << "\n==========================================" << endl;
        cout << "ВИКТОРИНА ЗАВЕРШЕНА!" << endl;
        cout << "Правильных ответов: " << k << " из 5" << endl;
        cout << "==========================================" << endl;
        break;
    default:
        cout << " 1 - 3" << endl;
    }

    cout << "============================================================================================================================================================" << endl;
    cout << "        ^   ^          ^   ^          ^   ^          ^   ^          ^   ^          ^   ^          ^   ^          ^   ^          ^   ^          ^   ^" << endl;
    cout << "        (o o)          (^ ^)          (* *)          (+ +)          (~ ~)          (@ @)          (= =)          (- -)          (x x)          (. .)" << endl;
    cout << "         \\_/            \\_/            \\_/            \\_/            \\_/            \\_/            \\_/            \\_/            \\_/            \\_/" << endl;
    cout << "============================================================================================================================================================" << endl;

    cout << "\nНажмите Enter для выхода...";
    cin.ignore();
    cin.get();


}