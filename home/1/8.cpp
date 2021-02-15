#include <iostream>
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan () {
        cin >> x;
        cin >> y;
    }
    Vector sum(const Vector &vec) {
        Vector tmp;
        Vector sum;
        cin >> tmp.x >> tmp.y;
        sum.x = tmp.x + vec.x;
        sum.y = tmp.y + vec.y;
        return sum;
    }
};
int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    Vector resultForSum;
    resultForSum = vec.sum(vec);
    cout << "(" << resultForSum.x << "; " << resultForSum.y << ")" << endl;
    return 0;
}
