#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x, y;
    void scan () {
        cin >> x;
        cin >> y;
    }
    void print() {
        cout << "(" << (double)x << "; " << (double)y << ")" << endl;
    }
    double lenght() {
        double len;
        len = sqrt(pow(x,2) + pow(y,2));
        return len;
    }
};

void printAll(Vector vec) {   
    vec.scan();
    cout << vec.lenght() << endl;
}

int main() {
    Vector vec;
    cout.setf(ios::fixed);
    cout.precision(2);
    printAll(vec);
    return 0;
}
