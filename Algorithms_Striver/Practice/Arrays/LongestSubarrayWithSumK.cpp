#include <bits/stdc++.h>
using namespace std;
void longestSubarrayWIthSum_brute()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 4, 2, 3};
    int n = arr.size();
    int maxi = INT_MIN;
    int k = 3;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                maxi = max(maxi, j - i + 1);
            }
        }
    }

    cout << maxi << endl;
}

int main()
{
    longestSubarrayWIthSum_brute();
}
