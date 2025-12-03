#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void lab2_2() {
    cout << "Ви обрали лабораторну №2.2" << endl;  
    double term, sum = 0;        
    const double min = 0.000001; 
    int n;                        
    short sign = 1;               
    for (n = 0; ; n++) {
        if (n % 2 == 0) {
            sign = 1;
        }
        else{
            sign = -1;
        }
        term = sign * ((pow(n,2) + 1) / (pow(n, 3) + 2));
        if (fabs(term) >= min) {
            sum += term;
            if (n == 9) {
                cout << "Сума 10 членів ряду: " << fixed << setprecision(6) << sum << endl;
            }
        } else {
            break;
        }
    }
    cout << "Повна сума ряду: " << sum << endl;
    cout << "Ітерацій: " << n << endl;
}