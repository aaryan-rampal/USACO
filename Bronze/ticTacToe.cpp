#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int soloWin(vector<bool> &arr, string s) {
    set<char> x;
    char singleton = s[0];
    for (int i = 0; i < 3; i++) {
        x.insert(s[i]);
    }
    if (x.size() == 1 && !arr[singleton - 'A']) {
        arr[singleton - 'A'] = true;
        return 1;
    }
    return 0;
}

int teamWin(vector<vector<bool>> &arr, string s) {
    set<char> x;
    char r, y;
    r = s[0];
    bool holy = true;
    for (int i = 0; i < 3; i++) {
        x.insert(s[i]);
        if (s[i] != r && holy) {
            y = s[i]; 
            holy = false;
        }
    }
       if (x.size() == 2 && !arr[y - 'A'][r - 'A']) {
        arr[y - 'A'][r - 'A'] = true;
        arr[r - 'A'][y - 'A'] = true;
        return 1;
    }
    return 0;
}

int main() {
    setIO("tttt");

    string top, mid, bot;
    cin >> top >> mid >> bot;
    int solo = 0, team = 0;

    vector<bool> soloWins(26);
    fill(soloWins.begin(), soloWins.end(), false);
    vector<vector<bool>> teamWins(26);
    for (int i = 0; i < 26; i++) teamWins[i].resize(26);

    solo += soloWin(soloWins, top);
    solo += soloWin(soloWins, mid);
    solo += soloWin(soloWins, bot);
    string s; s.push_back(top[0]); s.push_back(mid[1]); s.push_back(bot[2]);
    string h; h.push_back(top[2]); h.push_back(mid[1]); h.push_back(bot[0]);
    solo += soloWin(soloWins, s);
    solo += soloWin(soloWins, h);
    for (int i = 0; i < 3; i++) {
        string s;
        s.push_back(top[i]); s.push_back(mid[i]); s.push_back(bot[i]);
        solo += soloWin(soloWins, s);
    }

    team += teamWin(teamWins, top);
    team += teamWin(teamWins, mid);
    team += teamWin(teamWins, bot);
    string a; a.push_back(top[0]); a.push_back(mid[1]); a.push_back(bot[2]);
    string b; b.push_back(top[2]); b.push_back(mid[1]); b.push_back(bot[0]);
    team += teamWin(teamWins, a);
    team += teamWin(teamWins, b);
    for (int i = 0; i < 3; i++) {
        string s;
        s.push_back(top[i]); s.push_back(mid[i]); s.push_back(bot[i]);
        team += teamWin(teamWins, s);
    }

    cout << solo << "\n" << team; 
}