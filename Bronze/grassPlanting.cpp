#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("planting");

    int n;
    cin >> n;
    vector<int> edge[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int maxSize = 0;
    for (int i = 1; i < n + 1; i++) {
        int size = edge[i].size();
        maxSize = max(maxSize, size);
    }
    cout << maxSize + 1;
}