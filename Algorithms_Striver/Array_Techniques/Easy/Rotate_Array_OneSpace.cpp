#include <bits/stdc++.h>
using namespace std;
void rotate_brute(vector<int> &arr)
{
    // TC=>O(n)
    // SC=>O(1) extra space,O(N) for given array we used modified the arrray
    int n = arr.size();
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;

    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    vector<int> v = {1, 2, 3};
    rotate_brute(v);
}