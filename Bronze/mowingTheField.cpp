#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Grass {
    bool cut;
    int time;
};

vector<int> multipliers(char x) {
    vector<int> t(2);
    if (x == 'N') {
        t[0] = 0;
        t[1] = 1;
    } else if (x == 'S') {
        t[0] = 0;
        t[1] = -1;
    } else if (x == 'E') {
        t[0] = 1;
        t[1] = 0;
    } else {
        t[0] = -1;
        t[1] = 0;
    }
    return t;
}

vector<vector<Grass>> inst() {
    vector<vector<Grass>> t(2002);
    for (int i = 0; i < 2002; i++) {
        vector<Grass> temp(2002);
        t[i] = temp;
        for (int j = 0; j < 2002; j++) {
            t[i][j].cut = false;
            t[i][j].time = 0;
        }
    }
    return t;
}

int main() {
    setIO("mowing");

    vector<vector<Grass>> arr(2002);
    long long n; cin >> n;
    long long x = 1000, y = 1000;
    unsigned long long answer = ULONG_LONG_MAX, time = 0;
    bool revisit = false;

    for (int i = 0; i < n; i++) {
        char dir;
        long long moves;
        cin >> dir >> moves;
        vector<int> mult = multipliers(dir);
        for (int j = 0; j < moves; j++) {
            if (arr[x][y].cut) {
                answer = min(answer, time - arr[x][y].time);
                revisit = true;
            }
            arr[x][y].cut = true;
            arr[x][y].time = time;
            x += mult[0];
            y += mult[1];
            time++;
        }
    }
    if (revisit) cout << answer;
    else cout << "-1";
}