#include <bits/stdc++.h>
using namespace std;
// Problem Statement: return longest consecutive one's when flip k digit
void maxConsecutiveOnes_better(vector<int> &arr, int k)
{
    // TC=>O(N)+O(n)
    // SC=>O(1)
    int n = arr.size();
    int l = 0, r = 0, maxlen = 0;
    int zeroCount = 0;

    while (r < n)
    {
        if (arr[r] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (arr[l] == 0)
                zeroCount--;
            l++;
        }
        if (zeroCount <= k)
        {
            maxlen = max(maxlen, (r - l + 1));
        }
        r++;
    }
    cout << maxlen << endl;
}
void maxConsecutiveOnes_optimal(vector<int> &arr, int k)
{
    // TC=>O(N)
    // SC=>O(1)
    int n = arr.size();
    int l = 0, r = 0, maxlen = 0;
    int zeroCount = 0;
    while (r < n)
    {
        if (arr[r] == 0)
        {
            zeroCount++;
        }
        if (zeroCount > k)
        {
            if (arr[l] == 0)
                zeroCount--;
            l++;
        }
        if (zeroCount <= k)
        {
            maxlen = max(maxlen, (r - l + 1));
        }
        r++;
    }
    cout << maxlen << endl;
}
int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    maxConsecutiveOnes_better(arr, k);
    maxConsecutiveOnes_optimal(arr, k);
}