/*
https://www.spoj.com/problems/CMEXPR/
*/

#include <iostream>
#include <stack>

using namespace std;

bool isOp(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
	return false;
}

bool isBr(char ch) {
	if (ch == '(' || ch == ')') return true;
	return false;
}

short val(char ch) {
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	return 0;
}

void merge(stack <string>& st, char ch) {
	string b = st.top();
	st.pop();
	string a = st.top();
	st.pop();
	string nstr = a + ch + b;
	st.push(nstr);
}

bool checkPrev(stack <string>& st) {
	string grbg = st.top();
	st.pop();
	string chk = st.top();
	st.push(grbg);
	if (chk.size() > 1) return true;
	return false;
}

bool checkTop(stack <string>& st) {
	if (st.top().size() > 1) return true;
	return false;
}

string pstfx(string str) {
	string result = "";
	stack <char> st;
	for (int i = 0; i < str.size(); i++) {
		char ch = str[i];
		if (isBr(ch)) {
			if (ch == ')') {
				while (true) {
					char nch = st.top();
					st.pop();
					if (nch == '(') {
						break;
					}
					else result += nch;
				}
			}
			else st.push(ch);
		}
		else if (isOp(ch)) {
			if (!st.empty()) {
				char nchar = st.top();
				if (val(ch) > val(nchar)) {
					st.push(ch);
				}
				else {
					while (true) {
						if (st.empty()) break;
						char ops = st.top();
						if (ops == '(') {
							break;
						}
						else {
							st.pop();
							result += ops;
						}
						if (val(ch) == val(nchar)) break;
					}
					st.push(ch);
				}
			}
			else st.push(ch);
		}
		else {
			result += ch;
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

string infx(string str) {
	string result = "";
	stack < string > st;

	for (int i = 0; i < str.size();i++) {
		char ch = str[i];
		if (isOp(ch)) {
			bool fir = checkPrev(st);
			bool sec = checkTop(st);
			if ((fir || sec) && ch != '+') {
				if (sec) {
					string temp = st.top();
					int skip = 0;
					bool encircle = false;
					for (int k = 0; k < temp.size(); k++) {
						if (isOp(temp[k]) && skip == 0) {
							if (ch == '/' || val(temp[k]) == 1) {
								encircle = true;
								break;
							}
						}
						else if (isBr(temp[k])) {
							if (temp[k] == '(') {
								skip++;
							}
							else {
								skip--;
							}
						}
					}
					if (encircle) {
						st.pop();
						st.push('(' + temp + ')');
					}
				}
				if (fir) {
					string grbg = st.top();
					st.pop();
					string temp = st.top();
					st.pop();
					int skip = 0;
					bool encircle = false;
					for (int k = 0; k < temp.size(); k++) {
						if (isOp(temp[k]) && skip == 0) {
							if (val(ch) > val(temp[k])) {
								encircle = true;
								break;
							}
						}
						else if (isBr(temp[k])) {
							if (temp[k] == '(') {
								skip++;
							}
							else {
								skip--;
							}
						}
					}
					if (encircle) {
						temp = '(' + temp + ')';
					}
					st.push(temp);
					st.push(grbg);
				}
			}
			merge(st, ch);
		}
		else {
			string nstr = "";
			nstr += ch;
			st.push(nstr);
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	return result;
}

int main() {
	int data;
	cin >> data;

	for (int i = 0; i < data; i++) {
		string row;
		cin >> row;
		string result;
		result = pstfx(row);
		result = infx(result);
		cout << result << endl;
	}

	return 0;
}
