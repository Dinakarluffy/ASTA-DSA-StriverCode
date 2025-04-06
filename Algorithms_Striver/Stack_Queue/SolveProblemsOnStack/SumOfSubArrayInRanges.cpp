#include <bits/stdc++.h>
using namespace std;
void sumofSubArrayRanges_brute(vector<int> &arr)
{
    //TC=>O(n^2)
    //SC=>O(1)
    int n = arr.size();
    int tot = 0;
    int mod = (int)(1e9 + 7);
    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        int large = arr[i];

        for (int j = i; j < n; j++)
        {
            large = max(large, arr[j]);
            mini = min(mini, arr[j]);
            tot = (tot + (large - mini)) % mod;
        }
    }
    cout << "The sum of subarray minimum total=> " << tot << endl;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    sumofSubArrayRanges_brute(arr);
}