#include <iostream>

using namespace std;

// linear exponentiation
// x^n = x * x^n-1
// to handle negative n, we use fact that x^n = 1 / x^-n

double myPowLinearExponentiation(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPowLinearExponentiation(x, -n);
    return x * myPowLinearExponentiation(x, n - 1);
}

// binary exponentiation (recursive)
// https://leetcode.com/problems/powx-n/editorial/
// key idea is x^n can be rewritten as
// (x^2)^(n/2) if n is even
// x * (x^2)^((n-1)/2)

double myPowBinaryExponentiation(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPowBinaryExponentiation(x, -n);
    if (n % 2 == 0) 
        return myPowBinaryExponentiation(x * x, n / 2);
    else
        return x * myPowBinaryExponentiation(x * x, (n-1) / 2);
}

// check iterative on above editorial

int main() {
    cout << myPowBinaryExponentiation((double)2, -6) << endl;
    return 0;
}