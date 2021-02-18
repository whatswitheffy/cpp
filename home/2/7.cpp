#include "myLinal.h"
int main() {
    Matrix mat;
    int num, k;
    cout.setf(ios::fixed);
    cout.precision(2);
    cin >> num;
    if(num == 0) {
        Matrix m();
        cout << mat;
    }
    if(num == 1) {
        cin >> k;
        Matrix m1(k);    
    }
    if(num == 9) {
        Matrix m1(mat.m);
        cout << mat;
    }
    return 0;
}