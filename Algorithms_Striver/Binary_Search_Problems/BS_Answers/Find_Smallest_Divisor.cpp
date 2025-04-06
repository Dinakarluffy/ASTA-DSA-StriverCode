#include <bits/stdc++.h>
using namespace std;
int findSmallerstDivisor_givenThreshhold(vector<int> &arr, int t)
{
    // TC=>O(max * n )
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    for (int div = 1; div <= maxi; div++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)arr[i] / (double)div);
        }
        if (sum <= t)
        {
            return div;
        }
    }
    return -1;
}
int sumByD(vector<int> &arr, int div)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil((double)arr[i] / (double)div);
    }
    return sum;
}
int smallDivisor(vector<int> &arr, int t)
{
    //TC=>O(log2(max)*N)
    int n = arr.size();
    if (n > t) return -1;

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sum = sumByD(arr, mid);
        if (sum <= mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    int n = findSmallerstDivisor_givenThreshhold(arr, threshold);
    cout << n << endl;
    int n1 = smallDivisor(arr, threshold);
    cout << n1 << endl;
}