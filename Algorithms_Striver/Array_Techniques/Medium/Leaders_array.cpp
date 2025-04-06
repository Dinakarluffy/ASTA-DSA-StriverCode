#include <bits/stdc++.h>
using namespace std;
void leaders_brute(vector<int> &arr)
{
    // TC=>O(N^2)
    // SC=>O(N)
    vector<int> lead;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            lead.push_back(arr[i]);
        }
    }
    for (auto it : lead)
    {
        cout << it << " ";
    }
    cout << endl;
}
void leaders_optimal(vector<int>&arr){
    int n=arr.size();
    int maxi=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        //It store leaders in sorted manner
        if(arr[i]>maxi){
            //maxi=arr[i];
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> ve = {7, 1, 5, 3, 6, 4};
    leaders_brute(ve);
    leaders_optimal(ve);
}