#include <bits/stdc++.h>
using namespace std;
void sqrt(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i * i <= n)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
}
void sqrt_BS(int n)
{
    int ans = 1;
    int low = 1;
    int high = n - 1;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if ((mid * mid) <= n)
        {
            ans=mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    int n = 25;
    sqrt(n);
    sqrt_BS(n);
}