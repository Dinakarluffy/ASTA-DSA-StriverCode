#include <bits/stdc++.h>
using namespace std;
void selection_sort(vector<int> &arr)
{
    // TC=>O(n^2)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
            break;
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    for (auto it : arr)
    {

        cout << it << " ";
    }
    cout << endl;
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {

            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void merSort(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merSort(arr, low, mid);
    merSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void MERGESORT(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    merSort(arr, low, high);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int findPartitionIndex(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {
        int partition = findPartitionIndex(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}
void quick(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    quickSort(arr, low, high);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {100, 4, 5, 2, 3};
    // selection_sort(arr);
    // bubble_sort(arr);
    // insertion_sort(arr);
    // MERGESORT(arr);
    quick(arr);
}