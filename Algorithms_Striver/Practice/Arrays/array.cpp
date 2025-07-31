#include <bits/stdc++.h>
using namespace std;
void largestElement()
{
    vector<int> arr = {1, 1003, 4, 100, 23};
    int n = arr.size();
    int l = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > arr[l])
        {
            l = i;
        }
    }
    cout << arr[l] << endl;
}
void secondLargestelement()
{
    vector<int> arr = {1, 1003, -1, 1003, 23};
    int n = arr.size();
    int l = arr[0];
    int s = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > l)
        {
            s = l;
            l = arr[i];
        }
        else if (arr[i] < l && arr[i] > s)
        {
            s = arr[i];
        }
    }

    cout << "Second Largest elemtnt" << " ";
    cout << s << endl;
}
void checkSorted()
{
    vector<int> arr = {1, 2, 3, 4, 4, 5, 6};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "Not Sorted" << endl;
            break;
        }
    }
    cout << "Correct" << endl;
}
void removeUniqueElements()
{
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    int n = arr.size();
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[index] != arr[i])
        {
            arr[index + 1] = arr[i];
            index++;
        }
    }
    cout << index + 1 << endl;
}
int main()
{
    largestElement();
    secondLargestelement();
    checkSorted();
    removeUniqueElements();
}