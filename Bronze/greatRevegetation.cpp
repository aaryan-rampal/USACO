#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("revegetate");

    int n, m;
    cin >> n >> m;
    vector<int> pairs[n + 1];
    for (int i = 1; i < m + 1; i++) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    vector<int> seeds(n + 1);
    fill(seeds.begin(), seeds.end(), 1);
    for (int i = 1; i < n + 1; i++) {
        int j;
        for (j = 1; j < 5; j++) {
            bool foundColor = true;
            for (int k = 0; k < pairs[i].size(); k++) {
                if (j == seeds[pairs[i][k]] && i > pairs[i][k])
                    foundColor = false;
            }
            if (foundColor) break;
        }
        seeds[i] = j;
        cout << seeds[i];
    }
}
