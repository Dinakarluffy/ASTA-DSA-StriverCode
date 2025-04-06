
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}
int search_rotated_array(vector<int> &arr, int n, int k)
{
    // Identify the sorted half->left /right
    // In rotated sorted array either one side is always sorted
    //TC=>O(log2 n) for average cases,O(n/2) for worst cases
    //
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        // Left side is sorted
        if (arr[low] <= arr[mid])
        {
            if (k <= arr[mid] && arr[low] <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right part is sorted
        else
        {
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    //This will contain duplicate elements also
    vector<int> arr = {7, 8, 9, 1, 2, 3,3,3, 4, 5, 6};
    int n = arr.size(), k = 3;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";

    int a = search_rotated_array(arr, n, k);
    cout << a << endl;
    return 0;
}
