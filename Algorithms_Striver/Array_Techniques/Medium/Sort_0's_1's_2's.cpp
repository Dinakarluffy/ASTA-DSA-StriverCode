#include <bits/stdc++.h>
using namespace std;
void sort_zersos_ones_two_better(vector<int> arr)
{

    // TC=>O(2N)
    // SC=>O(1)
    int n = arr.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        if (arr[i] == 1)
        {
            count1++;
        }
        if (arr[i] == 2)
        {
            count2++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < (count0 + count1); i++)
    {
        arr[i] = 1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        arr[i] = 2;
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void sort_zersos_ones_two_optimal(vector<int> &arr)
{
    int n = arr.size();
    // Dutch National Flag Algorithm
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);

            high--;
        }
        else
        {
            mid++;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    vector<int> v = {0, 2, 1, 0, 1, 2, 0};
    // Brute force sorting Tc=>O(n logn)
    sort_zersos_ones_two_better(v);
    sort_zersos_ones_two_optimal(v);
}