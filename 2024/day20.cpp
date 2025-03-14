#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    array<int, 2> st = {0, 0};
    array<int, 2> en = {0, 0};
    vector<string> map;
    string line;
    while(cin >> line){
        map.push_back(line);
    }
    int n = map.size();
    int m = map[0].size();
    for(int i =0 ; i <n ;i++){
        for(int j =0 ; j < m; j++){
            if(map[i][j] == 'S'){
                st = {i, j};
            }
            if(map[i][j] == 'E'){
                en= {i, j};
            }
        }
    }

    vector<vector<int>> timeToEnd (n, vector<int>(m, -1));
    int depth = 0;
    queue<array<int, 2>> q;
    q.push(en);
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        if (timeToEnd[x][y] != -1) continue;
        timeToEnd[x][y] = depth;
        for (auto [dx, dy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#') {
                q.push({nx, ny});
            }
        }
        depth++;
    }

    int timeNormal = timeToEnd[st[0]][st[1]];
    cout << "timenormal: " << timeNormal << endl;
    
    q.push(st);
    depth = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<set<pair<int, int>>>> ans(n, vector<set<pair<int, int>>>(m));
    while(q.size()){
        auto [x, y] = q.front();
        q.pop();
        visited[x][y] = true;

        for (auto [dx, dy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            // for (auto [ddx, ddy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                // int nnx = nx + ddx, nny = ny + ddy;
                
                for (auto [newx, newy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                    int lastx = nx + newx, lasty = ny + newy;
                    if (lastx >= 0 && lastx < n && lasty >= 0 && lasty < m && map[lastx][lasty] != '#') {
                        if(timeNormal - (depth + timeToEnd[lastx][lasty] + 2) >= 100){
                            ans[nx][ny].insert({lastx, lasty});
                        }
                    }
                }
            // }
        }
        for (auto [dx, dy] : vector<array<int, 2>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#') {
                if(!visited[nx][ny]){
                    q.push({nx, ny});
                }
            }
        }
        depth++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += ans[i][j].size();
            // for (const auto& p : ans[i][j]) {
            //     cout << "(" << i << ", " << j << ") -> (" << p.first+1 << ", " << p.second+1 << ")" << endl;
            // }
        }
    }
    cout << cnt << endl;
}