#include <bits/stdc++.h>
using namespace std;
void maxlenofSubarry(vector<int> &arr, int k)
{
    int n = arr.size();
    int sum = 0;
    int r = 0;
    int l = 0;
    int maxi = 0;
    while (r < n)
    {
        sum = sum + arr[r];
        if (sum > k)
        {
            l = l + 1;
        }
        if (sum <= k)
        {
            maxi = max(maxi, r - l + 1);
        }
        r = r + 1;
    }
    cout << maxi << endl;
}
int main()
{
    vector<int> arr = {2, 5, 1, 10, 10};
    int k = 14;
    maxlenofSubarry(arr, k);
}