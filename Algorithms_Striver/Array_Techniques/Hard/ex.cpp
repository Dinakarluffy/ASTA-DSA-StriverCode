#include <bits/stdc++.h>
using namespace std;

// Swap elements in arr1 and arr2 if arr1[ind1] > arr2[ind2]
void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int len = n + m;

    // Initial gap: ceil(len / 2)
    int gap = (len / 2) + (len % 2);

    // Perform gap-based merging
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // Case 1: left in arr1[] and right in arr2[]
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // Case 2: both pointers in arr2[]
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // Case 3: both pointers in arr1[]
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        
        // If gap reaches 1, stop
        if (gap == 1)
            break;

        // Otherwise, calculate new gap
        gap = (gap / 2) + (gap % 2);
    }

    // Print the merged arrays
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    for (int num : arr2)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    merge(arr1, arr2);

    return 0;
}
