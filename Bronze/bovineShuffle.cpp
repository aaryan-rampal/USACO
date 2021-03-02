#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> shuffleOrder; 
    vector<int> finalID;
    for (int i = 0; i < n; i++) {
        int currentOrder; cin >> currentOrder;
        shuffleOrder.push_back(currentOrder);
    }
    for (int i = 0; i < n; i++) {
        int currentID; cin >> currentID;
        finalID.push_back(currentID);
    }

    for (int i = 0; i < 3; i++) {
        vector<int> temp (n);
        for (int j = 1; j < n+1; j++) {
            auto index = find(shuffleOrder.begin(), shuffleOrder.end(), j) - shuffleOrder.begin();
            temp[index] = finalID[j-1];
        }
        finalID = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << finalID[i] << "\n";
    }
}