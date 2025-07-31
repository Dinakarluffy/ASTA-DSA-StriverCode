#include <bits/stdc++.h>
using namespace std;
void reverseArrayRecursive(int l, int r, vector<int> &arr)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArrayRecursive(l + 1, r - 1, arr);
}
bool palindromeRecursive(int i, string &s)
{
    if (i >= (s.size() / 2))
        return true;
    if (s[i] != s[s.size() - i - 1])
        return false;
    return palindromeRecursive(i + 1, s);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArrayRecursive(0, arr.size() - 1, arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    string s = "MADAM";
    cout << palindromeRecursive(0, s);
}