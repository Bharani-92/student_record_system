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
    int choice, searchId;
    bool found;

    while (true) {
        cout << "\n1. Add\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
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

        
        else if (choice == 3) {
            cout << "Enter ID to search: ";
            cin >> searchId;

            ifstream fin("data.txt");
            found = false;

            while (fin.read((char*)&s, sizeof(s))) {
                if (s.id == searchId) {
                    cout << "Student Found:\n";
                    s.display();
                    found = true;
                }
            }

            if (!found)
                cout << "Student not found\n";

            fin.close();
        }

        
        else if (choice == 4) {
            cout << "Enter ID to delete: ";
            cin >> searchId;

            ifstream fin("data.txt");
            ofstream fout("temp.txt");

            found = false;

            while (fin.read((char*)&s, sizeof(s))) {
                if (s.id != searchId) {
                    fout.write((char*)&s, sizeof(s));
                } else {
                    found = true;
                }
            }

            fin.close();
            fout.close();

            remove("data.txt");
            rename("temp.txt", "data.txt");

            if (found)
                cout << "Student deleted\n";
            else
                cout << "Student not found\n";
        }

        else {
            break;
        }
    }

    return 0;
}
