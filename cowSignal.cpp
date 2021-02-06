#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        string str; cin >> str;
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < n; l++)
            {
                for (int z = 0; z < k; z++)
                {
                    cout << str[l];
                }
            }
            cout << "\n";
        }
    }
}