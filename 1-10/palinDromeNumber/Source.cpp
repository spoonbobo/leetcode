#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		long int temp = 0, temp2 = x;

		for (long int exp = 1; x / exp > 0; exp *= 10) {
			temp = temp * 10 + temp2 % 10;
			temp2 /= 10;
		}
		if (temp == x)
			return true;
		return false;
	}
};