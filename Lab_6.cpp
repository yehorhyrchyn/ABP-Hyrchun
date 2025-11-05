#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int** Matrix(int n) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}
void Center(int** array, int n) {
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
        for (int i = col - 1; i >= leftCol; i--) {
            array[row][i] = num++;
        }
        col = leftCol;
        for (int i = row + 1; i <= bottomRow; i++) {
            array[i][col] = num++;
        }
        row = bottomRow;
        for (int i = col + 1; i <= rightCol; i++) {
            array[row][i] = num++;
        }
        col = rightCol;
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
}
void print(int** array, int n) {
    cout << "\nЗаповнення по спіралі з центру проти годинникової стрілки:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << array[i][j];
        }
        cout << endl;
    }
}
void lab_6() {
    cout << "Ви обрали лабораторну №6" << endl; 
    int n;
    cout << "Введіть розмірність непареоматриці ";
    cin >> n;
    if (n % 2 == 0) {
        cout << " Для центру потрібна непарна матриця " << endl;
        return;
    }
    int** matrix = Matrix(n);
    Center(matrix, n);
    print(matrix, n);
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}