#include <bits/stdc++.h>
using namespace std;
void longest_subarray_sum_brute(vector<int> &arr, long long d)
{
    // TC=>O(n^2)
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == d)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    cout << len << endl;
}
void longest_subarray_sum_better(vector<int> &a, long long k)
{
    //IT's for both positive and negativee values
    // int n=arr.size();
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        // calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        // Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    cout << maxLen << endl;
}
//Optimal solution
void getLongestSubarray(vector<int> &a, long long k)
{
    //It's only for positive values
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n)
    {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n)
            sum += a[right];
    }

    cout << maxLen << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 1, 5};

    int k = 4;
    longest_subarray_sum_brute(v, k);
    getLongestSubarray(v, k);
}