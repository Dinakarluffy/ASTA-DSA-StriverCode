#include <bits/stdc++.h>
using namespace std;
void max_consecutive_ones_brute(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count = 0;
        }
        if (arr[i] == 1)
        {
            count = count + 1;
            maxi = max(maxi, count);
        }
       
    }
    cout << maxi << endl;
}
int main()
{
    vector<int> vec = {1, 1, 0, 1, 1, 1, 0, 1};
    max_consecutive_ones_brute(vec);
}