#include <iostream>
#include <iomanip>
#include "Lab_1.cpp"
#include "Lab_2_1.cpp"
using namespace std;

int main() {
    int nomerLaboratornoi;
    cout << "Введіть номер лабораторної роботи: ";
    cin >> nomerLaboratornoi;
    switch (nomerLaboratornoi) {
        case 1:
            lab_1();
            break;
        case 2:
            lab2_1();
            break;
            if (nomerLaboratornoi >2){
                cout << "Невірне значення або лабораторна відсутня" << endl;
            }  
        }
    return 0;
}