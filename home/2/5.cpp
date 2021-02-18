#include "myLinal.h"
int main() {
    Vector vec, vec2, res;
    cout.setf(ios::fixed);
    cout.precision(2);
    cin >> vec;
    cin >> vec2;
    res = vec * 2 - vec2 / 3 + (vec * vec2);
    cout << res;
    return 0;
}