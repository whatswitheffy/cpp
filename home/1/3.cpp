#include <iostream>
using namespace std;

struct Vector {
    double x, y;
    void scan() {
        cin >> x;
        cin >> y;
    }
    int quadrant() {
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
};

int main() {
    Vector vec;
    cout.setf(ios::fixed);
    cout.precision(2);
    vec.scan();
    cout << vec.quadrant() << endl;
    return 0;
}
