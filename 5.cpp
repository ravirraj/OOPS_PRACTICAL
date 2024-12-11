#include<iostream>
using namespace std;

int n;
#define size 10

template<class T>
void sel(T A[size]) {
    int i, j, min;
    T temp;

    for(i = 0; i < n - 1; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    cout << "\nSorted array: ";
    for(i = 0; i < n; i++) {
        cout << " " << A[i];
    }
}

int main() {
    int choice;
    int A[size];
    float B[size];
    int i;

    do {
        cout << "\n-----------------------";
        cout << "\n1. Integer";
        cout << "\n2. Float";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter Total Number Of Integer Elements: ";
            cin >> n;
            cout << "\nEnter Integer Elements: ";
            for(i = 0; i < n; i++) {
                cin >> A[i];
            }
            sel(A);
        } 
        else if (choice == 2) {
            cout << "\nEnter Total Number Of Float Elements: ";
            cin >> n;
            cout << "\nEnter Float Elements: ";
            for(i = 0; i < n; i++) {
                cin >> B[i];
            }
            sel(B);
        } 
        else if (choice == 3) {
            cout << "**********Program Exited Successfully**********" << endl;
        } 
        else {
            cout << "\nInvalid choice. Please try again.";
        }

    } while(choice != 3);

    return 0;
}
