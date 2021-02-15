#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan () {
        cin >> x;
        cin >> y;
    }
    void print () {
        cout << "(" << (double)x << "; " << (double)y << ")" << endl;
    }
    double lenght () {
        len = sqrt(pow(x,2) + pow(y,2));
        return len;
    }
    int quadrant () {
        int quad = 0;
        if (x > 0 && y > 0) {
            quad = 1;
        }
        if (x < 0 && y > 0) {
            quad = 2;
        }
        if (x < 0 && y < 0) {
            quad = 3;
        }
        if (x > 0 && y < 0) {
            quad = 4;
        }
        return quad;
    }
    void normalize () {
        Vector normalized;
        double invLen = 0;
        invLen = (1 / len);
        normalized.x = x * invLen;
        normalized.y = y * invLen;
        cout << "(" << (double)normalized.x << "; " << (double)normalized.y << ")" << endl;
    }
    double dot (const Vector &vec) {
        double scalar = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        scalar = vec.x * tmp.x + vec.y * tmp.y;
        return scalar;
    }
    int cross (const Vector &vec) {
        int crossResult = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        crossResult = vec.x * tmp.y - tmp.x * vec.y;
        return crossResult;
    }
    bool isCollinear (const Vector &vec) {
        int crossResult = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        crossResult = vec.x * tmp.y - tmp.x * vec.y;
        if(crossResult == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    Vector sum(const Vector &vec) {
        Vector tmp;
        Vector sum;
        cin >> tmp.x >> tmp.y;
        sum.x = tmp.x + vec.x;
        sum.y = tmp.y + vec.y;
        return sum;
    }
    Vector mult(double k) {
        Vector sum;
        sum.x = x * k;
        sum.y = y * k;
        return sum;
    }
    Vector rotate(double angle) {
        Vector rotated;
        rotated.x = x * cos(angle * (M_PI / 180)) - y * sin(angle * (M_PI / 180));
        rotated.y = x * sin(angle * (M_PI / 180)) + y * cos(angle * (M_PI / 180));
        return rotated;
    }
};

void printAll(Vector vec) {
    Vector resultForSum;
    Vector resultForMult;
    Vector rotatedVector;
    double k = 0;
    double angle = 0;
    vec.print();
    cout << vec.lenght() << endl;
    cout << vec.quadrant() << endl;
    vec.normalize();
    cout << vec.dot(vec) << endl;
    cout << vec.cross(vec) << endl;
    if (vec.isCollinear(vec) == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    resultForSum = vec.sum(vec);
    cout << "(" << resultForSum.x << "; " << resultForSum.y << ")" << endl;
    cin >> k;
    resultForMult = vec.mult(k);
    cout << "(" << resultForMult.x << "; " << resultForMult.y << ")" << endl;
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
