#include <iostream>

using namespace std;

int main() {
	int base = 2;
	int exp = 5;

	while (exp != 0) {
		cout << exp << endl;
		cout << (exp >> 1) << endl << endl;
		if (exp & 1) {
			cout << base << endl;
		}
		exp >>= 1;
		base *= base;
	}

	return 0;
}