#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string alphabet; cin >> alphabet;
    string lettersHeard; cin >> lettersHeard;

    int restartCounter = 1;
    // starting at 1 since it will play at least one time
    for(int i = 1; i < lettersHeard.length(); i++) {
        int indexI = alphabet.find(lettersHeard[i]);
        int indexIMinus1 = alphabet.find(lettersHeard[i-1]);
        if(!(indexI > indexIMinus1)) restartCounter++;
    }

    cout << restartCounter;
}