#include <bits/stdc++.h>
using namespace std;

void countStr(string s, string target)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        string ans = "";
        for (int j = i; j < s.size(); j++)
        {
            ans += s[j];
            if (ans == target)
                cnt++;
        }
    }
    cout << cnt << endl;
}
void countStr_optimal(string s, string target)
{
    int cnt = 0;
    int n = s.size(), m = target.size();
    for (int i = 0; i <= n - m; i++)
    {
        if (s.substr(i, m) == target)
            cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    string s = "wibgroooowioowibgr";
    string target = "wibgr";
    countStr(s, target);
}
