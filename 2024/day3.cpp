#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    smatch matches;
    string str;
    int ans = 0;
    while(cin >> str){
        while (regex_search(str, matches, pattern)) {
            ans += stoi(matches[1]) * stoi(matches[2]);
            str = matches.suffix().str();
        }
    }
    cout << ans << endl;
}