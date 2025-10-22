#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void lab_1() {
    cout << "Ви обрали лабораторну №1" << endl; 
    float znakX=0,znakY=0,ploshcha=0;
    cout << "Введіть координату X: ";
    cin >> znakX;
    cout << "Введіть координату Y: ";
    cin >> znakY;
    ploshcha = znakX * znakY / 2;
    cout << "Площа трикутника = " << ploshcha << endl;      



}

