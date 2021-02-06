#include <bits/stdc++.h>
using namespace std;

int countTime(int a, int n, vector<pair<int, int>> startEndTime);

int main() 
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    // start, end
    vector<pair <int, int>> startEndTime(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        startEndTime[i] = make_pair(a, b);
    }

    sort(startEndTime.begin(), startEndTime.end());
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        maxTime = max(maxTime, countTime(i, n, startEndTime));
    }
    cout << maxTime;
    
}

int countTime(int a, int n, vector<pair<int, int>> startEndTime)
{
    int time = 0;
    startEndTime.erase(startEndTime.begin() + a);
    for (int i = 0; i < n-1; i++) {
        time += startEndTime[i].second - startEndTime[i].first;
        if (startEndTime[i+1].first < startEndTime[i].second && i != n-2) time -= startEndTime[i].second - startEndTime[i+1].first;
    }
    return time;
}