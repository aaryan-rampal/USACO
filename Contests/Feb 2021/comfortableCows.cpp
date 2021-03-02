//#include <bits/stdc++.h>
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(0);
//    std::cin.tie(0);
//}
//
//int neighbours(int n, vector<pair<int,int>> cells, vector<pair<int,int>> &arr, int x, int y) {
//    int total = 0;
//    int cnt = 0;
//
//    if (find(cells.begin(), cells.end(), make_pair(x+1,y)) != cells.end()) cnt++;
//    if (find(cells.begin(), cells.end(), make_pair(x-1,y)) != cells.end()) cnt++;
//    if (find(cells.begin(), cells.end(), make_pair(x,y+1)) != cells.end()) cnt++;
//    if (find(cells.begin(), cells.end(), make_pair(x,y-1)) != cells.end()) cnt++;
//    if (cnt == 3) {
//        total++;
//        arr.push_back(make_pair(x,y));
//    } else {
//        auto it = find(arr.begin(), arr.end(), make_pair(x,y));
//        if (it != arr.end()) {
//            int index = distance(it, arr.begin());
//            arr.erase(arr.begin(), arr.begin() + index);
//            total--;
//        }
//    }
//    return total;
//}
//
//int main() {
//    setIO();
//    
//    int n; std::cin >> n;
//    vector<pair<int,int>> cells(n);
//    vector<pair<int,int>> arr;
//    int total = 0;
//    for (int i = 0; i < n; i++) {
//        int x, y; std::cin >> x >> y;
//        cells[i] = make_pair(x,y);
//
//        total += neighbours(n, cells, arr, x + 1, y);
//        total += neighbours(n, cells, arr, x - 1, y);
//        total += neighbours(n, cells, arr, x, y + 1);
//        total += neighbours(n, cells, arr, x, y - 1);
//        for (int j = 0; j < arr.size(); j++) {
//            total += neighbours(n, cells, arr, arr[i].first, arr[i].second);
//        }
//        cout << total << "\n";
//    }
//}
//



#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
}

int neighbours(int n, vector<pair<int,int>> cells, vector<pair<int,int>> &arr, int x, int y) {
    int total = 0;
    int cnt = 0;

    if (find(cells.begin(), cells.end(), make_pair(x+1,y)) != cells.end()) cnt++;
    if (find(cells.begin(), cells.end(), make_pair(x-1,y)) != cells.end()) cnt++;
    if (find(cells.begin(), cells.end(), make_pair(x,y+1)) != cells.end()) cnt++;
    if (find(cells.begin(), cells.end(), make_pair(x,y-1)) != cells.end()) cnt++;
    if (cnt == 3) {
        total++;
        arr.push_back(make_pair(x,y));
    } else {
        auto it = find(arr.begin(), arr.end(), make_pair(x,y));
        if (it != arr.end()) {
            int index = distance(it, arr.begin());
            arr.erase(arr.begin(), arr.begin() + index);
            total--;
        }
    }
    return total;
}

int main() {
    setIO();
    
    int n; std::cin >> n;
    vector<pair<int,int>> cells(n);
    vector<pair<int,int>> comft;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int x, y; std::cin >> x >> y;
        cells[i] = make_pair(x,y);

        total += neighbours(n, cells, comft, x + 1, y);
        total += neighbours(n, cells, comft, x - 1, y);
        total += neighbours(n, cells, comft, x, y + 1);
        total += neighbours(n, cells, comft, x, y - 1);
        for (int j = 0; j < comft.size(); j++) {
            total += neighbours(n, cells, comft, comft[i].first, comft[i].second);
        }
        cout << total << "\n";
    }
}