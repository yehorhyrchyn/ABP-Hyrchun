#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void lab_7() {
    cout << "Ви обрали лабораторну №7" << endl;
struct Detail {
    string name;
    string type;
    unsigned short count;
    unsigned short weight;
};
    Detail d[3]; //Масив

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". Введіть: Назва, Тип, Кількість, Вага > ";
        cin >> d[i].name >> d[i].type >> d[i].count >> d[i].weight;
    }
//Вивід таблиці
    cout << "-----------------------------------------------\n";
    cout << "|             Відомість деталей               |\n";
    cout << "|---------------------------------------------|\n";
    cout << "| Найменування  | Тип | Кількість | Вага в (г)|\n";
    cout << "|---------------|-----|-----------|-----------|\n";
    for (int i = 0; i < 3; i++) {
        cout << "|" << setw(13) << d[i].name
             << " | " << setw(3) << d[i].type
             << " | " << setw(9) << d[i].count
             << " | " << setw(9) << d[i].weight
             << " |\n";
    }
    cout << "|---------------------------------------------|\n";
    cout << "| Примітка: О – оригінальна; П – покупна;     |\n";
    cout << "| З - запозичена                              |\n";
    cout << "-----------------------------------------------" << endl;
}

