#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    vector<string> arr;
    string s;
    while(cin >> s){
        arr.push_back(s);
    }
    int n = arr.size();
    int m = arr[0].length();

    map<char, vector<pair<int, int>>> ant;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c = arr[i][j];
            if(c != '.'){
                if(!ant.count(c)){
                    ant[c] = vector<pair<int, int>>();
                }
                ant[c].push_back({i, j});
            }
        }
    }
    
    // p1
    set<pair<int, int>> ans;
    for(auto &entry : ant){
        char node = entry.first;
        vector<pair<int, int>> pos = entry.second;

        for(int i = 0; i < pos.size(); i++){
            for(int j = i+1; j < pos.size(); j++){
                auto &pa = pos[i];
                auto &pb = pos[j];
                int ver = pb.first - pa.first;
                int hor = pb.second - pa.second;
                if(pa.first - ver >= 0 && pa.second - hor >= 0 && pa.first - ver < n && pa.second - hor < m){
                    ans.insert({pa.first-ver, pa.second-hor});
                    // cout << "Inserted: (" << pa.first-ver << ", " << pa.second-hor << ")" << endl;
                }
                if(pb.first + ver >= 0 && pb.second + hor >= 0 && pb.first + ver < n && pb.second + hor < m){
                    ans.insert({pb.first+ver, pb.second+hor});
                    // cout << "Inserted: (" << pb.first+ver << ", " << pb.second+hor << ")" << endl;
                }
            }
        }
    }

    cout << ans.size() << endl;

    // p2
    ans.clear();
    for(auto &entry : ant){
        char node = entry.first;
        vector<pair<int, int>> pos = entry.second;

        for(int i = 0; i < pos.size(); i++){
            for(int j = i+1; j < pos.size(); j++){
                auto &pa = pos[i];
                auto &pb = pos[j];
                int ver = pb.first - pa.first;
                int hor = pb.second - pa.second;
                int div = gcd(ver, hor);
                hor /= div;
                ver /= div;
                int x = pa.first;
                int y = pa.second;
                ans.insert({x, y});
                while(x - ver >= 0 && y - hor >= 0 && x - ver < n && y - hor < m){
                    ans.insert({x-ver, y-hor});
                    x -= ver;
                    y -= hor;
                }
                x = pa.first;
                y = pa.second;
                while(x + ver >= 0 && y + hor >= 0 && x + ver < n && y + hor < m){
                    ans.insert({x+ver, y+hor});
                    x += ver;
                    y += hor;
                }
                
            }
        }
    }

    cout << ans.size() << endl;
}