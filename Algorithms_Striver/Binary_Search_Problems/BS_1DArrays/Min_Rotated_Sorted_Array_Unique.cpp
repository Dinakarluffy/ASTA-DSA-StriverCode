
#include <bits/stdc++.h>
using namespace std;

void Min_Element(vector<int> &arr)
{
    int n = arr.size();
    int mini = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[mini])
            mini = i;
    }
    cout << arr[mini] << endl;
}
void min_rotated_Sorted_array_unique(vector<int> &arr)
{
    // Identify the sorted half->left /right
    // In rotated sorted array either one side is always sorted
    // TC=>O(log2 n) for average cases,O(n/2) for worst cases
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        // Left side is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right part is sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    cout << ans << endl;
}
void min_rotated_Sorted_array_duplicates(vector<int> &arr)
{
    // Identify the sorted half->left /right
    // In rotated sorted array either one side is always sorted
    // TC=>O(log2 n) for average cases,O(n/2) for worst cases
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            ans = min(ans, arr[low]);
            low = low + 1;
            high = high - 1;
            continue;
        }

        // Left side is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right part is sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    cout << "Array contian duplicates" << endl;
    cout << ans << endl;
}

int main()
{
    // This will contain duplicate elements also
    vector<int> arr = {7, 8, 9, 0, 2, 3, 3, 3, 4, 5, 6};
    vector<int> arr1 = {6, 1, 1, 2, 2};
    int n = arr.size(), k = 3;
    // Min_Element(arr);
    min_rotated_Sorted_array_unique(arr);
    min_rotated_Sorted_array_duplicates(arr1);

    return 0;
}
