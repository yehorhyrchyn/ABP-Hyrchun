#include <iostream>
#include <iomanip>
#include <string>
#include <stack> 
using namespace std;
void lab_8() {
    cout << "Ви обрали лабораторну №8" << endl;
    struct Detail {
        string name;
        string type;
        unsigned short count;
        unsigned short weight;
    };
    stack<Detail> details; 
    for (int i = 0; i < 3; i++) {
        Detail d;
        cout << i + 1 << ". Введіть: Назва, Тип, Кількість, Вага > ";
        cin >> d.name >> d.type >> d.count >> d.weight;
        details.push(d); 
    }
    // Вивід 
    cout << "-----------------------------------------------\n";
    cout << "|             Відомість деталей               |\n";
    cout << "|---------------------------------------------|\n";
    cout << "| Найменування  | Тип | Кількість | Вага в (г)|\n";
    cout << "|---------------|-----|-----------|-----------|\n";
    while (!details.empty()) {
        Detail d = details.top(); // верхній елемент
        details.pop(); // видаляємо 

        cout << "|" << setw(13) << d.name
             << " | " << setw(3) << d.type
             << " | " << setw(9) << d.count
             << " | " << setw(9) << d.weight
             << " |\n";
    }
    cout << "|---------------------------------------------|\n";
    cout << "| Примітка: О – оригінальна; П – покупна;     |\n";
    cout << "| З - запозичена                              |\n";
    cout << "-----------------------------------------------" << endl;
}
