#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("guess");

    int n;
    cin >> n;
    vector<vector<string>> arr(n);
    for (int i = 0; i < n; i++) {
        string trash;
        cin >> trash;
        int j;
        cin >> j;
        vector<string> temp;
        for (int k = 0; k < j; k++) {
            string s;
            cin >> s;
            temp.push_back(s);
        }
        arr[i] = temp;
    }

    int maxDup = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dup = 0;

            for (string a : arr[i]) {
                if (find(arr[j].begin(), arr[j].end(), a) != arr[j].end())
                    dup++;
            }
            maxDup = max(maxDup, dup);
        }
    }
    cout << maxDup + 1;
}