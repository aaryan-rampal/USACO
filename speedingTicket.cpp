/*
Had to look up the test case I was failing (#3). Apparently, Bessie always drove under
the speed limit so I was outputting a negative number.
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> maxSpeed;
    vector<int> bessieSpeed;

    for (int i = 0; i < n; i++)
    {
        int length, speed; cin >> length >> speed;
        maxSpeed.insert(maxSpeed.end(), length, speed);
    }
    for (int i = 0; i < m; i++)
    {
        int length, speed; cin >> length >> speed;
        bessieSpeed.insert(bessieSpeed.end(), length, speed);

    }

    int biggestDif {0};
    for (int i = 0; i < 100; i++)
    {
        int currentDif = bessieSpeed[i] - maxSpeed[i];
        if (i == 0 || currentDif > biggestDif) biggestDif = currentDif;
    }
    if (biggestDif > 0) cout << biggestDif;
    else cout << "0";
}