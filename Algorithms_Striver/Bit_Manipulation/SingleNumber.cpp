#include <bits/stdc++.h>
using namespace std;
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
    //TC=>O(N)
    //TC=>O(1)
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans;
}
int main()
{
    vector<int> arr = {4, 4, 100,1, 1, 2};
    singleNumber_brute(arr);
    singleNumber_bitManipulation(arr);
}