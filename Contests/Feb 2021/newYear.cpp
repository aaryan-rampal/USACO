#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();

    vector<string> arr = {"Ox",      "Tiger", "Rabbit", "Dragon",
                          "Snake",   "Horse", "Goat",   "Monkey",
                          "Rooster", "Dog",   "Pig",    "Rat"};
    int n;
    cin >> n;
    vector<string> names;
    vector<string> year;
    vector<string> name2;
    vector<string> pm;
    bool foundBessie = false;
    bool foundElsie = false;
    for (int i = 0; i < n; i++) {
        string a, trash, b, c, d, trash1, trash2, trash3;
        cin >> a >> trash >> trash1 >> b >> c >> trash2 >> trash3 >> d;
        if (!foundBessie || !foundElsie) {
            names.push_back(a);
            pm.push_back(b);
            year.push_back(c);
            name2.push_back(d);
        }
        if (d == "Bessie") foundBessie = true;
        if (a == "Elsie") foundElsie = true;
    }

    int total = 0;
    for (unsigned int i = 0; i < names.size(); i++) {
        string year2;
        if (name2[i] == "Bessie")
            year2 = "Ox";
        else {
            auto it = find(names.begin(), names.end(), name2[i]);
            int index = it - names.begin();
            year2 = year[index];
        }
        auto it = find(arr.begin(), arr.end(), year[i]);
        auto it1 = find(arr.begin(), arr.end(), year2);

        int dif = 0;
        if (pm[i] == "next") dif = 12 - abs((it1 - arr.begin()) - (it - arr.begin()));
        else dif = 12 -  abs((it - arr.begin()) - (it1 - arr.begin()));
        total += pm[i] == "next" ? dif : dif * -1;
    }
    cout << abs(total);
}