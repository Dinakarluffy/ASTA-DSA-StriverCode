#include <bits/stdc++.h>
using namespace std;
// Same As Binary SUbarray SUm problem
int contgoal(vector<int> &arr, int goal)
{
    if (goal < 0)
    {
        return 0; // Return early as no valid processing can happen.
    }

    int n = arr.size();
    if (n == 0)
    {

        return 0;
    }

    int l = 0, r = 0, sum = 0, cnt = 0;

    // Sliding window approach
    while (r < n)
    {
        sum += (arr[r]%2);

        // Shrink window when the sum exceeds the goal
        while (sum > goal)
        {
            sum -= arr[l]%2;
            l++;
        }

        // All subarrays from arr[l] to arr[r] are valid (i.e., their sum <= goal)
        cnt += (r - l + 1);

        // Expand window by moving right pointer
        r++;
    }

    return cnt;
}
void niceSubarray_optimal(vector<int> &arr, int goal)
{
    // TC=>O(2*2N)
    // SC=>O(1)
    int cnt = contgoal(arr, goal + 1) - contgoal(arr, goal - 1);
    cout << cnt << endl;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    niceSubarray_optimal(arr, k);
}