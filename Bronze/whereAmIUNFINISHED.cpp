#include <iostream>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define INPUT freopen("whereami.in", "r", stdin); freopen("whereami.out", "w", stdout);

int main() {
 //   INPUT
    int n; cin >> n;
    vector<char> cha(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cha[i];
    }
    
    int maxNumber = 0;
    for (int i = 0; i < n; i++)
    {
        set<char> s;
        for (int j = i; j < n; j++)
        {
            if (s.count(cha[j]) == 0 || i != 0) s.insert(cha[j]);
            else {
                auto length = static_cast<int>(s.size());
                maxNumber = max(maxNumber, length);
                break;
            }
        }
    }
    cout << maxNumber;
    
}