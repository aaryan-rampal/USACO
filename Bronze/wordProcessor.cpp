#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main ()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int N, K; cin >> N >> K;
    int currentCharacters = 0;

    for (int i = 0; i < N; i++) {
        string x; cin >> x;

        if ((currentCharacters + x.length()) <= K) {
            if (i != 0) cout << " " << x;
            else cout << x;
            currentCharacters += x.length();
        } else {
            cout << "\n" << x;
            currentCharacters = x.length();
        }
    }
}
