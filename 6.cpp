#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    string name;
    string birthDate;
    string phoneNumber;

    Person(string n, string b, string p) : name(n), birthDate(b), phoneNumber(p) {}

    void display() const {
        cout << "Name: " << name << ", Birth Date: " << birthDate << ", Phone: " << phoneNumber << endl;
    }

    bool operator<(const Person& p) const {
        return name < p.name;
    }
};

class Item {
public:
    int code;
    string name;
    int quantity;
    float cost;

    Item(int c, string n, int q, float co) : code(c), name(n), quantity(q), cost(co) {}

    void display() const {
        cout << "Code: " << code << ", Name: " << name << ", Quantity: " << quantity << ", Cost: Rs. " << cost << endl;
    }

    bool operator<(const Item& i) const {
        return code < i.code;
    }
};

int main() {
    vector<Person> persons;
    vector<Item> items;
    int choice;

    do {
        cout << "\n***** Menu *****\n";
        cout << "1. Insert Person\n";
        cout << "2. Insert Item\n";
        cout << "3. Display Persons\n";
        cout << "4. Display Items\n";
        cout << "5. Search Person\n";
        cout << "6. Search Item\n";
        cout << "7. Sort Persons by Name\n";
        cout << "8. Sort Items by Code\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, birthDate, phone;
            cout << "\nEnter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Birth Date (DD/MM/YYYY): ";
            getline(cin, birthDate);
            cout << "Enter Phone Number: ";
            getline(cin, phone);
            persons.push_back(Person(name, birthDate, phone));
        }
        else if (choice == 2) {
            int code, quantity;
            string name;
            float cost;
            cout << "\nEnter Item Code: ";
            cin >> code;
            cout << "Enter Item Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Cost: ";
            cin >> cost;
            items.push_back(Item(code, name, quantity, cost));
        }
        else if (choice == 3) {
            cout << "\nPersons:\n";
            for (const auto& p : persons) {
                p.display();
            }
        }
        else if (choice == 4) {
            cout << "\nItems:\n";
            for (const auto& i : items) {
                i.display();
            }
        }
        else if (choice == 5) {
            string name;
            cout << "\nEnter Name to search: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (const auto& p : persons) {
                if (p.name == name) {
                    p.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Person not found.\n";
            }
        }
        else if (choice == 6) {
            int code;
            cout << "\nEnter Item Code to search: ";
            cin >> code;
            bool found = false;
            for (const auto& i : items) {
                if (i.code == code) {
                    i.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item not found.\n";
            }
        }
        else if (choice == 7) {
            sort(persons.begin(), persons.end());
            cout << "\nPersons sorted by Name:\n";
            for (const auto& p : persons) {
                p.display();
            }
        }
        else if (choice == 8) {
            sort(items.begin(), items.end());
            cout << "\nItems sorted by Code:\n";
            for (const auto& i : items) {
                i.display();
            }
        }
        else if (choice == 9) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
