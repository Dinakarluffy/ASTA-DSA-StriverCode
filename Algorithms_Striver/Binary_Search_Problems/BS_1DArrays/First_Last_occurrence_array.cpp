#include <bits/stdc++.h>
using namespace std;
void firstLast_occurrence_brute(vector<int> &arr, int x)
{
    // TC=>O(n)
    int n = arr.size();
    int first = -1;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }

    cout << "{" << first << " " << last << "}" << endl;
}
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

vector<int> firstLast_occurrence_BSUpperAndLowerBound(vector<int> &arr, int x)
{
    // TC=>2* O(log2 n)
    int n = arr.size();
    int lb = binarySearch_LowerBound(arr, x);
    if (lb == n || arr[lb] != x)
    {
        return {-1, -1};
    }

    return {lb, binarySearch_UpperBound(arr, x) - 1};
}
int first_occurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        /* code */
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    return first;
}
int last_occurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        /* code */
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
    }
    return last;
}
void binarySearch_find_occurence(vector<int> &nums, int target)
{
    // Upper bound= arr[index]>target,the first index that grater than target is called Upper index,
    // If nothing is grater than means you need to return last index value

    // TC=>O(log2 n)
    // SC=>O(1)
    int n = nums.size(); // size of the array
    int first = first_occurence(nums, target);
    if (first == -1)
    {
        cout << "-1" << " -1" << endl;
    }
    else
    {
        int last = last_occurence(nums, target);
        cout << first << " " << last << endl;
    }
}

int main()
{
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    int target = 13;
    firstLast_occurrence_brute(v, target);
    vector<int> a = firstLast_occurrence_BSUpperAndLowerBound(v, target);
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    binarySearch_find_occurence(v, target);
}