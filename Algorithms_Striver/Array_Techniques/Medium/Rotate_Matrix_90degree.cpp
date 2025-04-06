
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> rotate_brute(vector<vector<int>> &matrix)
{
    // TC=>O(N^2)
    // SC=>O(N^2)
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}
void rotate_optimal(vector<vector<int>> &matrix)
{
    //SC=>O(1)
    int n = matrix.size();
    // transposing the matrix
    //TC=>O(N/2*N/2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reversing each row of the matrix
    //O(N*N/2)
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated = rotate_brute(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++)
    {
        for (int j = 0; j < rotated[0].size(); j++)
        {
            cout << rotated[i][j] << " ";
        }
        cout << "n";
    }
    cout<<endl;

    vector < vector < int >> arr1;
    arr1 =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate_optimal(arr1);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr1.size(); i++) {
    for (int j = 0; j < arr1[0].size(); j++) {
        cout << arr1[i][j] << " ";
    }
    cout << "n";
    }
    cout<<endl;
}
