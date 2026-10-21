#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int n = 0;

int getAt(int index) {
    if (index < 0 || index >= n) {
        cout << "Index khong hop le" << endl;
        return -1;
    }
    return arr[index];
}

void getIdArr(int index) {
    if (index >= 0 && index < n) {
        cout << arr[index] << endl;
    } else {
        cout << "Index khong hop le" << endl;
    }
}

void insertFirst(int x) {
    if (n >= MAX) {
        cout << "Mang day" << endl;
        return;
    }
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
}

void insertLast(int x) {
    if (n >= MAX) {
        cout << "Mang day" << endl;
        return;
    }
    arr[n] = x;
    n++;
}

void insertValue(int x, int index) {
    if (n >= MAX) {
        cout << "Mang day" << endl;
        return;
    }
    if (index < 0 || index > n) {
        cout << "Index khong hop le" << endl;
        return;
    }
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = x;
    n++;
}

void deleteFirst() {
    if (n <= 0) {
        cout << "Mang rong" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void deleteLast() {
    if (n <= 0) {
        cout << "Mang rong" << endl;
        return;
    }
    n--;
}

void deleteIdArr(int index) {
    if (n <= 0) {
        cout << "Mang rong" << endl;
        return;
    }
    if (index < 0 || index >= n) {
        cout << "Index khong hop le" << endl;
        return;
    }
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void printForward() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printReverse() {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
