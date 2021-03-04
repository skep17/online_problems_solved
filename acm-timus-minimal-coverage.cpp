/*
https://acm.timus.ru/problem.aspx?space=1&num=1303
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

using namespace std;

int comp(const void* a, const void* b) {
	if (*(int*)a < *(int*)b) {
		return -1;
	}
	else if (*(int*)a == *(int*)b) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {

	int m, lb, rb;
	int data[100000][2];
	int result[100000][2];
	int count = 0;
	int power = 0;

	cin >> m;
	while (true) {
		cin >> lb;
		cin >> rb;
		if (lb == 0 && rb == 0) break;
		data[count][0] = lb;
		data[count][1] = rb;
		count++;
	}

	qsort((void*)data, count, 2 * sizeof(int), comp);

	int check = 0;
	bool zero = 1;
	bool br = 0;
	for (int i = 0; i < count; i++) {
		if (br == 1) break;
		if (data[i][0] <= check) {
			zero = 1;
			for (int j = i; j < count; j++) {
				int curLb = data[j][0];
				int curRb = data[j][1];

				if (curLb <= check && curRb >= check) {
					if (zero == 1) {
						result[power][0] = curLb;
						result[power][1] = curRb;
						power++;
						if (m <= result[power - 1][1]) br = 1;
						zero = 0;
					}
					else {
						if (result[power - 1][1] < curRb) {
							result[power - 1][0] = curLb;
							result[power - 1][1] = curRb;
							if (m <= result[power - 1][1]) br = 1;
						}
					}
				}
				if (curLb > check) {
					check = result[power - 1][1];
					i = j - 1;
					break;
				}
			}
		}
	}
	if (result[power - 1][1] < m) cout << "No solution" << endl;
	else {
		cout << power << endl;
		for (int k = 0; k < power; k++) {
			cout << result[k][0] << " " << result[k][1] << endl;
		}
	}
	return 0;
}
