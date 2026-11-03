#include <iostream>
using namespace std;

int a[1000], n = 0;

void heapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(largest);
    }
}

void push(int x) {
    a[n] = x;
    n++;

    int i = n - 1;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (a[p] >= a[i]) break;
        swap(a[p], a[i]);
        i = p;
    }
}

void pop() {
    if (n == 0) return;
    a[0] = a[n - 1];
    n--;
    if (n > 0) heapify(0);
}

int top() {
     if (n > 0) {
        return a[0];
    }
    else {
        return -1;
    }
}
