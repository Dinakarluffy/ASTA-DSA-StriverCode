#include <bits/stdc++.h>
using namespace std;
void merge_overlapping_subinterval_brute(vector<vector<int>> arr)
{
    // TC=>O(n logn)+O(2n)
    // SC=>O(n)
    int n = arr.size();    // row
    int m = arr[0].size(); // column
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
    // return ans;
}
void merge_overlapping_subinterval_optimal(vector<vector<int>> arr)
{
    // TC=>O(n logn)+O(n)
    // SC=>O(n)
    int n = arr.size();    // row
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
    // return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    merge_overlapping_subinterval_brute(v);
    merge_overlapping_subinterval_optimal(v);
}