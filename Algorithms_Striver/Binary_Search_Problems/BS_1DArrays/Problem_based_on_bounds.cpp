#include <bits/stdc++.h>
using namespace std;
void search_insert_position(vector<int> &nums, int insert)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= insert)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
}
// Floor in sorted array=>largest number in array<=x
// Ceil in sorted array=>smallest number in array>=x(it is lowr bound)
void Floor(vector<int> &nums, int insert)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = -1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= insert)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
}
void Ceil(vector<int> &nums, int insert)
{
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = -1;

    // Perform the steps:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= insert)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 11, 12, 16, 17};
    int insert = 11;
}