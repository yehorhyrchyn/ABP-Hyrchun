#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Detail10 {
private:
    string name;
    string type;
    unsigned short count;
    unsigned short weight;
public:
    Detail10() : name(""), type(""), count(0), weight(0) {}
    Detail10(const string& n, const string& t, unsigned short c, unsigned short w)
        : name(n), type(t), count(c), weight(w) {}
    void show() const {
        cout << "| " << left << setw(15) << name
             << "| " << left << setw(6)  << type
             << "| " << right << setw(10) << count
             << "| " << right << setw(10) << weight
             << " |" << endl;
    }
};

void lab_10() {
    cout << "Ви обрали лабораторну №10" << endl;

    Detail10 details[3];

    for (int i = 0; i < 3; i++) {
        string n, t;
        int c, w;
        cout << i + 1 << ". Введіть: Назва, Тип, Кількість, Вага > ";
        cin >> n >> t >> c >> w;
        details[i] = Detail10(n, t, c, w);
    }

    cout << "--------------------------------------------------------\n";
    cout << "| Найменування    |Тип   |  Кількість |   Вага (г)    |\n";
    cout << "--------------------------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        details[i].show();
    }

    cout << "--------------------------------------------------------\n";
}

