#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float price;
public:
    publication() {
        title = "";
        price = 0.0;
    }
    
    publication(string t, float p) {
        title = t;
        price = p;
    }

    void inputPublicationData() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }
};

class book : public publication {
    int pagecount;
public:
    book() {
        pagecount = 0;
    }

    book(string t, float p, int pc) : publication(t, p) {
        pagecount = pc;
    }

    void inputBookData() {
        inputPublicationData();
        cout << "Enter page count: ";
        cin >> pagecount;
        cin.ignore();
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Page count: " << pagecount << endl;
    }
};

class CD : public publication {
    float time;
public:
    CD() {
        time = 0.0;
    }

    CD(string t, float p, float tim) : publication(t, p) {
        time = tim;
    }

    void inputCDData() {
        inputPublicationData();
        cout << "Enter time in minutes: ";
        cin >> time;
        cin.ignore();
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Time in minutes: " << time << endl;
    }
};

int main() {
    cout << endl << "Enter Book Data:" << endl;
    book b;
    b.inputBookData();
    b.display();
    
    cout << endl << "Enter CD Data:" << endl;
    CD c;
    c.inputCDData();
    c.display();

    return 0;
}
