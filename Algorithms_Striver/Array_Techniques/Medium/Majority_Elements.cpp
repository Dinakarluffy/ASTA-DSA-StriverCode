#include <bits/stdc++.h>
using namespace std;
void majority_element_brute(vector<int> &arr)
{
    // TC=>O(N^2)
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void majority_element_better(vector<int> &arr)
{
    // TC=>O(N log N)
    // SC=>O(NlogN)
    map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
}
void majority_element_optimal(vector<int> &arr)
{
    //TC=>O(N) or O(N)+O(N) the array might not have majority element
    //SC=>O(1)
    int n = arr.size();
    int el;
    int count = 0;
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            el = arr[i];
        }
        else if (el == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (el == arr[i])
        {
            count1++;
        }
    }
    if (count1 > (n / 2))
    {
        cout << el << " ";
    }
    cout<<endl;
}

int main()
{
    vector<int> ve = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    // Majority_Elements is Array means=>N/2
    // Example:N=8 N is length of the array,N/2=4 so any element in the array should be present more than 4 times
    majority_element_brute(ve);
    majority_element_better(ve);
    majority_element_optimal(ve);
}