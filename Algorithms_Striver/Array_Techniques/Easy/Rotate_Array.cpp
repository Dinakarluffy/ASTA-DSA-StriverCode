#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void rotate_brute(vector<int> &arr, int d)
{
    // Left rotate
    // TC=>O(d)+O(n-d)+O(d)=>O(n+d)
    // sc=>O(d)
    int n = arr.size();
    d = d % n;
    int temp[d];

    // vector<int>temp;
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    int j = 0;
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[j]; // arr[i-(n-d)]
        j++;
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        // start+=1;
        // end-=1;
        swap(arr[start++], arr[end--]);
    }
}
void rotate_optimal(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;
    
    // Reverse the first n-d elements=>O(d)
    reverse(arr, 0, n - d - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    // Reverse the last d elements=>O(n-d)
    reverse(arr, n - d, n - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    // reverse the whole array=>O(n)
    reverse(arr, 0, n - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    // TC=>O(2n)
    // SC=>O(1)
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate_brute(arr, k);
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    rotate_optimal(arr1, 3);
}