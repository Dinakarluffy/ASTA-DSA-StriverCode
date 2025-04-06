#include <bits/stdc++.h>
using namespace std;
void maximumPoints(vector<int> &arr, int k)
{
    //TC=>O(2*k)
    //SC=>O(1)
    int n = arr.size();
    int lsum = 0, rsum = 0;

    int maxsum = 0;
    for (int i = 0; i < k; i++)
    {
        lsum += arr[i];
    }
    maxsum = lsum;
    int righind = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[righind];
        righind--;
        maxsum = max(maxsum, (lsum + rsum));
    }
    cout << maxsum << endl;
}
int main()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    maximumPoints(arr, 4);
}