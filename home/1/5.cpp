#include <iostream>
using namespace std;

struct Vector {
    double x, y;

    void scan() {
        cin >> x;
        cin >> y;
    }
    double dot(const Vector &vec) {
        double scalar = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        scalar = vec.x * tmp.x + vec.y * tmp.y;
        return scalar;
    } 
};

int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << vec.dot(vec) << endl;
    return 0;
}
