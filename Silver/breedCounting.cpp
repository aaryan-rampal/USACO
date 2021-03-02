#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> one(n + 1), two(n + 1), thr(n + 1);
    
    for (int i = 1; i < n + 1; i++) {
        one[i] = one[i - 1];
        two[i] = two[i - 1];
        thr[i] = thr[i - 1];

        int x; cin >> x;
        if (x == 1) one[i]++;
        else if (x == 2) two[i]++;
        else thr[i]++;
    }

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << one[b] - one[a - 1] << " " << two[b] - two[a - 1] << " " << thr[b] - thr[a - 1] << "\n";
    }
}