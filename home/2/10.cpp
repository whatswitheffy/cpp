#include "myLinal.h" 
int main() {
    Vector vec;
    Vector result;
    cout.setf(ios::fixed);
    cout.precision(2);
    Matrix matrix;
    Matrix m1(matrix.m);
    cin >> vec;
    result = matrix * vec;
    cout << result; 
    return 0;
}