#include <bits/stdc++.h>
using namespace std;
int maxIndex(vector<vector<int>> &arr, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][col] > maxValue)
        {
            maxValue = arr[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeak(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIndex = maxIndex(arr, n, m, mid);
        int left = mid - 1 >= 0 ? arr[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? arr[maxRowIndex][mid + 1] : -1;
        if (arr[maxRowIndex][mid] > left && arr[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (arr[maxRowIndex][mid] < left)
        {
            high=mid-1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
int main()
{
}