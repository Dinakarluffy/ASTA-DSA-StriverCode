#include <bits/stdc++.h>
using namespace std;
void KthMissingNumber(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    cout << k << endl;
}
int KthMissingNumber_BS(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);//value minus index
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high + k + 1;
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    KthMissingNumber(arr, k);
    int n = KthMissingNumber_BS(arr, k);
    cout << n << endl;
}