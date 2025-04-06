#include <bits/stdc++.h>
using namespace std;
void max_product_subarray_brute(vector<int> &arr)
{
    // TC=>O(N^3)
    int mini = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            int sum = 1;

            for (int k = i; k < j; k++)
            {
                sum *= arr[k];
                mini = max(sum, mini);
            }
        }
    }
    cout << endl;
    cout << mini << endl;
}

void max_product_subarray_better(vector<int> &arr)
{
    // TC=>O(N^2)
    int mini = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 1;

        for (int j = i; j < n; j++)
        {
            sum *= arr[j];
            mini = max(sum, mini);
        }
    }

    cout << mini << endl;
}
void max_product_subarray_optimal(vector<int> &arr)
{
    // TC=>O(N)
    // SC=>O(1)
    int n = arr.size();
    long long maxi = LONG_MIN;
    long long prefix = 1;
    long long suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }
        prefix = prefix * arr[i];         // from start
        suffix = suffix * arr[n - i - 1]; // from end;
        maxi = max(maxi, max(prefix, suffix));
    }
    cout << maxi << endl;
}

int main()
{
    vector<int> ve = {2, 3, -2, 4};
    max_product_subarray_brute(ve);
    max_product_subarray_better(ve);
    max_product_subarray_optimal(ve);
}