#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("triangles");

    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                bool crit = true;
                int area = -1;
                if (j == k || i == k) continue;
                if (arr[i].first != arr[j].first && arr[i].first != arr[k].first && arr[j].first != arr[k].first) crit = false; 
                if (arr[i].second != arr[j].second && arr[i].second != arr[k].second && arr[j].second != arr[k].second) crit = false; 
                if (crit) {
                    int minX = min(arr[i].first, min(arr[j].first, arr[k].first));
                    int minY = min(arr[i].second, min(arr[j].second, arr[k].second));
                    int maxX = max(arr[i].first, max(arr[j].first, arr[k].first));
                    int maxY = max(arr[i].second, max(arr[j].second, arr[k].second));
                    area = (maxY - minY) * (maxX - minX);
                }
                ans = max(area, ans);
            }
        }
    }
    cout << ans;
}