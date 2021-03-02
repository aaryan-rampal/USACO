#include <iostream>
#include <algorithm>
using namespace std;

#define ni numbers[i]

int main ()
{
    int numbers[7];
    for (int i = 0; i < 7; i++) cin >> ni;
    sort(numbers, numbers+7);
    cout << numbers[0] << " " << numbers[1] << " " << (numbers[6]-numbers[0]-numbers[1]);
}