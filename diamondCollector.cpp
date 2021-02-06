// It's not just a and b and a and c comparison, all the diamonds need to fall under the requiremnts

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // freopen("diamond.in", "r", stdin);
    // freopen("diamond.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int maxDiamonds = 0;
    vector<int> diamond (n);

    for (int i = 0; i < n; i++) {
        cin >> diamond[i];
    }
    

    for (int i = 0; i < n; i++) {
        int counter = 1;
        for (int j = 0; j < n; j++) {
            // Making sure I'm putting two different diamonds in a case
            if(i != j) {
                // If the difference in size is smaller than k, increase the counter
                if(abs(diamond[i]-diamond[j]) <= k) counter++;
            }
        }
        if(i == 0 || maxDiamonds < counter) maxDiamonds = counter;
    }

    cout << maxDiamonds;   
}