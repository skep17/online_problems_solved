/*
https://www.hackerrank.com/challenges/anagram/problem
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

string del(string str, char ch){
    string result;
    int x;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ch){
           x = i;
           break;
        }
    }
    string s1 = str.substr(0,x);
    string s2 = str.substr(x+1);
    result = s1 + s2;
    return result;
}

// Complete the anagram function below.
int anagram(string s) {
    int result=0;
    if(s.size()%2 == 1){
        result = -1;
        return result;
    }
    string s1;
    string s2;
    s1 = s.substr(0,s.size()/2);
    s2 = s.substr(s.size()/2);
    result = s2.size();
    for(int i = 0; i < s1.size(); i++){
        if(contains(s2,s1[i])){
            s2 = del(s2,s1[i]);
            result--;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
