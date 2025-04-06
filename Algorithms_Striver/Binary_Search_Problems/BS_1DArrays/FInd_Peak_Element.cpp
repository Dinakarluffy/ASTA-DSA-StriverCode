#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    // Peak element condition arr[i-1] < arr[i] > arr[i+1]
    // Array contains only one peak element. If it contains many, you can return any one.
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return arr[i];
        }
    }
    return -1;
}

int findPeakElement_binary_search(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] > arr[1])
    {
        return 0; // Return index of peak element
    }
    if (arr[n - 1] > arr[n - 2])
    {
        return n - 1; // Return index of peak element
    }

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid; // Return index of peak element
        }
        else if (arr[mid] > arr[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 5, 1, 2, 1};
    int e = findPeakElement(arr);
    cout << "Peak element (linear search): " << e << endl;

    int e1 = findPeakElement_binary_search(arr);
    cout << "Peak element index (binary search): " << e1 << " and value: " << arr[e1] << endl;

    return 0;
}
