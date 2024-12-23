#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);

    string line1, line2, line3;
    ll ans = 0 ;
    while (getline(cin, line1) && getline(cin, line2) && getline(cin, line3)) {
        ll ax = stoi(line1.substr(12, 2));
        ll ay = stoi(line1.substr(18, 2));
        ll bx = stoi(line2.substr(12, 2));
        ll by = stoi(line2.substr(18, 2));

        ll px = stoi(line3.substr(9, line3.find(',', 9) - 9)) + 1e13;
        ll py = stoi(line3.substr(line3.find(',', 9) + 4)) + 1e13;
        // ll px = stoi(line3.substr(9, line3.find(',', 9) - 9));
        // ll py = stoi(line3.substr(line3.find(',', 9) + 4));


        // pt1
        // int cntA = -1;
        // int cntB = -1;
        // for(int i  =0; i*ax <= px && i * ay <= py; i++){
        //     if((px-i*ax)%bx == 0 && (py - i*ay)%by == 0 && (px-i*ax)/bx == (py-i*ay)/by){
        //         cntA = i;
        //         cntB = (px-i*ax)/bx;
        //         break;
        //     }
        // }
        // if(cntA != -1){
        //     ans += cntA*3 + cntB * 1;
        // }

        //pt2
        ll det = ax*by - bx*ay;
        // cout << "ax: " << ax << ", ay: " << ay << ", bx: " << bx << ", by: " << by << ", px: " << px << ", py: " << py << endl;
        if(det != 0){
            ll cntA = by*px - bx*py;
            ll cntB = -ay*px + ax*py;
            if(cntA%det == 0 && cntB%det == 0){
                cntA /= det;
                cntB /= det;
                if(cntA >= 0 && cntB >= 0){
                    ans += cntA*3+cntB;
                }
            }
        }else if(ax * py == ay * px){
            ans += min(px/bx, px/ax*3);
        }

        string emptyLine;
        getline(cin, emptyLine);
    }
    cout << ans << endl;
}