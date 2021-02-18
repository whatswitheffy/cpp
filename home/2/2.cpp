#include "myLinal.h"

int main(void) {
    Vector vec, vec2, res, res2;
    cout.setf(ios::fixed);
    cout.precision(2);
    cin >> vec >> vec2;
    res = vec + vec2;
    cout << res;
    res2 = vec - vec2;
    cout << res2;
    return 0;
}
