#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen((s + ".in").c_str(), "r", stdin);
    //freopen((s + ".out").c_str(), "w", stdout);
}

int oddCases(int index, int k, vector<int> arr) {
    k++;
    int plusMinus[2] = {0};
    for (int i = 0; i < arr.size(); i++) {
        if (arr[index] - arr[i] == k)
            plusMinus[0]++;
        else if (arr[i] - arr[index] == k)
            plusMinus[1]++;
    }
    return max(plusMinus[0], plusMinus[1]);
}

int main() {
    setIO("diamond");

    int n, k;
    cin >> n >> k;
    bool isOdd = false;
    if (k % 2 != 0) {
        isOdd = true;
        k--;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxDiamonds = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (abs(arr[j] - arr[i]) <= k / 2) count++;
        }
        if (isOdd) count += oddCases(i, k/2, arr);
        maxDiamonds = max(maxDiamonds, count);
    }
    cout << maxDiamonds;
}