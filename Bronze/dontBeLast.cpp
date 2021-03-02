#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

string spitName(int i) {
    switch (i) {
    case 0:
        return "Bessie";
    case 1:
        return "Elsie";
    case 2:
        return "Daisy";
    case 3:
        return "Gertie";
    case 4:
        return "Annabelle";
    case 5:
        return "Maggie";
    case 6:
        return "Henrietta";
    }
    return "hello";
}

int main() {
    setIO("notlast");

    int n;
    cin >> n;
    map<int, int> cowMilk;
    for (int i = 0; i < 7; i++) {
        cowMilk[i] = 0;
    }

    char arr[7] = {'B', 'E', 'D', 'G', 'A', 'M', 'H'};

    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        int y = distance(arr, find(arr, arr + 7, s[0]));
        cowMilk[y] += x;
    }

    vector<int> milk;
    for (pair<int, int> p : cowMilk)
        milk.push_back(p.second);

    set<int> check;
    for (int i = 0; i < 7; i++) {
        check.insert(milk[i]);
    }

    if (check.size() == 1) {
        cout << "Tie";
        return 0;
    }

    int x = *std::next(check.begin(), 1);
    int count = 0;
    int index = 0;
    for (int i = 0; i < 7; i++) {
        if (milk[i] == x) {
            count++;
            index = i;
        }
    }

    if (count == 2) cout << "Tie";
    else cout << spitName(index);
}