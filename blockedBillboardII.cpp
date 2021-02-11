#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define input freopen("billboard.in", "r", stdin); freopen("billboard.out", "w", stdout);

int main() 
{
    fast 
    input

    int x1, y1, x2, y2, x3, y3, x4, y4; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int area = abs((y2-y1)) * abs((x2-x1));

    if (max(x1, x3) < min(x2, x4) && max(y1, y3) < min(y2, y4)) {
        // Overlap exists
        int x5 = max(x1, x3); int y5 = max(y1, y3); // bottom left
        int x6 = min(x2, x4); int y6 = min(y2, y4); // top right

        // Overlap completely cuts off an edge
        if ((y6 - y5 == y2 - y1 || x6 - x5 == x2 - x1)) {
            // If there are ends dangling 
            if ((y2 > y4 && y3 > y1) || (x2 > x4 && x3 > x1)) {
                cout << area;
            } else cout << area - (abs((y6 - y5)) * abs((x6 - x5)));
        } else cout << area;
    } else cout << area;
}