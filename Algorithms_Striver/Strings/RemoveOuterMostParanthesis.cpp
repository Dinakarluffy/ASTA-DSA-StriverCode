#include <bits/stdc++.h>
using namespace std;
void removeOuterParenthesis_optimal()
{
    string s = "(())(())";
    int n = s.size();
    stack<char> st;
    string ans = "";
    int depth = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            if (depth > 0)
                ans += c; // Don't include outer '('
            depth++;
        }
        else
        {
            depth--;
            if (depth > 0)
                ans += c; // Don't include outer ')'
        }
    }

    cout << ans << endl;
}
int main()
{
    removeOuterParenthesis_optimal();
}