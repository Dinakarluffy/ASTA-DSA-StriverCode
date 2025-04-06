#include <bits/stdc++.h>

using namespace std;

int solve_brute(string str)
{

    if (str.size() == 0)
        return 0;
    int maxans = INT_MIN;
    for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
    {
        unordered_set<int> set;
        for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}
int longestSubstring_optimal(string s)
{

    vector<int> mpp(256, -1);
    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
            left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int main()
{
    string str = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << solve_brute(str)<<endl;
    cout << "The length=>" << longestSubstring_optimal(str);

    return 0;
}