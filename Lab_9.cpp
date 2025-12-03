#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

struct Detail {
    char name[50];
    char type[50];
    char count[50];
    char weight[50];
};

int UnicodeLength(const char* str) {
    return strlen(str);
}

void DisplayTable(Detail* table, int size) {
    string separator(64, '_');
    string separator2(64, '-');

    cout << separator << endl;
    cout << "| " << left << setw(15) << "Назва"
         << "| " << left << setw(15) << "Тип"
         << "| " << left << setw(15) << "Кількість"
         << "| " << left << setw(15) << "Вага (г)"
         << "|" << endl;
    cout << separator2 << endl;

    for (int i = 0; i < size; ++i) {
        cout << "| " << left << setw(15) << table[i].name
             << "| " << left << setw(15) << table[i].type
             << "| " << left << setw(15) << table[i].count
             << "| " << left << setw(15) << table[i].weight
             << "|" << endl;
        cout << separator2 << endl;
    }
}

void AddRecord(Detail* table, int& recordCount, const Detail& newRecord) {
    if (recordCount < 50) {
        table[recordCount] = newRecord;
        recordCount++;
        cout << "Новий запис додано." << endl;
    } else {
        cout << "Досягнуто максимальну кількість записів." << endl;
    }
}

void DeleteRecord(Detail* table, int& recordCount, int indexToDelete) {
    if (indexToDelete >= 0 && indexToDelete < recordCount) {
        for (int i = indexToDelete; i < recordCount - 1; ++i) {
            table[i] = table[i + 1];
        }
        recordCount--;
        cout << "Рядок видалено." << endl;
    } else {
        cout << "Некоректний індекс рядка для видалення." << endl;
    }
}

void lab_9() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "Відомість деталей (ЛР9 — масив структур)" << endl;

    const int maxRecords = 50;
    Detail table[maxRecords];
    int recordCount = 0;

    ifstream inputFile("Lab_9.txt");
    if (inputFile) {
        Detail record;
        while (inputFile.getline(record.name, 50) &&
               inputFile.getline(record.type, 50) &&
               inputFile.getline(record.count, 50) &&
               inputFile.getline(record.weight, 50))
        {
            AddRecord(table, recordCount, record);
        }
        inputFile.close();
    }

    int choice;
    while (true) {
        cout << "\nОберіть опцію:\n";
        cout << "1. Вивести таблицю\n";
        cout << "2. Додати рядок\n";
        cout << "3. Видалити рядок\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            DisplayTable(table, recordCount);
        }
        else if (choice == 2) {
            Detail newRecord;
            cout << "Введіть назву: "; cin.getline(newRecord.name, 50);
            cout << "Введіть тип: "; cin.getline(newRecord.type, 50);
            cout << "Введіть кількість: "; cin.getline(newRecord.count, 50);
            cout << "Введіть вагу (г): "; cin.getline(newRecord.weight, 50);
            AddRecord(table, recordCount, newRecord);
        }
        else if (choice == 3) {
            int index;
            cout << "Введіть індекс рядка для видалення: ";
            cin >> index;
            DeleteRecord(table, recordCount, index);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Некоректний вибір. Спробуйте ще раз." << endl;
        }
    }

    ofstream outputFile("Lab_9.txt");
    for (int i = 0; i < recordCount; ++i) {
        outputFile << table[i].name << '\n'
                   << table[i].type << '\n'
                   << table[i].count << '\n'
                   << table[i].weight << '\n';
    }
    outputFile.close();
}
