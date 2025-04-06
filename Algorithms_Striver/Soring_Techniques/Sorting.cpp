#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    //{4, 1, 3, 9, 7}
    // TC=>O((n*(n+1))/2)=>O(n^2)
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            swap(arr[i], arr[mini]);
        }
    }
}
void bubble_sort(int arr[], int n)
{
    // TC=>O((n*(n+1))/2)=>O(n^2)=>worst cases,Best case=O(N)
    for (int i = n - 1; i >= 1; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap(arr[j],arr[j++]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
        {
            break;
        }
    }
}
void insertion_sort(int arr[], int n)
{
    // TC=>O(N) for best case,O(N^2) for average and worst case
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] < arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;      // left=>0 to mid
    int right = mid + 1; // right=>0 to high
    while (left <= mid && right <= high)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &v, int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(v, low, mid);      // left part
    merge_sort(v, mid + 1, high); // right part
    merge(v, low, mid, high);
}

void mergeSort(vector<int> &v, int n)
{
    // TC=>O(N log2(N))
    // SC=>O(n) for worst case
    merge_sort(v, 0, n - 1);
}
int main()
{
    int n = 5;
    int a[n] = {4, 1, 3, 9, 7};
    selection_sort(a, n);
    cout << "Sorting technique=>Selection Sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Sorting technique=>Bubble sort" << endl;
    int b[n] = {4, 1, 3, 9, 7};
    bubble_sort(b, n);
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "Sorting technique=>Insertion sort" << endl;
    int c[n] = {4, 1, 3, 9, 7};
    bubble_sort(c, n);
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl
         << "Sorting technique=>Merge_sort " << endl;
    vector<int> arr = {1, 5, 4, 3, 2};
    int size = arr.size();
    mergeSort(arr, n);

    for (auto it : arr)
    {
        cout << it << " ";
    }
}