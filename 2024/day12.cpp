#include "bits/stdc++.h"
using namespace std;

using ll = long long;
ll pere = 0;
ll area = 0;

int dx[] {0, -1, 0, 1};
int dy[] {-1, 0, 1, 0};

map<int, set<int>> rows, cols;


void ff(int i, int j, int n, int m, vector<string> &v, vector<vector<bool>> &visited, char letter){
    if(visited[i][j])
        return;
    visited[i][j] = true;
    if(!rows.count(i)) rows[i] = set<int>();
    rows[i].insert(j);
    if(!cols.count(j)) cols[j] = set<int>();
    cols[j].insert(i);

    area++;
    for(int a = 0; a < 4; a++){
        int ni = i + dx[a];
        int nj = j + dy[a];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m){
            if(v[ni][nj] == letter){
                ff(ni, nj, n, m, v, visited, letter);
                continue;
            }
        }
        pere ++;
    }

}

int main(){
    freopen("input.txt", "r", stdin);

    vector<string> v;
    string str;
    while(cin >> str){
        v.push_back(str);
    }
    int n = v.size();
    int m = v[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    ll ans = 0;
    ll ans2 = 0;
    
    for(int i  = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(!visited[i][j]){
                char character = v[i][j];
                rows.clear();
                cols.clear();
                pere = area = 0;
                ff(i, j, n, m, v, visited, v[i][j]);
                ans += pere * area;


                // for pt 2
                ll sides = 0;
                // left
                for(auto &a : cols){
                    // rows
                    auto &vr = a.second;
                    int prev = -2;
                    for(auto &r : vr){
                        if(a.first == 0 || v[r][a.first-1] != character){
                            if(r - prev > 1){
                                sides++;
                            }
                            prev = r;
                        }
                    }
                }

                // right
                for(auto &a : cols){
                    auto &vr = a.second;
                    int prev = -2;
                    for(auto &r : vr){
                        if(a.first == m-1 || v[r][a.first+1] != character){
                            if(r - prev > 1){
                                sides++;
                            }
                            prev = r;
                        }
                        
                    }
                }

                // top
                for(auto &a : rows){
                    auto &vc = a.second;
                    int prev = -2;
                    for(auto &c : vc){
                        if(a.first == 0 || v[a.first-1][c] != character){
                            if(c - prev > 1){
                                sides++;
                            }
                            prev = c;
                        }
                    }
                }

                // bottom
                for(auto &a : rows){
                    auto &vc = a.second;
                    int prev = -2;
                    for(auto &c : vc){
                        if(a.first == n-1 || v[a.first+1][c] != character){
                            if(c - prev > 1){
                                sides++;
                            }
                            prev = c;
                        }
                    }
                }                
                cout << character << " " << sides<< endl;
                ans2 += (area * sides);


            }
        }
    }

    cout << ans << endl;
    cout << ans2 << endl;


}