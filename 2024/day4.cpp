// #include "bits/stdc++.h"
// using namespace std;

// int main(){
//     freopen("input.txt", "r", stdin);
//     string line;
//     vector<string> str;
//     while(cin >> line){
//         str.push_back(line);
//     }

//     int cnt = 0;

//     int n = str.size();
//     int m = str[0].size();
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             string s = "";

//             // horizontal
//             for(int a = 0; a < 4; a++){
//                 if(j + a >= m){
//                     s = "";
//                     break;
//                 }
//                 s += str[i][j + a];
//             }
//             if(s != ""){
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Horizontal match at: (" << i << ", " << j << ")" << endl;
//                 }
//                 reverse(s.begin(), s.end());
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Horizontal reverse match at: (" << i << ", " << j << ")" << endl;
//                 }
//             }
//             s = "";

//             // vertical
//             for(int a = 0; a < 4; a++){
//                 if(i + a >= n){
//                     s = "";
//                     break;
//                 }
//                 s += str[i + a][j];
//             }
//             if(s != ""){
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Vertical match at: (" << i << ", " << j << ")" << endl;
//                 }
//                 reverse(s.begin(), s.end());
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Vertical reverse match at: (" << i << ", " << j << ")" << endl;
//                 }
//             }
//             s = "";

//             // major diagonal
//             for(int a = 0; a < 4; a++){
//                 if(i + a >= n || j + a >= m){
//                     s = "";
//                     break;
//                 }
//                 s += str[i + a][j + a];
//             }
//             if(s != ""){
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Major diagonal match at: (" << i << ", " << j << ")" << endl;
//                 }
//                 reverse(s.begin(), s.end());
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Major diagonal reverse match at: (" << i << ", " << j << ")" << endl;
//                 }
//             }
//             s = "";

//             // minor diagonal
//             for(int a = 0; a < 4; a++){
//                 if(i + a >= n || j - a < 0){
//                     s = "";
//                     break;
//                 }
//                 s += str[i + a][j - a];
//             }
//             if(s != ""){
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Minor diagonal match at: (" << i << ", " << j << ")" << endl;
//                 }
//                 reverse(s.begin(), s.end());
//                 if(s == "XMAS"){
//                     cnt++;
//                     cout << "Minor diagonal reverse match at: (" << i << ", " << j << ")" << endl;
//                 }
//             }
//         }
//     }
//     cout << cnt << endl;
// }


#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    string line;
    vector<string> str;
    while(cin >> line){
        str.push_back(line);
    }

    int cnt = 0;

    int n = str.size();
    int m = str[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            
            string major = "";
            string minor = "";

            for(int a = -1; a < 2; a++){
                if(i + a >= n || j + a >= m || i + a < 0 || j + a < 0){
                    major = "";
                    break;
                }
                major += str[i+a][j+a];
            }

            for(int a = -1; a < 2; a++){
                if(i + a >= n || j - a >= m || i + a < 0 || j - a < 0){
                    minor = "";
                    break;
                }
                minor += str[i+a][j-a];
            }

            if(major != "" && minor != ""){
                string rmajor = major;
                string rminor = minor;
                reverse(rmajor.begin(), rmajor.end());
                reverse(rminor.begin(), rminor.end());
                if((major == "MAS" || rmajor == "MAS") && (minor == "MAS" || rminor == "MAS")){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}