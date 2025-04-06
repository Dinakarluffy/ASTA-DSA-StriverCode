#include <bits/stdc++.h>
using namespace std;
void remove_duplicate_brute(vector<int> &arr)
{
    // TC=>O(Nlog(N)+N)
    // SC=>O(N)
    int n = arr.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int index = 0;
    for (auto it : s)
    {
        arr[index] = it;
        index++;
    }
    cout << index << endl;
}
void remove_duplicate_optimal(vector<int> &arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        } 
    }
    cout << i << endl;
}
int main()
{
    vector<int> v = {1, 1, 1, 1, 1, 2};
    remove_duplicate_brute(v);
    remove_duplicate_optimal(v);
}