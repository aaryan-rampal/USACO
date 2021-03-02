#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int findArrows(int a, vector<vector<int>> arrow) {
    int totalArrows = arrow[a].size();
    for (int i = 0; i < arrow[a].size(); i++) {
        totalArrows += findArrows(arrow[a][i], arrow);
    }
    return totalArrows;
}

int main() {
    setIO("factory");

    int n;
    cin >> n;
    vector<vector<int>> arrow(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        arrow[b].push_back(a);
    }

    vector<int> totalArrows(n + 1);
    for (int i = 1; i < n + 1; i++) {
        totalArrows[i] = findArrows(i, arrow);
        if (totalArrows[i] == n - 1) {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
}