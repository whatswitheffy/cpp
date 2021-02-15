#include <iostream>
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan() {
        cin >> x;
        cin >> y;
    }
    void print() {
        cout << "(" << (double)x << "; " << (double)y << ")" << endl;
    }
};
    
int main() {
    Vector vec;
    cout.setf(ios::fixed);
    cout.precision(2);
    vec.scan();
    vec.print();
    return 0;
}
