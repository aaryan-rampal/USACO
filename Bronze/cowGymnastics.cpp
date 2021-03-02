#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool consistentPair(int *arr, int a, int b, int k, int n) {
    return (distance(arr, find(arr, arr + n, a)) > distance(arr, find(arr, arr + n, b)));
}

int main() {
    setIO("gymnastics");

    int k, n; cin >> k >> n;
    int arr[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j]; 
        }
    }

    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            bool pair = true;
            if (i == j) continue;
            for (int m = 0; m < k; m++) {
                if(!consistentPair(arr[m], i, j, k, n)) pair = false;
            }
            if (pair) count++;
        }
    }
    cout << count;
}
