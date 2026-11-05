#include <iostream>
using namespace std;

#define MAX 100

int a[MAX + 1];
int n = 0;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void swim(int a[], int k) {
    while (k > 1 && a[k / 2] < a[k]) {
        swap(a[k], a[k / 2]);
        k = k / 2;
    }
}

void sink(int a[], int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k;
        if (j < n && a[j] < a[j + 1])
            j++;
        if (a[k] >= a[j])
            break;
        swap(a[k], a[j]);
        k = j;
    }
}

bool isEmpty() {
    return n == 0;
}

bool isFull() {
    return n == MAX;
}

void insert(int x) {
    if (isFull()) {
        cout << "Heap da day!\n";
        return;
    }

    a[++n] = x;
    swim(a, n);

    cout << "Da them " << x << " vao Heap.\n";
}

int getMax() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return -1;
    }

    return a[1];
}

int delMax() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return -1;
    }

    int max = a[1];

    swap(a[1], a[n]);
    n--;

    sink(a, n, 1);

    return max;
}

void display() {
    if (isEmpty()) {
        cout << "Heap rong!\n";
        return;
    }

    cout << "Heap: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    cout << endl;
}

void displayTree(int k, int level) {
    if (k > n)
        return;

    displayTree(2 * k + 1, level + 1);

    for (int i = 0; i < level; i++)
        cout << "    ";

    cout << a[k] << endl;

    displayTree(2 * k, level + 1);
}

