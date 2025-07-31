#include <bits/stdc++.h>
using namespace std;

void subarrayKdifferentIntegers_brute(vector<int> &arr, int k)
{
    // TC=>O(n^2)
    // SC=>O(n)
    int n = arr.size();
    int cnt = 0;

    // Iterate over all possible subarray starting points
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mp; // Used to count the frequencies of elements
        for (int j = i; j < n; j++)
        {
            mp[arr[j]]++; // Include arr[j] in the subarray

            // If we have exactly 'k' different integers in the subarray, count it
            if (mp.size() == k)
            {
                cnt++;
            }
            // If more than 'k' distinct integers, break out of the loop (no need to continue)
            else if (mp.size() > k)
            {
                break;
            }
        }
    }

    cout << cnt << endl;
}
// the below function is for <=K
int calculate_k(vector<int> &arr, int k)
{
    // TC=>O(n^2)
    // SC=>O(n)
    if (k == 0)
        return 0;
    int n = arr.size();
    int cnt = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[arr[r]]++;
        while (mp.size() <= k)
        {
            mp[arr[l]]--;

            if (mp[arr[l]] == 0)
                mp.erase(arr[l]);
            l--;
        }
        cnt = cnt + (r - l + 1);

        r++;
    }
    return cnt;
}
void subarrayKdifferentIntegers_optimal(vector<int> &arr, int k)
{
    //TC=>2*O(n)+O(n)
    //SC=>@*O(n)
    int cnt = calculate_k(arr, k) - calculate_k(arr, k - 1);
    cout << cnt << endl;
}
int main()
{
    int k = 3;
    vector<int> arr = {1, 2, 1, 3, 4};
    subarrayKdifferentIntegers_brute(arr, k); // Expected output: 2
    subarrayKdifferentIntegers_optimal(arr, k);

    return 0;
}
