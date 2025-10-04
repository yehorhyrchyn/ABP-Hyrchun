#include <iostream>
#include <iomanip>
#include "Lab_1.cpp"

using namespace std;

int main() {
    int nomerLaboratornoi;
    cout << "Введіть номер лабораторної роботи: ";
    cin >> nomerLaboratornoi;

    switch (nomerLaboratornoi) {
        case 1:
            lab_1();
    }
            if (nomerLaboratornoi != 1){
                cout << "Невірне значення або лабораторна відсутня" << endl;
            }
    

    return 0;
}
