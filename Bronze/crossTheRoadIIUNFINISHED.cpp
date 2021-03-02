#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("circlecross");

    string s;
    cin >> s;
    int cnt = 0;

    for (char i = 'A'; i < 'Z'; i++) {
        for (char j = 'A'; j < 'Z'; j++) {
            if (i == j) continue;
            bool arr[2] = {false};
            int pos[2][2];

            for (int k = 0; k < s.length(); k++) {
                if (s[k] == i) {
                    if (!arr[0]) {
                        arr[0] = true;
                        pos[0][0] = k;
                    } else {
                        pos[0][1] = k;
                    }
                } else if (s[k] == j) {
                    if (!arr[1]) {
                        arr[1] = true;
                        pos[1][0] = k;
                    } else {
                        pos[1][1] = k;
                    }
                }
            }
            if (pos[0][0] < pos[1][0] && pos[1][0] < pos[0][1] && pos[0][1] < pos[1][1]) cnt++;
        }
    }
    cout << cnt;
}