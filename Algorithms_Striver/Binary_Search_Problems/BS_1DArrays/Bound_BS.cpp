
#include <bits/stdc++.h>
using namespace std;
int binarySearch_LowerBound(vector<int> &nums, int target)
{
    // Lower bound= arr[index]>=target,the first index that grater than target is called lower index,
    // If nothing is grater than means you need to return last index value

    // TC=>O(log2 n)
    // SC=>O(1)
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int binarySearch_UpperBound(vector<int> &nums, int target)
{
    // Upper bound= arr[index]>target,the first index that grater than target is called Upper index,
    // If nothing is grater than means you need to return last index value

    // TC=>O(log2 n)
    // SC=>O(1)
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    cout << "Lower Bound values" << endl;
    vector<int> a = {3, 4, 6, 7, 9, 11, 12, 16, 17};
    int target = 11;
    int n = binarySearch_LowerBound(a, target);
    cout << n << endl;
    int index = lower_bound(a.begin(), a.end(), target) - a.begin();
    cout << index << endl;
    int arr[] = {3, 4, 6, 7, 9, 11, 12, 16, 17};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int ind = lower_bound(arr, arr + n1, target) - arr;
    // if they ask portion of the array  for lower bound you need to write like that lower_bound(arr+start_index, arr +end index, target) - arr
    cout << ind << endl;
    // Normal lower bound found in STL
    // index=lower_bound(arr.begin(),arr.end(),target)-arr.begin(); if it's not vector means array lower_bound(arr,arr+n,target)-arr;
    cout << "Upper bound values" << endl;
    int u = binarySearch_UpperBound(a, target);
    cout << u << endl;
    int u1 = upper_bound(a.begin(), a.end(), target) - a.begin();
    int u2 = upper_bound(arr, arr + n1, target) - arr;
    cout << u1 << endl
         << u2 << endl;
}
