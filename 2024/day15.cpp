// #include "bits/stdc++.h"

// using namespace std;

// int di[] {0, -1, 0, 1};
// int dj[] {-1, 0, 1, 0};

// bool move(int i, int j, vector<string>&arr, int m){
//     if(arr[i][j] == '#'){
//         return false;
//     }
//     if(arr[i][j] == '.'){
//         return true;
//     }
//     bool success = move(i+di[m], j+dj[m], arr, m);
//     if(success){
//         arr[i+di[m]][j+dj[m]] = arr[i][j];
//     }
//     return success;
// }


// int main(){
//     freopen("input.txt", "r", stdin);

//     vector<string> arr;
//     string str;
//     int sr = 0, sc = 0;
//     while(getline(cin, str)){
//         if(str.size()== 0)break;
//         arr.push_back(str);
//     }

//     // getline(cin, str);
//     vector<string> moves;
//     while(getline(cin, str)){
//         moves.push_back(str);
//     }

//     int n = arr.size();
//     int m = arr[0].size();

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m;j++){
//             if(arr[i][j] == '@'){
//                 sr = i;
//                 sc = j;
//                 arr[i][j] = '.';
//             }
//         }
//     }
    
//     for(auto & s : moves){
//         for(auto &c : s){
//             int dir = -1;
//             if(c == '<') dir = 0;
//             else if(c== '^') dir = 1;
//             else if(c=='>') dir = 2;
//             else if(c == 'v') dir = 3;
//             else continue;
//             bool success = move(sr+di[dir], sc+dj[dir], arr, dir);
//             if(success){
//                 sr += di[dir];
//                 sc += dj[dir];
//                 arr[sr][sc] = '.';
//             }
//         }
//     }
//     cout << "Moves: ";
//     for (const auto& s : moves) {
//         cout << s << " ";
//     }
//     cout << endl;

//     for (const auto& row : arr) {
//         cout << row << endl;
//     }

//     int ans =0 ;
//     for(int i =0 ; i < n; i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j] == 'O'){
//                 ans += i*100 + j;
//             }

//         }
//     }
//     cout << ans << endl;
// }

//pt2

#include "bits/stdc++.h"

using namespace std;

int di[] {0, -1, 0, 1};
int dj[] {-1, 0, 1, 0};

bool move(int i, int j, vector<string>&arr, int m){
    if(arr[i][j] == '#'){
        return false;
    }
    if(arr[i][j] == '.'){
        return true;
    }
    // horizontal movement
    if(m == 0 || m == 2){
        j += dj[m];
        bool success = move(i, j+dj[m], arr, m);
        if(success){
            arr[i][j+dj[m]] = arr[i][j];
            arr[i][j] = arr[i][j-dj[m]];
            arr[i][j-dj[m]] = '.';
        }
        return success;
    }
    // vertical movement
    else{
        if(arr[i][j] == ']') j--;
        vector<pair<int, int>> blocks;
        queue<pair<int ,int>> q;
        q.push({i, j});
        while(!q.empty()){
            auto & pair = q.front();
            q.pop();
            blocks.push_back(pair);
            if(arr[pair.first+di[m]][pair.second] == '#' || arr[pair.first+di[m]][pair.second+1] == '#'){
                return false;
            }
            if(arr[pair.first+di[m]][pair.second] == '['){
                q.push({pair.first+di[m], pair.second});
            }
            if(arr[pair.first+di[m]][pair.second] == ']'){
                q.push({pair.first+di[m], pair.second-1});
            }
            if(arr[pair.first+di[m]][pair.second+1] == '['){
                q.push({pair.first+di[m], pair.second+1});
            }
        }
        reverse(blocks.begin(), blocks.end());
        // prevent double counting
        set<pair<int,int>> seen;
        for(auto &block : blocks){
            if(seen.count(block)) continue;
            arr[block.first+di[m]][block.second] = arr[block.first][block.second];
            arr[block.first+di[m]][block.second+1] = arr[block.first][block.second+1];
            arr[block.first][block.second] = '.';
            arr[block.first][block.second+1] = '.';
            seen.insert(block);
        }
        return true;
    }
    
}


int main(){
    freopen("input.txt", "r", stdin);
    vector<string> arr;
    string str;
    int sr = 0, sc = 0;
    while(getline(cin, str)){
        if(str.size()== 0)break;
        string news = "";
        for(auto &c:str){
            if(c == '#')
                news += "##";
            if(c == 'O')
                news += "[]";
            if(c == '@')
                news += "@.";
            if(c == '.')
                news += "..";
        }
        arr.push_back(news);
    }

    // getline(cin, str);
    vector<string> moves;
    while(getline(cin, str)){
        moves.push_back(str);
    }

    int n = arr.size();
    int m = arr[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            if(arr[i][j] == '@'){
                sr = i;
                sc = j;
                arr[i][j] = '.';
            }
        }
    }
    
    for(auto & s : moves){
        for(auto &c : s){
            int dir = -1;
            if(c == '<') dir = 0;
            else if(c== '^') dir = 1;
            else if(c=='>') dir = 2;
            else if(c == 'v') dir = 3;
            else continue;
            bool success = move(sr+di[dir], sc+dj[dir], arr, dir);
            if(success){
                sr += di[dir];
                sc += dj[dir];
                arr[sr][sc] = '.';
            }
            // static int iteration = 0;
            // if (iteration < 30) {
            //     for (const auto& row : arr) {
            //         cout << row << endl;
            //     }
            //     iteration++;
            // }
        }
    }

    long long ans =0 ;
    for(int i =0 ; i < n; i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == '['){
                ans += (long long)i*100 + j;
            }
        }
    }
    for (const auto& row : arr) {
        cout << row << endl;
    }
    cout << ans << endl;
}