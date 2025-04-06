#include <bits/stdc++.h>
using namespace std;
void max_subarray_sum_better(vector<int> &arr)
{
    // TC=>O(N^2)
    int mini = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            mini = max(sum, mini);
        }
    }

    cout << mini << endl;
}
void max_subarray_sum_brute(vector<int> &arr)
{
    // TC=>O(N^3)
    int mini = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                mini = max(sum, mini);
            }
        }
    }
    cout << endl;
    cout << mini << endl;
}
void max_subarray_sum_optimal(vector<int> &arr)
{
    // TC=>O(N)
    // SC=>O(1)
    int n = arr.size();
    long long maxi = LONG_MIN;
    long long sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            start = i;
        }
        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        // maxi=max(maxi,sum);
    }
    cout << maxi << endl;
    for (int i = ansStart; i < ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> ve = {-2, -3, 4, -1, -2, 1, 5, -3};
    max_subarray_sum_brute(ve);
    max_subarray_sum_better(ve);
    max_subarray_sum_optimal(ve);
}