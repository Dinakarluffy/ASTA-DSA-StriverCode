#include <bits/stdc++.h>
using namespace std;
void assignCookies(vector<int> &g, vector<int> &s)
{
    sort(s.begin(), s.end());
    sort(g.begin(), g.end());
    int l = 0;
    int r = 0;
    int cnt = 0;
    while (r < s.size() && l < g.size())
    {
        if (s[r] >= g[l])
        {
            l++;
        }
        r++;
    }
    cout << l << endl;
}
int main()
{
    vector<int> greed = {1, 5, 3, 3, 4};//1.3.3.4.5

    vector<int> s = {4, 2, 1, 2, 1, 3};//1,1,2,2,3,4
    assignCookies(greed, s);
}