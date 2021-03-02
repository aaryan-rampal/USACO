#include <bits/stdc++.h>
using namespace std;

int loop(vector<int> flowers, int a, int b, int n)
{
    int sum = 0; int counter = 0;
    for (int i = a; i <= b; i++) {
        sum += flowers[i]; counter ++;
    }
    long double x = (long double)sum/counter;
    for (int i = a; i <= b; i++) {
        if(x == flowers[i]) return 1;
    }
    return 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    
    int pairs = n;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            pairs += loop(flowers, i, j, n);
        }
    }

    cout << pairs;
}