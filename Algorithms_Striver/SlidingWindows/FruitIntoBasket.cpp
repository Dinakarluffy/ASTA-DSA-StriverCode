#include <bits/stdc++.h>
using namespace std;
// max len subarray with atmost two types of number
void fruit_brute(vector<int> &arr)
{
    // TC=>O(n^2)
    // SC=>O(n)
    int n = arr.size();
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < n; j++)
        {

            st.insert(arr[j]);
            if (st.size() <= 2)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    cout << maxlen << endl;
}
void fruit_better(vector<int> &arr, int k)
{
    // TC=>O(n)+O(n)
    // SC=>O(3)
    int n = arr.size();
    unordered_map<int, int> mp;
    int maxlen = 0;
    int l = 0;
    int r = 0;
    while (r < n)
    {
        mp[arr[r]]++;
        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                    mp.erase(arr[l]);
                l++;
            }
        }
        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    cout << maxlen << endl;
}
void fruit_optimal(vector<int> &arr, int k)
{
    //TC=>O(n)
    //SC=>O(3)
    int n = arr.size();
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<int, int> mp;
    while (r < n)
    {
        mp[arr[r]]++;
        if (mp.size() > k)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
                mp.erase(arr[l]);
            l++;
        }
        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
    }
    cout << maxlen << endl;
}
int main()
{
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    fruit_brute(arr);
    fruit_better(arr, 2);
    fruit_optimal(arr, 2);
}