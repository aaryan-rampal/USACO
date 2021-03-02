/*
I did look up the solution but just to get a general hint on where to go. I was trying
to make like a quadruple nested loop that found each possible combination of words
and then counted the letters those combinations and then did max(ocurrences, combinationOcurrences)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countOcurrences(string x)
{
    vector<int> ocurrences (26);
    for(char letter : x) {
        ocurrences[letter - 'a']++;
    }
    return ocurrences;
}

void maxOcurrences(vector<int> oc1, vector<int> oc2, vector<int> &ocurrences)
{
    vector<int> maxOcurrences (26);
    for (int i = 0; i < 26; i++) {
        ocurrences[i] += max(oc1[i], oc2[i]);
    }
}

int main() 
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> occurrences (26);
    for (int i = 0; i < n; i++) {
        string x, y; cin >> x >> y;
        vector<int> oc1, oc2;
        oc1 = countOcurrences(x); oc2 = countOcurrences(y);
        maxOcurrences(oc1, oc2, occurrences);
    }
    
    for (int i = 0; i < 26; i++) {
        cout << occurrences[i] << "\n";
    }
    
}