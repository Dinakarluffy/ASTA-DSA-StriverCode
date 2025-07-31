#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";
    string res = "";
    for (int i = 0; i < strs[0].size(); ++i)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); ++j)
        {
            if (i >= strs[j].size() || strs[j][i] != ch)
                return res;
        }
        res += strs[0][i];
    }
    return strs[0]; // All characters matched
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
