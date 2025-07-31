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
void count_str_char(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int w_count = mp['w'];
    int i_count = mp['i'];
    int b_count = mp['b'];
    //int ans = min(w_count, min(i_count, b_count));
    int ans = min({w_count, i_count, b_count}); // C++11 or newer
    cout << ans << endl;
}
void adder(vector<int> &arr)
{
    int carry = 1;
    int i = arr.size() - 1;
    while (i >= 0)
    {
        int sum = arr[i] + carry;
        if (sum <= 9)
        {
            arr[i] = sum;
            carry = 0;
            break;
        }
        else
        {
            carry = 1;
            arr[i] = 0;
        }
        i--;
    }
    if (carry == 1)
    {
        arr.insert(arr.begin(), 1);
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    string s = "wooiiiibobbooowioowwwib";
    string target = "wibgr";
    // countStr(s, target);
    count_str_char(s);
    vector<int> arr = {9, 9, 8};
    adder(arr);
}
