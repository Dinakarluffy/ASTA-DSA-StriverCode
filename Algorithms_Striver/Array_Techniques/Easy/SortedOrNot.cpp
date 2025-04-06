#include <bits/stdc++.h>
using namespace std;
bool sorted_or_not_brute(vector<int> &arr)
{

    // TC=>O(N)
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 1};
    bool s = sorted_or_not_brute(v);
    cout << s << endl;
}