/*
So, you go from x+1 to x-2 to x+4 to x-8... Basically, x +/- (y) where y is multiplied by 2 each time. You can show that as x + y where y is multiplied by -2 (takes care of the switching
between signs for us). Then, newX is the new x value we will reach this loop when we use the formula above. If that new value has passed y (that's what the if condition looks for), then we 
start calculting the distance. First of all, we know that we had to go x+1 and then back to x. Then we went x-2 and then back to x. The distance we are travelling is 1+1+2+2+4+4... There are
2 values since we need to go back each time to the origin. Then, you do log(multiplier)/log(2) since you need to find out how many times did we have to double our distance (go to new value 
and back to origin). I added 1 to that value since it doesn't count the first time when we only travel 1 distance (log(1)/log(2) == undefined). Reminder, the multiplier is the distance 
from the origin to the new point, it doesn't include the return journey. Then, we enter the for loop which simulates us going from the origin to the new point and back again. If you do the 
math, this is the same as summing up all the values i of 2^i so that's what the for loop is for. Then, we need to adjust the difference since the difference includes the return journey on 
the last trip. When you return, you have seen all of the road so logically, the cow can't be seen on the return journery and therefore we must remove that return trip distance. Then, there 
is also the possibility that you were supposed to travel to x+16 but you found the cow at x+10 so you need to account for the difference between the x value you were aiming for and where 
you found the cow. I made it the absolute value since sometimes, the cow is to the left (-) of the farmer so I don't want to subtract negatives and add to the distance. I also did this without
looking anything up (except for the half hour spent trying to get the debugger to work because I did pow(2,3)/2 instead of pow(2,dirChange)/2).
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int x, y; cin >> x >> y;
    bool yGreaterThanX = y > x ? true : false;
    int distance = 0;

    long double multiplier = 1;
    while (true)
    {
        int newX = x + multiplier;
        if (yGreaterThanX && newX > y || !yGreaterThanX && newX < y || newX == y) {
            int dirChange = (log(abs(multiplier)) / log(2)) + 1;
            int distance = 0;

            for (int i = 1; i < (dirChange+1); i++)
            {
                distance += pow(2, i);
            }
            distance -= abs(y-newX); distance -= (pow(2, dirChange))/2;
            cout << distance;
            break;
        } else {
            multiplier *= -2;
        }   
    }
    
}