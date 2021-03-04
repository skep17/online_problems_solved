/*
https://www.spoj.com/problems/AIBOHP/
*/

#include <iostream>

using namespace std;

int findPal(string str) {
	int len = str.size();
	int table[len][len];
	for (int i = 0; i < len; i++) {
		table[i][i] = 1;
		if (i < len - 1) table[i][i + 1] = 0;
	}
	for (int k = 1; k < len; k++) {
		for (int i = 0; i+k < len; i++) {
			if (str[i] == str[i + k]) {
				table[i + k][i] = table[i + k - 1][i + 1] + 2;
			}
			else {
				if (table[i + k - 1][i] > table[i + k][i + 1]) {
					table[i + k][i] = table[i + k - 1][i];
				}
				else {
					table[i + k][i] = table[i + k][i + 1];
				}
			}
		}
	}
	return table[len - 1][0];
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int result = str.size() - findPal(str);
		cout << result << endl;
	}

	return 0;
}
