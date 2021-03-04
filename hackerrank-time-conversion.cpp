/*
https://www.hackerrank.com/challenges/time-conversion/problem
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string result;
    bool conv;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == 'P'){
            conv = true;
            break;
        } else if(s[i] == 'A'){
            conv = false;
            break;
        }
        result += s[i];
    }
    if(conv){
        if(result.substr(0,2) == "12"){
            return result;
        }
        char c;
        c = result[0];
        c += 1;
        result[0] = c;
        c = result[1];
        c += 2;
        result[1] = c;
    } else if(result[0] == '1'){
        char c;
        c = result[0];
        c -= 1;
        result[0] = c;
        c = result[1];
        c -= 2;
        result[1] = c;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
