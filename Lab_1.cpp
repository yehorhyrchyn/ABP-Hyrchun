#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void lab_1() {
    cout << "Ви обрали лабораторну №1" << endl; 


string name1, name2 , name3;

string sc1, sc2, sc3;

unsigned short cnt1, cnt2, cnt3;//usigned short бо кількість не може бути від'ємною

unsigned short sq1, sq2, sq3; //використовую short бо вага в граммах не потрбіне дробове

/* Введення  даних */

cout << "1. Введіть: Назва ,Тип, Кількість, Вага > ";

cin >>name1 >> sc1 >> cnt1 >> sq1;

cout << "2.  Введіть: Назва ,Тип, Кількість, Вага > ";

cin >>name2 >> sc2 >> cnt2 >> sq2;

cout << "3.  Введіть: Назва ,Тип, Кількість, Вага > ";

cin >>name3 >> sc3 >> cnt3 >> sq3;

/* Виведення таблиці */

cout << "-----------------------------------------------\n";
cout << "|             Відомість деталей               |\n";
cout << "|---------------------------------------------|\n";
cout << "| Найменування  | Тип | Кількість | Вага в (г)|\n";
cout << "|---------------|-----|-----------|-----------|\n";

/*  данні */

cout << "|" << setw(5) << name1 << "        | " << sc1 << "   | " << setw(3) << cnt1

<< "       | " << setw(9) << fixed << setprecision(1) << sq1 << " | " << endl;

cout << "|"<< setw(5) << name2 << "        | " << sc2 << "   | " << setw(3) << cnt2

<< "       | " << setw(9) << fixed << setprecision(1) << sq2 << " | " << endl;

cout << "|" << setw(5) << name3 << "        | " << sc3 << "   | " << setw(3) << cnt3

<< "       | " << setw(9) << fixed << setprecision(3) << sq3 << " | " << endl;

/*  примітки */
cout << "|---------------------------------------------|" << endl;
cout << "| Примітка: О – оригінальна;П – покупна;      |" << endl;
cout << "| З - запозичена                              |" << endl;
cout << "-----------------------------------------------" << endl;
}