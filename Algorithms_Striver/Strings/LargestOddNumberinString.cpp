#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string s)
{
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        { // Odd digit found
            return s.substr(0, i + 1);
        }
    }
    return ""; // No odd digit found
}

int main()
{
    string s = "4206";
    cout << "Largest odd number: " << largestOddNumber(s) << endl;

    return 0;
}
