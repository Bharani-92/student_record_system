#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    char name[50];

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
    }

    void display() {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

int main() {
    Student s;
    int choice;

    while (true) {
        cout << "\n1. Add\n2. Display\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            ofstream fout("data.txt", ios::app);
            s.input();
            fout.write((char*)&s, sizeof(s));
            fout.close();
        }

        else if (choice == 2) {
            ifstream fin("data.txt");
            while (fin.read((char*)&s, sizeof(s))) {
                s.display();
            }
            fin.close();
        }

        else {
            break;
        }
    }

    return 0;
}