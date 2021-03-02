//#include <bits/stdc++.h>
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//}
//
//int xValue(char a) {
//    if (a == 'W') return -1;
//    if (a == 'E') return 1;
//    return 0;
//}
//
//int yValue(char a) {
//    if (a == 'N') return -1;
//    if (a == 'S') return 1;
//    return 0;
//}
//
//int main() {
//    setIO();
//
//    int n; cin >> n;
//    char good[] = {'N', 'E', 'S', 'W'};
//    for (int i = 0; i < n; i++) {
//        string s; cin >> s;
//        char dir[4] = {'0'};
//        int x = 0;
//        int y = 0;        
//
//        int index = 1;
//        for (int j = 0; j < s.length(); j++) {
//            if (find(dir, dir + 4, s[i]) != dir + 4) {
//                dir[index] = s[i]; 
//                index++;
//            }
//        }
//        
//        if (find(good, good + 4, dir[0]) > find(good, good + 4, dir[1])) cout << "CCW\n";
//        else cout << "CW\n";
//    }
//}

#include <bits/stdc++.h>
using namespace std;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();

    int n; cin >> n;
    char good[] = {'N', 'E', 'S', 'W'};
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        char dir[4] = {'a'};
        dir[0] = s[0];

        for (int j = 0; j < s.length(); j++) {
            if () 
        }
        
        
        
    }
}


