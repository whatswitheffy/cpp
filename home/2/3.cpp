#include "1.h"
int main() {
    Vector vec, vec2, res, res2;
    double k = 0;
    cout.setf(ios::fixed);
    cout.precision(2);
    cin >> vec;
    cin >> k;
    res = vec * k;
    cout << res;
    res2 = vec / k;
    cout << res2;
    return 0;
}