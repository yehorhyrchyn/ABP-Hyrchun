#include <iostream>
#include <iomanip>
#include <string>
#include "Lab_1.cpp"
#include "Lab_2.1.cpp"
#include "Lab_2.2.cpp"
#include "Lab_3.cpp"
#include "Lab_4.cpp"
#include "Lab_5.cpp"
#include "Lab_6.cpp"
#include "Lab_7.cpp"
#include "Lab_8.cpp"
#include "Lab_9.cpp"
#include "Lab_10.cpp"
#include "Lab_13.cpp"
#include "Lab_14.cpp"
using namespace std;
int main() {
    string nomerLaboratornoi;
    cout << "Введіть номер лабораторної ";
    cin >> nomerLaboratornoi;

    if (nomerLaboratornoi == "1")
        lab_1();
    else if (nomerLaboratornoi == "2.1")
        lab2_1();
    else if (nomerLaboratornoi == "2.2")
        lab2_2();
    else if (nomerLaboratornoi == "3")
        lab_3();
    else if (nomerLaboratornoi == "4")
        lab_4();
    else if (nomerLaboratornoi == "5")
        lab_5();
    else if (nomerLaboratornoi == "6")
        lab_6();
    else if (nomerLaboratornoi == "7")
        lab_7();
    else if (nomerLaboratornoi == "8")
        lab_8();
    else if (nomerLaboratornoi == "9")
        lab_9();
    else if (nomerLaboratornoi == "10")
        lab_10();
    else if (nomerLaboratornoi == "13")
        Lab_13();
    else if (nomerLaboratornoi == "14")
        Lab_14();                                        
    else
        cout << "Невірне значення або лабораторна відсутня" << endl;

    return 0;
}
