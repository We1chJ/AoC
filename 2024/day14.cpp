/*
What a problem

For pt2, look over every iterations and observe that there is a weird verticle cluster of robots every 101 iterations or so. Loop over that and see that there will be a time of christmas tree there
*/

#include "bits/stdc++.h"

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); // Redirect cout to output.txt

    int quad[] {0, 0, 0, 0};
    string str;
    const int X = 101, Y = 103;
    int IT_start = 301;
    int IT_interval = 101*1000;
    vector<string> inputs;
    vector<vector<char>> arr(Y, vector<char>(X,'.'));
    while(getline(cin, str)){
        inputs.push_back(str);
    }

    for(int IT = IT_start; IT < IT_start + IT_interval; IT+=101){
        fill(arr.begin(), arr.end(), vector<char>(X, '.'));
        for(auto & s : inputs){
            str = s;
            size_t comma1 = str.find(',');
            size_t space = str.find(' ');
            size_t comma2 = str.find(',', space);

            int posx = stoi(str.substr(2, comma1 - 2));
            int posy = stoi(str.substr(comma1 + 1, space - (comma1 + 1)));

            int vx = stoi(str.substr(space + 3, comma2 - (space + 3)));
            int vy = stoi(str.substr(comma2 + 1));

            int nx = ((posx + (vx * IT) % X) % X + X) % X;
            int ny = ((posy + (vy * IT) % Y) % Y + Y) % Y;

            if (nx < X / 2) {
                if (ny < Y / 2) {
                    quad[0]++;
                } else if (ny >= (Y + 1) / 2) {
                    quad[2]++;
                }
            } else if (nx >= (X + 1) / 2) {
                if (ny < Y / 2) {
                    quad[1]++;
                } else if (ny >= (Y + 1) / 2) {
                    quad[3]++;
                }
            }
            arr[ny][nx] = 'x';
        }
        ofstream outFile("output_" + to_string(IT) + ".txt");
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
            outFile << arr[i][j];
            }
            outFile << endl;
        }
        outFile.close();
    }

    // for (int i = 0; i < Y; i++) {
    //     for (int j = 0; j < X; j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}