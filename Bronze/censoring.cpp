/*
Had to look at the editorial for this one too. I was going character by character and I had too many for loops 
and it TLE'd. 
*/

#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("censor");

    string s, t; cin >> s >> t;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        result.push_back(s[i]);
        if (t.size() <= result.size() && result.substr(result.size() - t.size()) == t) {
            result.resize(result.size() - t.size());
        } 
    }
    cout << result; 
}