#include <iostream>
using namespace std;

struct Vector {
    double x, y;

    void scan () {
        cin >> x;
        cin >> y;
    }
    Vector mult(double k) {
        Vector sum;
        sum.x = x * k;
        sum.y = y * k;
        return sum;
    }
};
void printAll(Vector vec) {
    Vector resultForMult;
    double k = 0;
    cin >> k;
    resultForMult = vec.mult(k);
    cout << "(" << resultForMult.x << "; " << resultForMult.y << ")" << endl;
}

int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    printAll(vec);
    return 0;
}
