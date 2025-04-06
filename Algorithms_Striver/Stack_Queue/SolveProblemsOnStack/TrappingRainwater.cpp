#include <bits/stdc++.h>
using namespace std;
int prefixMax(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    return prefix[n - 1];
}

int suffixMax(vector<int> &arr)
{
    int n = arr.size();
    vector<int> sMax(n);
    sMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        sMax[i] = max(sMax[i + 1], arr[i]);
    }
    return sMax[0];
}
// Approach
int trappingWater(vector<int> &arr)
{
    // TC=>O(2n)+O(N)=>O(3n)
    // SC=>O(2n)
    int n = arr.size();
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixMax(arr);
        int rightMax = suffixMax(arr);
        if (arr[i] < leftMax && arr[i] < rightMax)
        {
            tot += min(leftMax, rightMax) - arr[i];
        }
    }
    return tot;
}
// Approach 2
int trappingWater2(vector<int> &arr)
{
    // TC=>O(n)
    // SC=>O(1)
    int n = arr.size();
    int lMax, rMax, tot = 0, l = 0, r = n - 1;

    while (l < r)
    {
        if (arr[l] <= arr[r])
        {
            if (lMax > arr[l])
            {
                tot += lMax - arr[l];
            }
            else
            {
                lMax = arr[l];
            }
            l = l + 1;
        }
        else
        {
            if (rMax > arr[r])
            {
                tot += rMax - arr[r];
            }
            else
            {
                rMax = arr[r];
            }
            r = r - 1;
        }
    }
    return tot;
}
int main()
{
    vector < int > arr;
    arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The water that can be trapped is " << trappingWater(arr) << endl;
}