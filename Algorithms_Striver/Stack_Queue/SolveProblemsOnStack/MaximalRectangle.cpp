#include <bits/stdc++.h>
using namespace std;
// Problem Statement: Given input is 2D matrix contain 1's and 0's .you need to find all 1's in maximal  rows and column in matrix
void maximalRectangle(vector<vector<int>> &arr)
{
    // TC=>O(m*n)+O(n*2m)
    //SC=>O(n*m)+O(n)
    int n = arr.size();
    int m = arr[0].size();
    int maxArea = 0;
    vector<vector<int>> prefSum;
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i][j];
            if (arr[i][j] == 0)
            {
                sum = 0;
            }
            prefSum[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++)
    {
        // send the prefix sum rows into largest rectangle histogram function and get maxArea
    }
}
int main()
{
}