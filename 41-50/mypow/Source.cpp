#include <iostream>

using namespace std;

double myPow(double x, int n) {
    bool positive = n > 0 ? true : false;
    double result = 1;
    while (n != 0) {
        if (n & 1) {
            result *= x;
        }
        if (n == -1) {
            break;
        }
        n >>= 1;
        x *= x;
    }
    if (positive)
        return result;
    else
        return 1 / result;
}

int main() {
    cout << myPow((double)2, -6) << endl;
    return 0;
}