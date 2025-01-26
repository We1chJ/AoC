// #include "bits/stdc++.h"
// using namespace std;

// void dfs(int i, int j, vector<vector<int>> &arr, int dis){
//     if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
//         return;
//     if(arr[i][j] == -1) return;
//     if(dis != 0 && arr[i][j] <= dis) return;

//     cout << i << " " << j << endl;
//     arr[i][j] = dis;
//     dfs(i+1, j, arr, dis+1);
//     dfs(i-1, j, arr, dis+1);
//     dfs(i, j+1, arr, dis+1);
//     dfs(i, j-1, arr, dis+1);    
// }

// int main(){
//     freopen("input.txt", "r", stdin);
//     int n = 71;
//     int m = 71;
//     vector<vector<int>> arr (n, vector<int>(m, INT_MAX));
//     string str;
//     int cnt =  1024;
//     while(cin >> str){
//         int a, b;
//         a = stoi(str.substr(0, str.find(',')));
//         b = stoi(str.substr(str.find(',') + 1));
//         if(cnt > 0){
//             arr[b][a] = -1;
//             cnt--;
//         }
//     }
//     vector<vector<int>> visited (n, vector<int>(m, 0));
//     arr[0][0] = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(arr[i][j] == -1)
//                 cout << '#';
//             else
//                 cout << '.';
//         }
//         cout << endl;
//     }
//     dfs(0, 0, arr, 0);
//     cout << arr[n-1][m-1] << endl;
// }

// pt2 binary search


#include "bits/stdc++.h"
using namespace std;

void dfs(int i, int j, vector<vector<int>> &arr, int dis){
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
        return;
    if(arr[i][j] == -1) return;
    if(dis != 0 && arr[i][j] <= dis) return;

    // cout << i << " " << j << endl;
    arr[i][j] = dis;
    dfs(i+1, j, arr, dis+1);
    dfs(i-1, j, arr, dis+1);
    dfs(i, j+1, arr, dis+1);
    dfs(i, j-1, arr, dis+1);    
}

int main(){
    freopen("input.txt", "r", stdin);
    int n = 71;
    int m = 71;
    vector<array<int, 2>> blocks;
    string str;
    while(cin >> str){
        int a, b;
        a = stoi(str.substr(0, str.find(',')));
        b = stoi(str.substr(str.find(',') + 1));
        blocks.push_back({a, b});
    }

    int l = 0, r = blocks.size();
    while(l < r){
        vector<vector<int>> arr (n, vector<int>(m, INT_MAX));
        int mid = (l+r+1)/2;
        for(int i =0 ;i < mid; i++){
            auto [a, b] = blocks[i];
            arr[a][b] = -1;
        }
        arr[0][0] = 0;
        dfs(0, 0, arr, 0);
        if(arr[n-1][m-1] != INT_MAX){
            l = mid;
        }else{
            r = mid-1;
        }
        cout << arr[n-1][m-1] << endl;
    }
    cout << blocks[l][0] << "," << blocks[l][1] << endl;
}