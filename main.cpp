#include "std_lib_facilities.h"
using namespace std;

int main() {

    double a, b, c;

    cout << "Enter a, b, and c of a quadratic equation :  ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "It is not a quadratic equation, a cannot be zero.";
        return 0;
    }

    if (((b*b)-4*a*c) < 0) {
        cout << "The root cannot be calculated since the discriminant is less than zero.";
        return 0;
    }

    if (((b*b)-4*a*c) == 0) {
        int res = -b / (2*a);
        cout << "The result is: " << res;
    }

    if (((b*b)-4*a*c) > 0) {
        int res1 = -b + sqrt(((b*b)-4*a*c)) / (2*a);
        int res2 = -b - sqrt(((b*b)-4*a*c)) / (2*a);
        cout << "The results are: " << res1 << " and " << res2;
    }

    return 0;
}