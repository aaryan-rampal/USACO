#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

int main() 
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> time;
    for (int  i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        time.PB(MP(x, y));
    }

    sort(time.begin(), time.end());
    int elapsedTime = 0;  
    for (int i = 0; i < n; i++) {
        elapsedTime = time[i].first + time[i].second;
        if(elapsedTime > time[i+1].first) {
            time[i+1].second += (elapsedTime - time[i+1].first);
        }
    }

    cout << elapsedTime;
}