// #include "bits/stdc++.h"

// using namespace std;
// vector<string> arr;
// using ll = long long;
// int dp[150][150][4];

// // right, top, left, bot
// int dx []{0, -1, 0, 1};
// int dy []{1, 0, -1, 0};

// void dfs(int i, int j, int dir, int n, int m){
//     if(i < 0 || j < 0 || i >= n || j >= m) return;
//     if(arr[i][j] == '#') return;

//     int newi = i + dx[dir];
//     int newj = j + dy[dir];
//     if(dp[newi][newj][dir] >= dp[i][j][dir] + 1){
//         dp[newi][newj][dir] = dp[i][j][dir] + 1;
//         dfs(newi, newj, dir, n, m);
//     }

//     int td = (dir + 1)%4;
//     if(dp[i][j][td] >= dp[i][j][dir] + 1000){
//         dp[i][j][td] = dp[i][j][dir] + 1000;
//         dfs(i, j, td, n, m);
//     }
//     td = (dir - 1+4)%4;
//     if(dp[i][j][td] >= dp[i][j][dir] + 1000){
//         dp[i][j][td] = dp[i][j][dir] + 1000;
//         dfs(i, j, td, n, m);
//     }
// }


// int main(){
//     freopen("input.txt", "r", stdin);
//     string s;
//     while(cin >> s){
//         arr.push_back(s);
//     }
//     int n = arr.size();
//     int m = arr[0].size();

//     pair<int, int> start;
    
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = INT_MAX;
//             if(arr[i][j] == 'S')
//                 start = {i, j};
//         }
//     }
//     dp[start.first][start.second][0] = 0;
//     dfs(start.first, start.second, 0, n, m);
    
//     int ans = INT_MAX;
//     for(int i = 0 ; i < 4; i++){
//         ans = min(ans, dp[1][m-2][i]);
//     }

//     cout << ans << endl;
// }

// p2
#include "bits/stdc++.h"

using namespace std;
vector<string> arr;
using ll = long long;
int dp[150][150][4];
set<pair<int, int>> res;
int ans = INT_MAX;

// right, top, left, bot
int dx []{0, -1, 0, 1};
int dy []{1, 0, -1, 0};

void dfs(int i, int j, int dir, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(arr[i][j] == '#') return;

    int newi = i + dx[dir];
    int newj = j + dy[dir];
    if(dp[newi][newj][dir] >= dp[i][j][dir] + 1){
        dp[newi][newj][dir] = dp[i][j][dir] + 1;
        dfs(newi, newj, dir, n, m);
    }

    int td = (dir + 1)%4;
    if(dp[i][j][td] >= dp[i][j][dir] + 1000){
        dp[i][j][td] = dp[i][j][dir] + 1000;
        dfs(i, j, td, n, m);
    }
    td = (dir - 1+4)%4;
    if(dp[i][j][td] >= dp[i][j][dir] + 1000){
        dp[i][j][td] = dp[i][j][dir] + 1000;
        dfs(i, j, td, n, m);
    }
}


bool dfs2(int i, int j, int dir, int n, int m, int score){
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    if(arr[i][j] == '#') return false;
    if(arr[i][j] == 'E'){
        res.insert({i, j});
        return true;
    }
    bool found = false;
    int newi = i + dx[dir];
    int newj = j + dy[dir];
    if(dp[newi][newj][dir] >= dp[i][j][dir] + 1){
        dp[newi][newj][dir] = dp[i][j][dir] + 1;
        found |= dfs2(newi, newj, dir, n, m, score +1);
    }

    int td = (dir + 1)%4;
    if(dp[i][j][td] >= dp[i][j][dir] + 1000){
        dp[i][j][td] = dp[i][j][dir] + 1000;
        found |= dfs2(i, j, td, n, m, score + 1000);
    }
    td = (dir - 1+4)%4;
    if(dp[i][j][td] >= dp[i][j][dir] + 1000){
        dp[i][j][td] = dp[i][j][dir] + 1000;
        found |= dfs2(i, j, td, n, m, score + 1000);
    }

    if(found)
        res.insert({i, j});
    return found;
}


int main(){
    freopen("input.txt", "r", stdin);
    string s;
    while(cin >> s){
        arr.push_back(s);
    }
    int n = arr.size();
    int m = arr[0].size();

    pair<int, int> start;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = INT_MAX;
            if(arr[i][j] == 'S')
                start = {i, j};
        }
    }
    dp[start.first][start.second][0] = 0;
    dfs(start.first, start.second, 0, n, m);
    
    for(int i = 0 ; i < 4; i++){
        ans = min(ans, dp[1][m-2][i]);
    }

    cout << ans << endl;

    dfs2(start.first, start.second, 0, n, m, 0);

    cout << res.size() << endl;
}