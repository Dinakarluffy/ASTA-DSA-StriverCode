#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row1 = 3;
    int col1 = 2;
    int row2 = 2;
    int col2 = 2;
    if (col1 != row2)
        cout << "Multiplication is not possible" << endl;
    else
    {
        vector<vector<int>> arr1(row1, vector<int>(col1, 0));
        vector<vector<int>> arr2(row2, vector<int>(col2, 0));
        for (int i = 0; i < row1; i++)
        {
            int sum = 1;
            for (int j = 0; j < col1; j++)
            {
                arr1[i][j] = sum;
                sum++;
            }
        }
        for (int i = 0; i < row2; i++)
        {
            int sum = 2;
            for (int j = 0; j < col2; j++)
            {
                arr2[i][j] = sum;
                sum++;
            }
        }
        vector<vector<int>> ans(row1, vector<int>(col2, 0));
        // MULTIPLICATION
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for (int k = 0; k < col1; k++)
                {
                    ans[i][j] += arr1[i][k] * arr2[k][j];
                }
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
    }
}