#include <bits/stdc++.h>
using namespace std;
// Only one element in array is unique you need to return the value,other elements repeat twice
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size(); // size of the array.
    if (n == 1)
        return arr[0];

    for (int i = 0; i < n; i++)
    {

        // Check for first index:
        if (i == 0)
        {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        // Check for last index:
        else if (i == n - 1)
        {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        // Check for both right and left
        else
        {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}
int singleNonDuplicate_binary_search(vector<int> &arr)
{
    int n = arr.size();
    int low = 2; // Because eliminate some cases for checking both right and left element checking
    int high = n - 2;
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid - 1] != arr[mid])
        {
            return arr[mid];
        }
        // Left half(even ,odd)
        if (((mid % 2 == 0) && arr[mid] == arr[mid + 1]) || ((mid % 2 == 1) && arr[mid] == arr[mid - 1]))
        {
            // Eliminiate left part
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // Eliminate right half
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    int ans1 = singleNonDuplicate_binary_search(arr);
    cout << "The single element is: " << ans1 << "\n";
    return 0;
}
