#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[low];//first element is pivot
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <=high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

// The QuickSort function implementation
void quickSort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}