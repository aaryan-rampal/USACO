#include <bits/stdc++.h>
using namespace std;

int findMaximumWater(int divM, int a, int b, int capacity)
{
    int lastWater = 0; int divMDup = divM;
    for (int i = 0; i < divM; i++) {
        int water = 0; int j = 0;
        while (water <= capacity) {
            if(divMDup * a + b * j <= capacity) water = divMDup * a + b * j;
            else break;
            j++;
        }
        divMDup--;
        if(water > lastWater && water <= capacity)
            lastWater = water;
    }
    return lastWater;
}

int main() 
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, m; cin >> x >> y >> m;
    
    int xDivM = floor(m/x);
    int yDivM = floor(m/y);

    int maxWater1 = findMaximumWater(xDivM, x, y, m);
    int maxWater2 = findMaximumWater(yDivM, y, x, m);

    cout << max(maxWater1, maxWater2);
}