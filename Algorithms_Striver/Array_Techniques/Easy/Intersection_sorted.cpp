#include <bits/stdc++.h>
using namespace std;
void intersection_sorted_brute(vector<int> &arr1, vector<int> &arr2)
{
    // TC=>O(n1*n2)
    // SC=>O(n2)
    int n1 = arr1.size();
    int n2 = arr2.size();
    int vis[n2] = {0};
    vector<int> ans;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
void intersection_sorted_optimal(vector<int> &arr1, vector<int> &arr2)
{
    // TC=>O(n1+n2)
    // SC=>O(n1+n2)
    int n1 = arr1.size();
    int n2 = arr2.size();
    int vis[n2] = {0};
    vector<int> ans;
    int i=0;int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;j++;
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {0,1, 2, 3};
    intersection_sorted_brute(v1, v2);
    intersection_sorted_optimal(v1, v2);
}