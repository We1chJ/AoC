// #include "bits/stdc++.h"

// using namespace std;
// using ll = long long;

// ll A = 0, B = 0, C = 0;

// int getCombo(int x)
// {
//     if (x == 4)
//         return A;
//     else if (x == 5)
//         return B;
//     else if (x == 6)
//         return C;
//     else
//         return x;
// }

// int main()
// {
//     freopen("input.txt", "r", stdin);

//     string str;
//     getline(cin, str);
//     A = stoi(str.substr(12));
//     getline(cin, str);
//     B = stoi(str.substr(12));
//     getline(cin, str);
//     C = stoi(str.substr(12));
//     getline(cin, str);
//     getline(cin, str);

//     str = str.substr(9);
//     stringstream ss(str);
//     vector<int> tokens;
//     string token;
//     while (getline(ss, token, ','))
//     {
//         tokens.push_back(stoi(token));
//     }

//     ll ans = 0;

//     for (int i = 0; i < tokens.size(); i += 2)
//     {
//         int fir = tokens[i];
//         int sec = tokens[i + 1];

//         ll num, den;
//         switch (fir)
//         {
//         case 0:
//             // Code for case 0
//             num = A;
//             den = getCombo(sec);
//             A = num / (1 << den);
//             break;
//         case (1):
//             // Code for case 1
//             B ^= sec;
//             break;
//         case 2:
//             // Code for case 2
//             B = getCombo(sec) % 8;
//             break;
//         case 3:
//             // Code for case 3
//             if (A != 0)
//             {
//                 i = sec;
//                 i -= 2;
//             }
//             break;
//         case 4:
//             // Code for case 44
//             B = B ^ C;
//             break;
//         case 5:
//             // Code for case 5
//             cout << getCombo(sec) % 8 << ",";
//             break;
//         case 6:
//             // Code for case 6
//             num = A;
//             den = getCombo(sec);
//             B = num / (1 << den);
//             break;
//         case 7:
//             // Code for case 7
//             num = A;
//             den = getCombo(sec);
//             C = num / (1 << den);
//             break;
//         }
//     }
// }

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll A = 0, B = 0, C = 0;

ll getCombo(ll x)
{
    if (x == 4)
        return A;
    else if (x == 5)
        return B;
    else if (x == 6)
        return C;
    else
        return x;
}

vector<int> run_program(vector<int> &program, ll a) {
    A = a;
    B = 0;
    C = 0;
    vector<int> out;
    int i = 0;
    while (i < program.size()) {
        int opcode = program[i];
        int operand = program[i + 1];
        switch (opcode) {
            case 0:
                A >>= getCombo(operand);
                break;
            case 1:
                B ^= operand;
                break;
            case 2:
                B = getCombo(operand) % 8;
                break;
            case 3:
                if (A != 0) {
                    i = operand - 2;
                }
                break;
            case 4:
                B ^= C;
                break;
            case 5:
                out.push_back(getCombo(operand) % 8);
                break;
            case 6:
                B = A >> getCombo(operand);
                break;
            case 7:
                C = A >> getCombo(operand);
                break;
        }
        i += 2;
    }
    return out;
}

ll ans = LLONG_MAX;

void bt(vector<int> &tokens, int pos, ll cur)
{
    // cout << "pos: " << pos << ", start: " << start << ", cur: " << cur << endl;
    if (pos == -1)
    {
        ans = min(ans, cur);
        return;
    }
    cur <<= 3;

    for(ll i = cur; ; i++){
        if(ans != LLONG_MAX) return;
        vector<int> res = run_program(tokens, i);
        // for (int r : res) {
        //     cout << r << " ";
        // }
        // cout << endl;
        // for (int j = pos; j < tokens.size(); j++) {
        //     cout << tokens[j] << " ";
        // }
        // cout << endl;

        bool match = true;
        for(int x = pos; x < tokens.size(); x++){
            if(tokens[x] != res[x-pos])
                match = false;
        }

        if(match){
            bt(tokens, pos-1, i);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    string str;
    getline(cin, str);
    A = stoi(str.substr(12));
    getline(cin, str);
    B = stoi(str.substr(12));
    getline(cin, str);
    C = stoi(str.substr(12));
    getline(cin, str);
    getline(cin, str);

    str = str.substr(9);
    stringstream ss(str);
    vector<int> tokens;
    string token;
    while (getline(ss, token, ','))
    {
        tokens.push_back(stoi(token));
    }
    
    bt(tokens, tokens.size() - 1, 0);

    cout << ans << endl;
}