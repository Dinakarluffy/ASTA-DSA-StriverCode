#include <bits/stdc++.h>
using namespace std;

void numberOfReversePairs(vector<int> &a)
{

    // TC=>O(n^2)
    // SC=>O(1)
    //  Count the number of pairs:
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    cout << "The number of inversions is: "
         << cnt << endl;
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    // storing elements in the temporary array in a sorted manner//

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

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    // Modification 3
}
int countReversePairs(vector<int> &arr, int low, int mid, int high)
{
    // TC=>O(n logn)
    int cnt = 0;
    int right = mid + 1;
    int left = low;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countReversePairs(arr, low, mid, high);
    merge(arr, low, mid, high); // merging sorted halves
    return cnt;
}

int numberOfReversePairs_optimal(vector<int> &a)
{
    // TC=>O(2n logn)
    // SC=>O(n)
    int n = a.size();
    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> a = {2, 4, 3, 5, 1};

    numberOfReversePairs(a);
    int n = numberOfReversePairs_optimal(a);
    cout << n << endl;

    return 0;
}
