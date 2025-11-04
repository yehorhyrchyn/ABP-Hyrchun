#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void lab_4() {
    cout << "Ви обрали лабораторну №4" << endl; 
    const int n = 9;
    int array[n][n] = {0};
    int num = 1;
    int row = n / 2;
    int col = n / 2;
    array[row][col] = num++;
    int topRow = row, bottomRow = row;
    int leftCol = col, rightCol = col;
    while (topRow > 0 || bottomRow < n - 1 || leftCol > 0 || rightCol < n - 1) {
        if (leftCol > 0) leftCol--;
        if (topRow > 0) topRow--;
        if (rightCol < n - 1) rightCol++;
        if (bottomRow < n - 1) bottomRow++;
        //  Вліво 
        for (int i = col - 1; i >= leftCol; i--) {
            array[row][i] = num++;
        }
        col = leftCol;
        //  Вниз 
        for (int i = row + 1; i <= bottomRow; i++) {
            array[i][col] = num++;
        }
        row = bottomRow;
        //  Вправо 
        for (int i = col + 1; i <= rightCol; i++) {
            array[row][i] = num++;
        }
        col = rightCol;
        //  Вгору 
        for (int i = row - 1; i >= topRow; i--) {
            array[i][col] = num++;
        }
        row = topRow;
    }
    for (int i = 0; i < n; i++) {
        if (array[0][i] == 0) {
            array[0][i] = num++;
        }
    }
    cout << "Заповнення по спіралі з центру проти годинникової стрілки:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}