#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;
void lab_3() {
    cout << "Ви обрали лабораторну №3" << endl;
    srand(time(NULL));
    const int SIZE = 200;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand()% 101 -50;
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
        if (i % 25 == 0 && i != 0) {
            cout << endl;
        }
    }
    int count = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] * arr[i + 1] < 0) { 
            count++;
        }
    }
    cout << endl;
    cout << "Кількість пар з протилежними знаками: " << count << endl;
}
        