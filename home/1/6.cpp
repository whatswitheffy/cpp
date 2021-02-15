#include <iostream>
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan () {
        cin >> x;
        cin >> y;
    }
    int cross (const Vector &vec) {
        int crossResult = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        crossResult = vec.x * tmp.y - tmp.x * vec.y;
        return crossResult;
    }
};

int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << vec.cross(vec) << endl;
    return 0;
}
