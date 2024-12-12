// #include "bits/stdc++.h"

// using namespace std;

// set<pair<int, int>> visited;
// int ans = 0;

// void ff(int i, int j, int n, int m, vector<string> &arr, int prev){
//     if(i < 0 || i >= n || j < 0 || j >=m )
//         return;
//     // cout << arr[i][j] - '0' << endl;
//     if((arr[i][j] - '0') != prev-1) return;
//     if((arr[i][j] - '0' == 0 && !visited.count({i, j}))){ ans++; visited.insert({i, j}); return;}

//     ff(i+1, j, n, m, arr, arr[i][j] - '0');
//     ff(i-1, j, n, m, arr, arr[i][j] - '0');
//     ff(i, j+1, n, m, arr, arr[i][j] - '0');
//     ff(i, j-1, n, m, arr, arr[i][j] - '0');
// }

// int main(){
//     freopen("input.txt", "r", stdin);
//     vector<string> arr;
//     string str;
//     while(cin >> str){
//         arr.push_back(str);

//     }
//     int n = arr.size();
//     int m = arr[0].size();

//     for(int i = 0; i < n;i ++){
//         for(int j = 0; j < m; j++){
//             if(arr[i][j] == '9'){
//                 visited.clear();
//                 ff(i, j, n, m, arr, 10);
//             }

//         }
//     }
//     cout << ans << endl;
// }
#include "bits/stdc++.h"

using namespace std;

// set<pair<int, int>> visited;
int ans = 0;

void ff(int i, int j, int n, int m, vector<string> &arr, int prev){
    if(i < 0 || i >= n || j < 0 || j >=m )
        return;
    // cout << arr[i][j] - '0' << endl;
    if((arr[i][j] - '0') != prev-1) return;
    if(arr[i][j] - '0' == 0 ){ ans++;  return;}

    ff(i+1, j, n, m, arr, arr[i][j] - '0');
    ff(i-1, j, n, m, arr, arr[i][j] - '0');
    ff(i, j+1, n, m, arr, arr[i][j] - '0');
    ff(i, j-1, n, m, arr, arr[i][j] - '0');
}

int main(){
    freopen("input.txt", "r", stdin);
    vector<string> arr;
    string str;
    while(cin >> str){
        arr.push_back(str);

    }
    int n = arr.size();
    int m = arr[0].size();

    for(int i = 0; i < n;i ++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '9'){
                ff(i, j, n, m, arr, 10);
            }

        }
    }
    cout << ans << endl;
}