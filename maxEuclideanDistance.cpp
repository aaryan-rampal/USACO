#include <bits/stdc++.h>
using namespace std;

#define crdx(i) coordinates[i].first
#define crdy(i) coordinates[i].second

int main() 
{
    // freopen("TEST.in", "r", stdin);
    // freopen("TEST.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair <int, int>> coordinates;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }
    
    long long maxDistance = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i != j) {
                long long distance = sqrt(pow((crdx(i) - crdx(j)), 2) + pow((crdy(i) - crdy(j)), 2));
                if(distance > maxDistance) maxDistance = distance;
            }
        }
    }

    cout << pow(maxDistance, 2);
    
}