/*
https://www.hackerrank.com/challenges/two-strings
*/

#include <bits/stdc++.h>

using namespace std;

bool contains(string str, char ch){
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
            return true;
        }
    }
    return false;
}

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    string check = "";
    for(int i = 0; i < s1.size(); i++){
        if(!contains(check, s1[i])){
            check += s1[i];
            for(int j = 0; j < s2.size(); j++){
                if(s1[i] == s2[j]){
                    return "YES";
                }
            }
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
