#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define input freopen("square.in", "r", stdin); freopen("square.out", "w", stdout);

int main() 
{
    fast 
    //input

    vector<int> a(4);
    vector<int> b(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> b[i];

    int n = max(a[0],max(b[0],max(a[2],b[2]))) - min(a[0],min(b[0],min(a[2],b[2])));
    int m = max(a[1],max(b[1],max(a[3],b[3]))) - min(a[1],min(b[1],min(a[3],b[3])));
    cout << pow(max(n,m), 2);
}