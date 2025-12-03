#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm> 

using namespace std;

// ==============================================
// 1. Клас Dynamic2DArray (Динамічний Двовимірний Масив)
// ==============================================
class Dynamic2DArray {
private:
    int** arr;
    int numRows; 
    int numCols;
    int maxRows; 
    int maxCols;

public:
    // --- Конструктори та Деструктор ---

    // 1. Конструктор за замовчуванням
    Dynamic2DArray() : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {}

    // 2. Конструктор з параметрами
    Dynamic2DArray(int rows, int cols) : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {
        allocateArray(rows, cols); 
    }

    // 3. Конструктор копіювання (Глибоке копіювання)
    Dynamic2DArray(const Dynamic2DArray& other) : arr(nullptr), numRows(0), numCols(0), maxRows(0), maxCols(0) {
        copyFrom(other);
    }

    // Деструктор (Звільнення пам'яті)
    ~Dynamic2DArray() {
        clearArray();
    }
    
    // Оператор присвоєння копіюванням (Глибоке копіювання)
    Dynamic2DArray& operator=(const Dynamic2DArray& other) {
        if (this == &other) {
            return *this;
        }
        clearArray();
        copyFrom(other);
        return *this;
    }

    // --- Функції ---

    // Запис елемента масиву.
    void setValue(int row, int col, int value) {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Індекс вийшов за межі масиву.");
        }
        arr[row][col] = value;
    }

    // Одержання елемента масиву.
    int getValue(int row, int col) const {
        if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
            throw out_of_range("Індекс вийшов за межі масиву.");
        }
        return arr[row][col];
    }

    // Виведення масиву на екран.
    void printArray() const {
        if (numRows == 0 || numCols == 0) {
            cout << "Масив порожній." << endl;
            return;
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }

    // Пошук максимального елемента.
    int findMax() const {
        if (numRows == 0 || numCols == 0) {
            throw runtime_error("Масив порожній.");
        }
        int maxVal = arr[0][0];
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (arr[i][j] > maxVal) {
                    maxVal = arr[i][j];
                }
            }
        }
        return maxVal;
    }

    // Пошук мінімального елемента.
    int findMin() const {
        if (numRows == 0 || numCols == 0) {
            throw runtime_error("Масив порожній.");
        }
        int minVal = arr[0][0];
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (arr[i][j] < minVal) {
                    minVal = arr[i][j];
                }
            }
        }
        return minVal;
    }

    // --- Інформація про розміри ---
    int getMaxRows() const { return maxRows; }
    int getMaxCols() const { return maxCols; }
    int getCurrentRows() const { return numRows; }
    int getCurrentCols() const { return numCols; }

private:
    // Виділення пам'яті
    void allocateArray(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            throw invalid_argument("Розміри мають бути додатними.");
        }

        clearArray(); 

        maxRows = rows;
        maxCols = cols;
        numRows = rows;
        numCols = cols;

        arr = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            arr[i] = new int[numCols];
        }
    }

    // Глибоке копіювання даних
    void copyFrom(const Dynamic2DArray& other) {
        if (other.arr == nullptr) return;

        allocateArray(other.maxRows, other.maxCols);

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                arr[i][j] = other.arr[i][j]; 
            }
        }
    }

    // Звільнення пам'яті
    void clearArray() {
        if (arr) {
            for (int i = 0; i < numRows; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
            numRows = 0;
            numCols = 0;
            maxRows = 0;
            maxCols = 0;
        }
    }
};

// ==============================================
// 2. Головна функція для демонстрації (int main)
// ==============================================
void Lab_14() {
    cout << "=== Динамічний Двовимірний Масив (Варіант №4) ===" << endl;

    // 1. Конструктор з параметрами та Запис/Одержання елементів
    Dynamic2DArray array(3, 4); 

    // Заповнення масиву тестовими даними
    int counter = 1;
    for (int i = 0; i < array.getCurrentRows(); ++i) {
        for (int j = 0; j < array.getCurrentCols(); ++j) {
            array.setValue(i, j, counter++);
        }
    }
    array.setValue(2, 3, 100); 
    array.setValue(0, 0, -5); 

    cout << "\n--- Створений масив ---" << endl;
    array.printArray();

    // 2. Інформація про розміри
    cout << "\n--- Інформація про розміри ---" << endl;
    cout << "Макс. рядків: " << array.getMaxRows() << ", Макс. стовпців: " << array.getMaxCols() << endl;
    cout << "Поточні рядки: " << array.getCurrentRows() << ", Поточні стовпці: " << array.getCurrentCols() << endl;
    cout << "Отримання елемента [1][2]: " << array.getValue(1, 2) << endl;

    // 3. Пошук максимального та мінімального елемента
    cout << "\n--- Пошук Min/Max ---" << endl;
    cout << "Максимальне значення: " << array.findMax() << endl;
    cout << "Мінімальне значення: " << array.findMin() << endl;

    // 4. Демонстрація Конструктора копіювання та Оператора присвоєння
    cout << "\n--- Демонстрація копіювання ---" << endl;
    
    // Конструктор копіювання
    Dynamic2DArray arrayCopy = array; 
    arrayCopy.setValue(0, 0, 999); 

    cout << "Оригінальний масив [0][0]: " << array.getValue(0, 0) << endl;
    cout << "Масив-копія [0][0]: " << arrayCopy.getValue(0, 0) << endl;

    // Оператор присвоєння
    Dynamic2DArray arrayAssignment;
    arrayAssignment = array;
    
    cout << "Масив, отриманий присвоєнням:" << endl;
    arrayAssignment.printArray();

    return ;
}