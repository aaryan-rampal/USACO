/*
Got an important lesson in reading the question.
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rooms; cin >> rooms;
    vector<int> capacity;           
    for (int i = 0; i < rooms; i++) {
        int abc; cin >> abc;
        capacity.push_back(abc);
    }

    int minDistance;
    for (int i = 0; i < rooms; i++) {
        // i = current room
        int roomIndex = i+1; 
        int distance = 0;
        for (int j = 1; j < rooms; j++) {
            if(roomIndex == rooms) roomIndex = 0;
            distance += capacity[roomIndex] * j;
            roomIndex++;
        }
        
        if(i == 0 || distance < minDistance) minDistance = distance;
    }

    cout << minDistance;
    
}
