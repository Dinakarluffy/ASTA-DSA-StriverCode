#include <bits/stdc++.h>
using namespace std;
void longestsubstring_brute(string s, int k)
{
    /// TC=>O(N^2)*log(26) if use unorder mapp means TC=>O(n^2)
    // SC=O(256)
    int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp.clear();
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            if (mp.size() <= k)
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
void longestsubstring_optimal(string s, int k)
{
    /// TC=>O(N^2)*log(256) 
    // SC=O(256)
    int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mp;
    while (r < n)
    {
        mp[s[r]]++;
        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l--;
        }
        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    cout << maxlen << endl;
}
void longest_optimal(string arr, int k)
{
    // TC=>O(n)+O(n)
    // SC=>O(3)
    int n = arr.size();
    unordered_map<char, int> mp;
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

int main()
{
    string s = "aaabbccd";
    int k = 2;
    longestsubstring_brute(s, k);
    longestsubstring_optimal(s, k);
    longestsubstring_optimal(s, k);
}