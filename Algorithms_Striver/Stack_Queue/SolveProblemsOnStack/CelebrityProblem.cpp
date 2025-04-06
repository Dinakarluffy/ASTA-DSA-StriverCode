#include <bits/stdc++.h>
using namespace std;
// Problem statement:everyone knows him ,but he knows no one
int celebrity(vector<vector<int>> &arr)
{
    // Knows me=n-1;
    // I Know=0;
    // TC=>O(N*N)+O(N)
    // SC=>O(2N)
    int n = arr[0].size();
    int m = arr.size();
    vector<int> knowme(n, 0);
    vector<int> iknow(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                knowme[j]++;
                iknow[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (knowme[i] == (n - 1) && iknow[i] == 0)
        {
            return i;
        }
    }
    return -1;
}
int celebrity_optimal(vector<vector<int>> &arr)
{
    //TC=>O(2N)
    //SC=>O(1)
    int n = arr.size();
    int top = 0;
    int down = n - 1;
    while (top <= down)
    {
        if (arr[top][down] == 1)
        {
            top = top + 1;
        }
        else if (arr[down][top] == 1)
        {
            down = down - 1;
        }
        else

        {
            down--;
            top--;
        }
    }
    if (top > down)
        return -1;
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        if (arr[top][i] == 0 && arr[i][top] == 1)
        {
            
        }
        else
        {
            return -1;   
        }
    }
    return top;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int n = celebrity(arr);

    cout << n << endl;
    int n1 = celebrity_optimal(arr);
    cout << n1 << endl;
}