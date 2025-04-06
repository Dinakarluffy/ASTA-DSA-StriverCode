#include <bits/stdc++.h>
using namespace std;
void move_zero_brute(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp;
    // TC=>o(N)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    int nz = temp.size();
    // TC=>O(N)
    for (int i = 0; i < nz; i++)
    {
        arr[i] = temp[i];
    }

    // TC=>O(n-N)
    for (int i = nz; i < n; i++)
    {
        arr[i] = 0;
    }
    // TC=>O(2N)
    // SC=>O(N)

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void move_zeros_optimal(vector<int>&arr){
    int j=-1;
    int n=arr.size();
    //TC=>O(x)
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    //if(j==-1) return arr;
    //TC=>O(n-x);
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    //TC=>O(n)
    //SC=>O(1)

    for(auto it:arr){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> v = {0,0,2};
    move_zero_brute(v);
    move_zeros_optimal(v);
}