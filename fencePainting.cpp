#include <iostream>
#include <vector>
using namespace std;

int main () {fi
    
    int a, b, c, d; cin >> a >> b >> c >> d;

    if ((c > b && d > b) || (c < a && d < a)) {
        cout << (b-a)+(d-c);
    } else {
        cout << max(b, d) - min(a, c);
    }
}