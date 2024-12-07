#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    string str;
    vector<string> map;

    while(cin >> str){
        map.push_back(str);
    }

    int n = map.size();
    int m = map[0].size();
    
    int ans = 0;

    int starti, startj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '^'){
                starti = i;
                startj = j;
            }
        }
    }
    int curi = starti, curj = startj;

    int dx []{-1, 0, 1, 0};
    int dy []{0, 1, 0, -1};

    int dir = 0;
    
    while(curi >= 0 && curi < n && curj >= 0 && curj < m){
        if(map[curi][curj] != 'X'){
            map[curi][curj] = 'X';
            ans++;
        }

        int newi = curi + dx[dir];
        int newj = curj + dy[dir];
        if(newi >= 0 && newi < n && newj >= 0 && newj < m && map[newi][newj] == '#'){
            dir = (dir+1)%4;
            continue;
        }
        curi = newi;
        curj = newj;
    }

    cout << ans << endl;

    // part 2:
    set<pair<int, int>> s;
    bool visited[n][m][4];
    dir = 0;
    curi = starti;
    curj = startj;

    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == starti && j == startj) || (map[i][j] == '#')){
                continue ;
            }

            map[i][j] = '#';

            memset(visited, false, sizeof(visited));
            dir = 0;
            curi = starti;
            curj = startj;

            while(curi >= 0 && curi < n && curj >= 0 && curj < m){
                if(visited[curi][curj][dir])
                    break;
                visited[curi][curj][dir] = true;
                int newi = curi + dx[dir];
                int newj = curj + dy[dir];
                if(newi >= 0 && newi < n && newj >= 0 && newj < m && map[newi][newj] == '#'){
                    dir = (dir+1)%4;
                    continue;
                }
                curi = newi;
                curj = newj;
            }

            if(curi >= 0 && curi < n && curj >= 0 && curj < m){
                s.insert({i, j});
            }       

            map[i][j] = '.';
        }
    }

    cout << s.size() << endl;
}