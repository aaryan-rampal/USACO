#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Log {
    int day;
    string name;
    int change;
};

bool sortMethod(const Log &a, const Log &b) { return a.day < b.day; }

int changeInWinners(vector<bool> &winner, vector<int> milk) {
    int maxMilk = 0;
    vector<int> maxCows;
    bool change = false;

    for (int i = 0; i < 3; i++) {
        maxMilk = max(maxMilk, milk[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (milk[i] == maxMilk)
            maxCows.push_back(i);
        else {
            if (winner[i]) {
                change = true;
                winner[i] = false;
            }
        }
    }

    for (int i = 0; i < maxCows.size(); i++) {
        if (!winner[maxCows[i]]) {
            change = true;
        }
        winner[maxCows[i]] = true;
    }
    return change ? 1 : 0;
}

int main() {
    setIO("measurement");

    int n;
    cin >> n;
    vector<Log> arr;
    for (int i = 0; i < n; i++) {
        Log x;
        cin >> x.day >> x.name >> x.change;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), sortMethod);

    vector<int> milk(3);
    vector<bool> winner(3);
    fill(winner.begin(), winner.end(), false);

    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].name[0] == 'B')
            milk[0] += arr[i].change;
        else if (arr[i].name[0] == 'M')
            milk[1] += arr[i].change;
        else if (arr[i].name[0] == 'E')
            milk[2] += arr[i].change;
        changes += changeInWinners(winner, milk);
    }
    cout << changes;
}