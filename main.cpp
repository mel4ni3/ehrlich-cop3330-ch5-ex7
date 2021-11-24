#include "std_lib_facilities.h"
using namespace std;

void instabilityCheck(double res, double instability) {
    // check for instability
    if (res > 0 && res > instability) {
        cout << "\n" << res << " is too large, it is bigger than the instability benchmark\n";
    }

    else if (res < -instability) {
        cout << "\n" << res << " is too small, it is smaller than the instability checkmark\n";
    }
}

int main() {

    double a, b, c;
    double instability = 1.0e-6;

    // get input from user and initialize variables
    cout << "Enter a, b, and c of a quadratic equation :  ";
    cin >> a >> b >> c;

    // check for coefficients of zero
    if (a == 0) {
        if (b == 0)
            cout << "Both a and b are zero, so the root cannot be determined.\n";
        else {
            cout << "The result is : " << -c/b;
            instabilityCheck(-c/b, instability);
        }
        return 0;
    }

    if (b == 0) {
        if (-(c/a) == 0)
            cout << "The result is: 0\n";
        else if (-(c/a) < 0)
            cout << "The root cannot be calculated since there are only imaginary roots.\n";
        else {
            double res1 = -sqrt(-c/a);
            double res2 = sqrt(-c/a);
            cout << "The results are: " << res1 << " and " << res2;
            instabilityCheck(res1, instability);
            instabilityCheck(res2, instability);
        }

    }

    // check the discriminant
    if (((b*b)-4*a*c) < 0) {
        cout << "The root cannot be calculated since the discriminant is less than zero.";
        return 0;
    }

    if (((b*b)-4*a*c) == 0) {
        double res = -b / (2*a);
        cout << "The result is: " << res;
        instabilityCheck(res, instability);
    }

    if (((b*b)-4*a*c) > 0) {
        double res1 = -b + sqrt(((b*b)-4*a*c)) / (2*a);
        double res2 = -b - sqrt(((b*b)-4*a*c)) / (2*a);
        cout << "The results are: " << res1 << " and " << res2;
        instabilityCheck(res1, instability);
        instabilityCheck(res2, instability);
    }




    return 0;
}