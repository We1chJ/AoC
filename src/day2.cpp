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

#include "bits/stdc++.h"

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    int ans = 0;
    while (getline(cin, line))
    {
        istringstream iss(line);
        vector<int> v;
        int num;
        while (iss >> num)
        {
            v.push_back(num);
        }

        vector<int> temp = v;
        bool flag = true;
        int dif = temp[1] - temp[0];
        for (int j = 0; j < temp.size() - 1; j++)
        {
            int a = temp[j + 1] - temp[j];
            if (abs(a) >= 1 && abs(a) <= 3 && a * dif > 0)
            {
                ;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
            continue;;
        }

        for (int i = 0; i < v.size(); i++)
        {
            vector<int> temp = v;
            temp.erase(temp.begin() + i);
            bool flag = true;
            int dif = temp[1] - temp[0];
            for (int j = 0; j < temp.size() - 1; j++)
            {
                int a = temp[j + 1] - temp[j];
                if (abs(a) >= 1 && abs(a) <= 3 && a * dif > 0)
                {
                    ;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}