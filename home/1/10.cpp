#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

struct Vector {
    double x, y;
    void scan () {
        cin >> x;
        cin >> y;
    }
    Vector rotate(double angle) {
        Vector rotated;
        rotated.x = x * cos(angle * (M_PI / 180)) - y * sin(angle * (M_PI / 180));
        rotated.y = x * sin(angle * (M_PI / 180)) + y * cos(angle * (M_PI / 180));
        return rotated;
    }
};

void printAll(Vector vec) {
    Vector rotatedVector;
    double angle = 0;
    cin >> angle;
    rotatedVector = vec.rotate(angle);
    cout << "(" << rotatedVector.x << "; " << rotatedVector.y << ")" << endl;
}
int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    printAll(vec);
    return 0;
}
