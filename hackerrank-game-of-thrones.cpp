/*
https://www.hackerrank.com/challenges/game-of-thrones/problem
*/

#include <bits/stdc++.h>

using namespace std;

int contains(string str, char ch){
    int result = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
            result++;
        }
    }
    return result;
}

bool contain(string str, char ch){
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
            return true;
        }
    }
    return false;
}

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    string result;
    string check = "";
    int center = 0;
    char cenchar = ';';
    int len = s.size();
    if(len%2 == 0){
        center++;
    }
    for(int i = 0; i < s.size(); i++){
        int curr;
        if(!contain(check,s[i])){
            check+= s[i];
            curr = contains(s,s[i]);
            if(curr%2 == 1 && cenchar != s[i]){
            center++;
            cenchar = s[i];
            }
            if(center > 1){
                result = "NO";
                return result;
            }
        }
    }
    result = "YES";
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
