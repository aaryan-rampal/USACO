#include <bits/stdc++.h>
using namespace std;

int countDuplicates(char a, char b)
{
    return a == b ? true : false;
}

bool loopsThroughIndex(vector<vector <char>> a, int index, int n)
{
    bool duplicate = false;
    for (int j = 0; j < n; j++) {
        for (int k = (n*2)-1; k > n-1; k--) {
            if(countDuplicates(a[j][index], a[k][index])) return true;
        }
    }
    return false;
}

int main() 
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n, m; cin >> n >> m;
    vector <vector <char>> allCowsGenome(n*2);
    for (int i = 0; i < n*2; i++) {
        vector<char> currentGenome(m);
        for (int j = 0; j < m; j++) {
            cin >> currentGenome[j];
        }
        allCowsGenome[i] = currentGenome;
    }

    int counter = 0;
    // Cycles through spotted cows
    for (int i = 0; i < m; i++) {
        if (!loopsThroughIndex(allCowsGenome, i, n)) counter++;
    }
    cout << counter;    
}