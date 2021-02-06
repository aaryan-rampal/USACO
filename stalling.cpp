#include <bits/stdc++.h>
using namespace std;

int factorial(int n) 
{
    int fact = 1;
    for (int i = 1; i < n+1; i++) {
        fact *= i;
    }
    return fact;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> cowSize(n);
    vector<int> stallSize(n); int minStallSize = 0;
    for (int i = 0; i < n; i++) {
        cin >> cowSize[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> stallSize[i];
        if (i == 0 || stallSize[i] < minStallSize) minStallSize = stallSize[i];
    }

    vector<int> cowCanFit(n);
    for (int i = 0; i < n; i++) {
        int counter = 0;
        if (cowSize[i] > minStallSize) {
            for (int j = 0; j < n; j++) {
                if (cowSize[i] <= stallSize[j]) counter++;
            }
            cowCanFit[i] = counter;
        } else {
            cowCanFit[i] = n;
        }
    }

    sort(cowCanFit.begin(), cowCanFit.end());
    long long answer = 1;
    for (int i = 0; i < n; i++) {
        if (cowCanFit[i] != n) {
            answer *= (long long)(cowCanFit[i] - i);
        } else {
            answer *= (long long)factorial(n-i);
            break;
        }
    }
    cout << answer;
    
    
    
}