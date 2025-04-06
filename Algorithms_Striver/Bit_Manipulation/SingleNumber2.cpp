#include <bits/stdc++.h>
using namespace std;
// Every Number appearing twice
void singleNumber_brute(vector<int> &arr)
{
    // TC=>O(N*logm)+O(m)
    // SC=>O(m)
    // m=(n/2+1)
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
}
void singleNumber_bitManipulation(vector<int> &arr)
{
    // TC=>O(N*32)
    // SC=>O(1)
    int n = arr.size();
    int ans = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & (1 << bit))
            {
                cnt++;
            }
        }
        if (cnt % 3 == 1)
        {
            ans = ans | (1 << bit);
        }
    }
    cout << ans << endl;
}
int singleNumber_optimal(vector<int> &arr)
{
    // TC=>O(nlogn )+O(n/3)
    // TC=>O(1)
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 1; i < n; i += 3)
    {
        if (arr[i] != arr[i - 1])
        {
            return arr[i - 1];
        }
    }
    return arr[n - 1];
}
void singleNumber_bitManipulation_optimal2(vector<int> &arr)
{
    // Use buckets concept here,oneBucket(contain apear only in list),twoBucket,threeBucket
    // arr[i] will go to oneBucket,if it is not present in twoBucket
    // arr[i] will go to twoBucket,if it is present in oneBucket
    // arr[i] will go to threeBucket, if it is presen in twoBucket

    // TC=>O(n)
    // SC=>O(1)
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ones = (ones ^ arr[i]) & (~twos);

        twos = (twos ^ arr[i]) & (~ones);
    }
    cout << ones << endl;
}
int main()
{
    vector<int> arr = {5, 5, 5, 2, 4, 4, 4};
    singleNumber_brute(arr);
    singleNumber_bitManipulation(arr);
    int n = singleNumber_optimal(arr);
    cout << n << endl;
    singleNumber_bitManipulation_optimal2(arr);
}