#include "myLinal.h"

int main() {
    Matrix matrix, matrix_, res;
    cout.setf(ios::fixed);
    cout.precision(2);
    Matrix m1(matrix.m);
    cin >> matrix_;
    res = matrix * matrix_;
    cout << res;
    return 0;
}