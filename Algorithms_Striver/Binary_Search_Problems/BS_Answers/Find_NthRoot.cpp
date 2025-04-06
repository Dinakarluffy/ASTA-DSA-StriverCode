#include <bits/stdc++.h>
using namespace std;
int nvalue(int mid, int n, long long m)
{
    // return 1 if ==,
    // return 0 if<m
    // return 2 if>m
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int nthRoot(int n, long long m)
{
    // Code here.
    int low = 1;
    int high = m;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        int midN = nvalue(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
           low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n = 2;
    long long m = 9;
    int a=nthRoot(n,m);
    cout<<a<<endl;
}
