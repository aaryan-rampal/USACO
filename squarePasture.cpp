#include <bits/stdc++.h>
using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
};

int main ()
{
    // freopen("square.in", "r", stdin);
    // freopen("square.out", "w", stdout);

    Rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2; 
    
    int sideLength1 = max(a.x2, b.x2)-min(a.x1, b.x1);
    int sideLength2 = max(b.y2, a.y2)-min(b.y1, a.y1);
    int sideLength = max(sideLength1, sideLength2);
    cout << pow(sideLength, 2.0);
}