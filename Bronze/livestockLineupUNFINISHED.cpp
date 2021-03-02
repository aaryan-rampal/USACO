#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int nameToNum(string name) {
    if (name == "Beatrice") return 1;
    if (name == "Belinda") return 2;
    if (name == "Bella") return 3;
    if (name == "Bessie") return 4;
    if (name == "Betsy") return 5;
    if (name == "Blue") return 6;
    if (name == "Buttercup") return 7;
    return 8;
}

string numToName(int num) {
    if (num == 0) return "Beatrice";
    if (num == 1) return "Belinda";
    if (num == 2) return "Bella";
    if (num == 3) return "Bessie";
    if (num == 4) return "Betsy";
    if (num == 5) return "Blue";
    if (num == 6) return "Buttercup";
    return "Sue";
}

vector<int> combination(vector<int> *arr, vector<int> lineup, int a, int b) {
    lineup.push_back(a);
    if (arr[b].size() != 1 && find(lineup.begin(), lineup.end(), b) == lineup.end()) lineup = combination(arr, lineup, b, arr[b][1]);
    else if (arr[b].size() == 1) {
        if (find(lineup.begin(), lineup.end(), arr[a][0]) != lineup.end()) lineup = combination(arr, lineup, b, arr[b][0]);
        else lineup.push_back(arr[a][0]);
    }
    return lineup;
}

int main() {
    setIO("lineup");

    int n; cin >> n;
    vector<int> arr[8];
    string a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < 4; j++) {
            cin >> c;
        }
        cin >> b;
        int aNum = nameToNum(a) - 1;
        int bNum = nameToNum(b) - 1;
        arr[bNum].push_back(aNum);
        arr[aNum].push_back(bNum);
    }

    vector<int> lineup;
    for (int i = 0; i < 8; i++) {
        if (arr[i].size() == 1 && find(lineup.begin(), lineup.end(), i) == lineup.end()) {
            lineup = combination(arr, lineup, i, arr[i][0]);
        } else if (arr[i].size() == 0) {
            lineup.push_back(i);
        }
    }

    for (int i = 0; i < lineup.size(); i++) {
        cout << numToName(lineup[i]);
        if (i != lineup.size() - 1) cout << "\n";
    }
}