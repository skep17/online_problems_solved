/*
https://www.hackerrank.com/challenges/repeated-string/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count = 0;
    long pl = 0;
    long div = n/s.size();
    long rem = n%s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            count++;
            if(i<rem) pl++;
        }
    }
    return count*div + pl;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
