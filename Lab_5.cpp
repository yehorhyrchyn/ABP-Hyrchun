#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;
void lab_5() {
    cout << "Ви обрали лабораторну №5" << endl; 
    srand(time(NULL));
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 101 - 50;
    cout << "Масив:";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    int summad= 0;
    for (int i = 0; i < n - 1; i++) {
        int sum = arr[i];
        for (int j = i + 1; j < n; j++) {
            sum += arr[j];
            if (sum == 0) summad++;
        }
    }
    cout << "Кількість безперервних ділянок, сума яких = 0: " " "<< summad << endl;
}

  