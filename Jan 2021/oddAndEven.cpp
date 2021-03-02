#include <bits/stdc++.h>
using namespace std;

int findMod3(int a)
{
    if(a == 1) return 0;
    if((a-1) % 3 == 0) a -= 2;
    int x = floor(a/1.5);
    return x;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int odd = 0; int even = 0;
    for (int i = 0; i < n; i++) {
        int nextNumber; cin >> nextNumber;
        if(nextNumber % 2 == 0) even++;
        else odd++;
    }

    int pairs = 0;
    if(even < odd) {
        pairs += even*2;
        odd -= even;
        pairs += findMod3(odd);
    } else if(even >= odd) {
        pairs = odd * 2;
        if(even != odd) pairs += 1;
    }

    cout << pairs;

    
    
}