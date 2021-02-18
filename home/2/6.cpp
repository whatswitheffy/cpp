#include "myLinal.h"

int main() {
    Vector vec;
    char ch;
    cout.setf(ios::fixed);
    cout.precision(2);
    cin >> vec;
    cin >> ch;
    cout << vec.operator[](ch);
}