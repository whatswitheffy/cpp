#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan() {
        cin >> x;
        cin >> y;
    }
    double length() {
        len = sqrt(pow(x,2) + pow(y,2));
        return len;
    }
    void normalize() {
        Vector normalized;
        double invLen = 0;
        invLen = (1 / len);
        normalized.x = x * invLen;
        normalized.y = y * invLen;
        cout << "(" << normalized.x << "; " << normalized.y << ")" << endl;
    }
    
};

int main() {
    Vector vec;
    vec.scan();
    vec.length();
    cout.setf(ios::fixed);
    cout.precision(2);
    vec.normalize();
    return 0;
}
