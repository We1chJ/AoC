// #include "bits/stdc++.h"
// using namespace std;

// int main(){
//     freopen("input.txt", "r", stdin);
//     vector<int> l1, l2;
//     int a, b;
//     while(cin >> a >> b){
//         l1.push_back(a);
//         l2.push_back(b);
//     }
//     sort(l1.begin(), l1.end());
//     sort(l2.begin(), l2.end());

//     long long ans= 0 ;
//     for(int i = 0; i < l1.size(); i++){
//         ans += abs(l1[i] - l2[i]);
//     }
//     cout << ans << endl;
// }

#include "bits/stdc++.h"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    vector<int> l1, l2;
    int a, b;
    while(cin >> a >> b){
        l1.push_back(a);
        l2.push_back(b);
    }
    sort(l2.begin(), l2.end());

    long long ans= 0 ;
    for(auto &a : l1){
        auto i1 = lower_bound(l2.begin(), l2.end(), a);
        auto i2 = upper_bound(l2.begin(), l2.end(), a);
        ans += (a * (i2-i1));
    }
    cout << ans << endl;
}