/*
https://www.spoj.com/problems/NDIV/
*/

#include <iostream>
#include <math.h>
using namespace std;

int getValue(int a) {
	int result = 0;
	int root = (int) sqrt(a);
	for (int i = 1; i <= root; i++) {
		if (a % i == 0) result+=2;
	}
	if (root * root == a) result--;
	return result;
}

int main() {
	int lowBound;
	int upBound;
	int div;
	cin >> lowBound;
	cin >> upBound;
	cin >> div;
	int result = 0;
	for (lowBound; lowBound <= upBound; lowBound++) {
		if (getValue(lowBound) == div) result++;
	}
	cout << result << endl;
	return 0;
}
