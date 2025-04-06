#include <bits/stdc++.h>
using namespace std;
void printXorRange(int n)
{
    // TC=>O(N)
    // SC=>O(1)
    long Xor = 0;
    for (int i = 1; i <= n; i++)
    {
        Xor = Xor ^ i;
    }
    cout << Xor << endl;
}
int printXorRange_optimal(int n)
{
    // TC=>O(1)
    // SC=>O(1)
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    else
    { // if(n%4==0)
        return n;
    }
}
void printXorRangeLTOR_optimal(int l, int r)
{
    int L = printXorRange_optimal(l-1);
    int R = printXorRange_optimal(r);
    int ans = L ^ R;
    cout << ans << endl;//or return func(l-1)^func(r)
}
int main()
{
    printXorRange(8);
    int n = printXorRange_optimal(8);
    cout << n << endl;
    printXorRangeLTOR_optimal(1, 4);
}