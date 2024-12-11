#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee {
public:
    string name;
    int identity;
    double salary;

    void accept() {

        cout << endl << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> identity;
        cout << "Enter salary (in Rs.): ";
        cin >> salary;
    }

    void display() {
        cout << endl << "Name: " << name << endl;
        cout << "ID: " << identity << endl;
        cout << "Salary: Rs. " << fixed << setprecision(2) << salary << endl;
    }

    void writeToFile(ofstream &f) {
        f << setw(20) << left << "Name:" << name << endl;
        f << setw(20) << left << "ID:" << identity << endl;
        f << setw(20) << left << "Salary (Rs.):" << fixed << setprecision(2) << salary << endl;
        f << "----------------------------------------" << endl;
    }

    void readFromFile(ifstream &f) {
        getline(f, name);
        f >> identity;
        f >> salary;
        f.ignore();
    }
};

void openFun() {
    Employee o[5];
    int i, n;

    cout << endl << "FILE OPERATION USING open() FUNCTION." << endl;

    ofstream outf("info.txt", ios::out);
    if (!outf) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    outf << "==========================================" << endl;
    outf << "          EMPLOYEE INFORMATION           " << endl;
    outf << "==========================================" << endl;
    outf << setw(20) << left << "Name"
         << setw(10) << left << "ID"
         << setw(20) << left << "Salary (Rs.)" << endl;
    outf << "------------------------------------------" << endl;

    cout << endl << "Enter total employees: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << endl << "Enter information of employee no.: " << i + 1 << endl;
        o[i].accept();
        o[i].writeToFile(outf);
    }

    outf.close();

    ifstream inf("info.txt", ios::in);
    if (!inf) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    cout << endl << "Information stored in file:" << endl;

    cout << setw(20) << left << "Name"
         << setw(10) << left << "ID"
         << setw(20) << left << "Salary (Rs.)" << endl;
    cout << "------------------------------------------" << endl;

    for (i = 0; i < n; i++) {
        cout << setw(20) << left << o[i].name
             << setw(10) << left << o[i].identity
             << setw(20) << left << fixed << setprecision(2) << o[i].salary << endl;
    }

    inf.close();
}

int main() {
    openFun();
    return 0;
}
