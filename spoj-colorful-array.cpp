/*
https://www.spoj.com/problems/CLFLARR/
*/

#include <iostream>

using namespace std;


int main() {
	int elemNum, qNum, stElem, fnElem, color;
	cin >> elemNum;
	cin >> qNum;
	int data[qNum][3];
	for (int i = qNum - 1; i >=0; i--) {
		cin >> stElem;
		cin >> fnElem;
		cin >> color;
		data[i][0] = color;
		data[i][1] = stElem - 1;
		data[i][2] = fnElem - 1;
	}
	int painting[elemNum][2] = {0};
	for (int i = 0; i < qNum; i++) {
		for (int j = data[i][1]; j <= data[i][2]; j++) {
			if (painting[j][0] == 0) {
				painting[j][0] = data[i][0];
				painting[j][1] = data[i][2];
			}
			else {
				j = painting[j][1];
			}
		}
	}
	for (int i = 0; i < elemNum; i++) {
		cout << painting[i][0]<<endl;
	}
	return 0;
}
