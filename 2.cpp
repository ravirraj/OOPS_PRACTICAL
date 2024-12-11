#include <iostream>
#include <string>
#include <cstring> 
#include <iomanip> 

using namespace std;

class person {
private:
    char name[40], dob[15], bdg[15];
    int h, w;
public:
    static int count;

    person() {
        
        h = w = 0;
    }

    static void recordcount() {
        cout << "\n Total no of records: " << count;
    }

    friend class personal;
};

class personal {
private:
    char add[70], telephone[15], policy_no[10];

public:
    personal() {
        strcpy(add, "");
        strcpy(telephone, "");
        strcpy(policy_no, "");
    }

    void getdata(person *obj);
    void displaydata(person *obj);
    friend class person;
};

int person::count = 0;

void personal::getdata(person *obj) {
    cout << "\nEnter Name of Person: ";
    cin.ignore(); 
    cin.getline(obj->name, 40);

    cout << "Enter date of birth of person (DD/MM/YYYY): ";
    cin >> obj->dob;

    cout << "Enter blood group of person: ";
    cin >> obj->bdg;

    cout << "Enter height and weight of person: ";
    cin >> obj->h >> obj->w;

    cout << "Enter Contact no of person: ";
    cin >> this->telephone;

    cout << "Enter address of person: ";
    cin.ignore(); 
    cin.getline(this->add, 70);

    cout << "Enter the insurance policy no: ";
    cin >> this->policy_no;

    obj->count++;
}

void personal::displaydata(person *obj) {
   
    cout << setw(20) << obj->name << setw(20) << obj->dob << setw(15) << obj->bdg
         << setw(10) << obj->h << setw(10) << obj->w << setw(20) << this->telephone
         << setw(15) << this->policy_no << setw(20) << this->add << endl;
}

int main() {
    personal *p1[30];
    person *p2[30];
    int n = 0, ch, i;

    do{
        cout << "\nMenu";
        cout << "\n1. Information of Person \n2. Display Information \n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nEnter The Information ";
            p1[n] = new personal;
            p2[n] = new person;
            p1[n]->getdata(p2[n]);
            n++;
            person::recordcount();
            break;

        case 2:
            cout << "\n";
            cout << "\n*****************************************************************************************************\n";
            cout << setw(20) << "NAME" << setw(20) << "DATE OF BIRTH" << setw(15) << "BLOOD GROUP"
                 << setw(10) << "HEIGHT" << setw(10) << "WEIGHT" << setw(20) << "TELEPHONE NO"
                 << setw(15) << "INSU.POLICYNO" << setw(20) << "ADDRESS" << endl;
            cout << "*****************************************************************************************************\n";

            for (i = 0; i < n; i++) {
                p1[i]->displaydata(p2[i]);
            }
            person::recordcount();
            break;
        }
    } while (ch != 3);

    for (i = 0; i < n; i++) {
        delete p1[i];
        delete p2[i];
    }

    return 0;
}
