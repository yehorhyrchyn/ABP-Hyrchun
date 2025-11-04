#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void lab2_1() {
    cout << "Ви обрали лабораторну №2.1" << endl;   
    float y ,x ;
    cout << "Введіть x: ";
    cin >> x;
    cout << endl;
    cout << "Введіть y: ";
    cin >>y;
    cout << '('<< x<< ')' << '('<< y <<')' << endl;
if (x >= 0 && y >= 0 && y <= 1 - x) {
    cout << "Точка потрапляє в область" << endl;
}
else if (y <= 0 && x >= 0 && y >= -1 + x) {
    cout << "Точка потрапляє в область" << endl;
}
else if (y==0.5 && x==-0.5){
    cout << "Точка потрапляє в область" << endl;
}
else {
    cout << "Точка не потрапляє в область" << endl;
}

    }