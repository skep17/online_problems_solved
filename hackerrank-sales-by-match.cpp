/*
https://www.hackerrank.com/challenges/sock-merchant/problem
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool contains( int x, vector <int> y){
    for(int i = 0; i < y.size(); i++){
        if(y[i] == x)
            return true;
    }
    return false;
}


// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    int result = 0;
    int count = 0;
    vector<int> s;
    for(int i = 0; i < ar.size(); i++){
        if(!contains(ar[i], s)){
            s.push_back(ar[i]);
            for(int j = 0; j < ar.size(); j++){
                if(ar[j] == ar[i]){
                    count++;
                }
            }
            result += count/2;
            count = 0;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
