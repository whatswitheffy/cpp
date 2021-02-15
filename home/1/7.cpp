#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

struct Vector {
    double x, y;
    double len;
    void scan () {
        cin >> x;
        cin >> y;
    }
    bool isCollinear (const Vector &vec) {
        int crossResult = 0;
        Vector tmp;
        cin >> tmp.x >> tmp.y;
        crossResult = vec.x * tmp.y - tmp.x * vec.y;
        if(crossResult == 0) {
            return true;
        }
        else {
            return false;
        }
    }
   
};
void printAll(Vector vec) {
    if (vec.isCollinear(vec) == true) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }  
}
int main() {
    Vector vec;
    vec.scan();
    cout.setf(ios::fixed);
    cout.precision(2);
    printAll(vec);
    return 0;
}
