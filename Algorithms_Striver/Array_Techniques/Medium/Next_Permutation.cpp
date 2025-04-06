#include <bits/stdc++.h>
using namespace std;
void next_permutation_brute(vector<int> &arr)
{
    // Brute force is very high level complexity because {N!*N} for permutation generate,len=5=>5!
    //=120,so we not use brute force solution
    int n = arr.size();
}
void next_permutation_better(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void next_permutation_optimal(vector<int> &arr)
{
    /*
    1.Generate all possible values in sort manner
    2.Linear search and get index
    3.Next index is answer if it not 0th index is answer
    */
    int n = arr.size();
    int index = -1;
    // Find the break point
    // n-2 near only changes will happen ex:[1,2,3,4,5]
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        // If no break index
        reverse(arr.begin(), arr.end());
        // return A;
    }
    // Find value that is > target but smallest

    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    // Try to place remaining number in sorted order
    reverse(arr.begin() + index + 1, arr.end());
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> ve = {3, 1, 2};
    next_permutation_better(ve);
    vector<int> v = {2, 1, 5, 4, 3, 0, 0};
    next_permutation_better(v);
}