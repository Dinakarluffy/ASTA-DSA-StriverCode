#include <bits/stdc++.h>
using namespace std;
// Print all subsets
// nums=[1 2 3]
//[],[1],[2],[3],[1,2]...
// if n=3 ,2^n=>8 subsets
// in bits 1<<n
void print_powerSet_bitsManipulaiton(vector<int> &arr)
{
    //TC=>O(n*2^n)
    //SC=>O(n*2^n)
    int n = arr.size();
    // int range=pow(2,n);
    int subsets = 1 << n;
    vector<vector<int>> ans;
    for (int num = 0; num < subsets; num++)
    {
        vector<int> list;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                list.push_back(arr[i]);
            }
        }
        ans.push_back(list);
    }
    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    print_powerSet_bitsManipulaiton(arr);
}