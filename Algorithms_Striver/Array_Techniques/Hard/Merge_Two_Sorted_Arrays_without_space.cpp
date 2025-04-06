#include <bits/stdc++.h>
using namespace std;
void merge_two_sorted_arrays_without_space_brute(vector<int> arr1, vector<int> arr2)
{
    // TC=>O(n+m)+O(n+m)
    // SC=>O(n+m)
    int n = arr1.size();
    int m = arr2.size();
    int left = 0;
    int right = 0;
    int index = 0;
    vector<int> arr3(n + m);
    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            index++;
            left++;
        }
        else
        {
            arr3[index] = arr2[right];
            index++;
            right++;
        }
    }
    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }
    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
    for (auto it : arr1)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : arr2)
    {
        cout << it << " ";
    }
    cout << endl;
}
void merge_two_sorted_arrays_without_space_better(vector<int> arr1, vector<int> arr2)
{
    // TC=>O(min(n,m))+O(nlogn)
    // SC=>O(1)
    int n = arr1.size();
    int m = arr2.size();
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (auto it : arr1)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : arr2)
    {
        cout << it << " ";
    }
    cout << endl;
}
void swapIfGreater(vector<int>&arr1, vector<int>&arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(vector<int>&arr1, vector<int>&arr2)
{
    // TC=>O(log2(n+m))*O(n+m)
    //SC=>O(1)
    int n = arr1.size();
    int m = arr2.size();
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // case 1: left in arr1[]
            // and right in arr2[]:
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1)
            break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
    for (int num : arr1)
        cout << num << " ";
    cout << endl;

    for (int num : arr2)
        cout << num << " ";
    cout << endl;
}

void merge_optimal2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {0, 2, 6, 8, 9};
    merge_two_sorted_arrays_without_space_brute(v1, v2);
    merge_two_sorted_arrays_without_space_better(v1, v2);
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};

    merge(arr1, arr2);
    
    merge_optimal2(arr1, arr1.size(), arr2, arr2.size());
    return 0;
}