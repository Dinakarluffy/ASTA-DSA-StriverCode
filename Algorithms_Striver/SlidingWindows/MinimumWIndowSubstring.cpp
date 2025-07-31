#include <bits/stdc++.h>
using namespace std;

string minwindowSubstring_brute(string s, string t)
{
    int n = s.size();
    int minLen = INT_MAX;
    int sIndex = -1;

    unordered_map<char, int> tFreq;
    for (char ch : t)
        tFreq[ch]++;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> windowFreq = tFreq;
        int count = t.size();

        for (int j = i; j < n; j++)
        {
            if (windowFreq.find(s[j]) != windowFreq.end())
            {
                if (windowFreq[s[j]] > 0)
                    count--;
                windowFreq[s[j]]--;
            }

            if (count == 0)
            {
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    sIndex = i;
                }
                break;
            }
        }
    }

    if (sIndex == -1)
        return "";

    return s.substr(sIndex, minLen);
}
string minwindowSubstring_optimal(string s, string t)
{
    // TC => O(2N) + O(m)
    // SC => O(256)
    int n = s.size();
    int minLen = INT_MAX;
    int sIndex = -1;
    int l = 0, r = 0;
    int cnt = 0;

    unordered_map<char, int> tFreq;
    for (char ch : t)
    {
        tFreq[ch]++;
    }

    while (r < n)
    {
        if (tFreq[s[r]] > 0)
            cnt++;
        tFreq[s[r]]--;

        while (cnt == t.size())
        {
            if ((r - l + 1) < minLen)
            {
                minLen = r - l + 1;
                sIndex = l;
            }

            tFreq[s[l]]++; 
            if (tFreq[s[l]] > 0)
                cnt--;

            l++; // move left pointer to shrink the window
        }

        r++; // move right pointer to expand the window
    }

    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
int main()
{
    string s = "ddaaabbca";
    string t = "abc";
    string result = minwindowSubstring_brute(s, t);
    cout << "Minimum window substring: " << result << endl;
    string result1 = minwindowSubstring_optimal(s, t);
    cout << "Minimum window substring Optimal: " << result1 << endl;
}
