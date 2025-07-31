#include <bits/stdc++.h>
using namespace std;
int finbnocci(int n)
{
    if (n <= 1)
        return n;
    return finbnocci(n - 1) + finbnocci(n - 2);
}
// SUBSEQUENCE=A contiguous/Non-contiguos sequence which follows oroder
void printResursiveSubsequence(int index, vector<int> &ds, int arr[], int n)
{

    // TC=>O(2^n * n)
    // SC=>O(n)
    if (index == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}" << " ";
        }
        cout << endl;
        return;
    }
    // Take or pick the particular index into the subsequence
    ds.push_back(arr[index]);
    printResursiveSubsequence(index + 1, ds, arr, n);
    ds.pop_back();
    // Not pick ,this element is not added to your subsequence
    printResursiveSubsequence(index + 1, ds, arr, n);
}
void printSubsequenceSUM(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{

    // TC=>O(2^n * n)
    // SC=>O(n)
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }

        return;
    }
    // Take or pick the particular index into the subsequence
    ds.push_back(arr[index]);
    s += arr[index];
    printSubsequenceSUM(index + 1, ds, s, sum, arr, n);
    s -= arr[index];
    ds.pop_back();
    // Not pick ,this element is not added to your subsequence
    printSubsequenceSUM(index + 1, ds, s, sum, arr, n);
}
// Print any one Subsequence equal to sum
bool printSubsequenceSUMBool(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{

    // TC=>O(2^n * n)
    // SC=>O(n)
    if (index == n)
    {
        if (sum == s)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }

        else
            return false;
    }
    // Take or pick the particular index into the subsequence
    ds.push_back(arr[index]);
    s += arr[index];
    if (printSubsequenceSUMBool(index + 1, ds, s, sum, arr, n) == true)
        return true;
    s -= arr[index];
    ds.pop_back();
    // Not pick ,this element is not added to your subsequence
    if (printSubsequenceSUMBool(index + 1, ds, s, sum, arr, n) == true)
        return true;
    return false;
}
// Print  Subsequence  sum == K
int printSubsequenceSUMEqualToK(int index, int s, int sum, int arr[], int n)
{

    // TC=>O(2^n * n)
    // SC=>O(n)
    if (index == n)
    {
        if (sum == s)
        {

            return 1;
        }

        else
            return 0;
    }
    // Take or pick the particular index into the subsequence

    s += arr[index];
    int l = printSubsequenceSUMEqualToK(index + 1, s, sum, arr, n);
    s -= arr[index];

    // Not pick ,this element is not added to your subsequence
    int r = printSubsequenceSUMEqualToK(index + 1, s, sum, arr, n);
    return l + r;
}

int main()
{
    int ans = finbnocci(4);
    // cout << ans << endl;

    int arr[] = {1, 1, 2};
    vector<int> ds;
    int n = 3;
    // printResursiveSubsequence(0, ds, arr, n);
    int sum = 2;
    // printSubsequenceSUM(0, ds, 0, sum, arr, n);
    // printSubsequenceSUMBool(0, ds, 0, sum, arr, n);
    cout << printSubsequenceSUMEqualToK(0, 0, sum, arr, n);
}