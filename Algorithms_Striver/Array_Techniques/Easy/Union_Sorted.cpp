#include <bits/stdc++.h>
using namespace std;
void union_sorted_brute(vector<int> &arr1, vector<int> &arr2)
{
    set<int> s;
    int n1 = arr1.size();
    int n2 = arr2.size();
    for (int i = 0; i < n1; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s.insert(arr2[i]);
    }

    for (auto it : s)
    {
        cout << it << " ";
    }

    // TC=>O(n1logn1) +O(n2logn2)+O(n1+n2)
    // SC=>O(n1+n2)(this is store the value in set)+O(n1+n2)(this is return the answer)
}
void union_sorted_optimal(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> un;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (un.size() == 0 || un.back() != arr1[i])
            {
                un.push_back(arr1[i]);
            }
            i++;
        }
        else
        {

            if (un.size() == 0 || un.back() != arr2[j])
            {
                un.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (un.size() == 0 || un.back() != arr1[i])
        {
            un.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (un.size() == 0 || un.back() != arr2[j])
        {
            un.push_back(arr2[j]);
        }
        j++;
    }

    cout << endl;
    for (auto it : un)
    {
        cout << it << " ";
    }

    // TC=>+O(n1+n2)
    // SC=>O(n1+n2)
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {7};
    union_sorted_brute(v1, v2);
    union_sorted_optimal(v1, v2);
}