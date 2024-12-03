// #include "bits/stdc++.h"

// using namespace std;

// int main() {
//     freopen("input.txt", "r", stdin);
//     string line;
//     int ans = 0;
//     while (getline(cin, line)) {
//         istringstream iss(line);
//         vector<int> v;
//         int num;
//         while (iss >> num) {
//             v.push_back(num);
//         }
//         bool flag = true;
//         int dif = v[1]-v[0];
//         for(int i = 0; i < v.size()-1; i++){
//             int a = v[i+1]-v[i];
//             if(abs(a) >= 1 && abs(a) <= 3 && a * dif > 0){
//                 ;
//             }else{
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) ans++;
//     }
//     cout << ans << endl;
// }

// part 2: cheesy method because the report only has small number of levels for all cases.
// #include "bits/stdc++.h"

// using namespace std;

// int main()
// {
//     freopen("input.txt", "r", stdin);
//     string line;
//     int ans = 0;
//     while (getline(cin, line))
//     {
//         istringstream iss(line);
//         vector<int> v;
//         int num;
//         while (iss >> num)
//         {
//             v.push_back(num);
//         }

//         vector<int> temp = v;
//         bool flag = true;
//         int dif = temp[1] - temp[0];
//         for (int j = 0; j < temp.size() - 1; j++)
//         {
//             int a = temp[j + 1] - temp[j];
//             if (abs(a) >= 1 && abs(a) <= 3 && a * dif > 0)
//             {
//                 ;
//             }
//             else
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             ans++;
//             continue;;
//         }

//         for (int i = 0; i < v.size(); i++)
//         {
//             vector<int> temp = v;
//             temp.erase(temp.begin() + i);
//             bool flag = true;
//             int dif = temp[1] - temp[0];
//             for (int j = 0; j < temp.size() - 1; j++)
//             {
//                 int a = temp[j + 1] - temp[j];
//                 if (abs(a) >= 1 && abs(a) <= 3 && a * dif > 0)
//                 {
//                     ;
//                 }
//                 else
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag)
//             {
//                 ans++;
//                 break;
//             }
//         }
//     }
//     cout << ans << endl;
// }

// part 2: more generic solutions
#include "bits/stdc++.h"
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> v;
        int num;
        while (iss >> num) {
            v.push_back(num);
        }
        vector<int> after[3];
        bool flag = true;
        int n = v.size();
        for(int i = 1; i < n-1; i++){
            int a = v[i]-v[i-1];
            int b = v[i+1]-v[i];
            if(abs(a) >= 1 && abs(a) <= 3 && abs(b) >= 1 && abs(b) <= 3 && a * b > 0){
                ;
            }else{
                for (int j = 0; j < 3; j++) {
                    after[j] = v;
                    after[j].erase(after[j].begin() + i + (j-1));
                }
                flag = false;
                break;
            }
        }
        if(flag){ ans++; continue;}

        for(int z = 0; z < 3; z++){
            vector<int> &temp = after[z];
            flag = true;
            for(int i = 1; i < n-1-1; i++){
                int a = temp[i]-temp[i-1];
                int b = temp[i+1]-temp[i];
                
                if(abs(a) >= 1 && abs(a) <= 3 && abs(b) >= 1 && abs(b) <= 3 && a * b > 0){
                    ;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){ ans++; break;}
        }
        
    }
    cout << ans << endl;
}
