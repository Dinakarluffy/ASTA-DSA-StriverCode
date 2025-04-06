#include <bits/stdc++.h>
using namespace std;
int main()
{
    int start = 3;
    int goal = 4;

    int ans = start ^ goal;
    int count=0;
    //TC=>O(log2(start ^ goal ))
    //SC=>O(1)
    while (ans != 0)
    {
        ans = ans & ans-1;
        count++;
    }

    cout << "The number of minimum bits flip for goal decimal is =>" << count;
}