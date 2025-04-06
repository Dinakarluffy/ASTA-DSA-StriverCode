#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int> &nums, int k)
{
    int l=0,r=0;
    sort(nums.begin(),nums.end());
    int res=0,tot=0;
    int n=nums.size();
    while(r<n){
        while(nums[r] * (r-l+1)>tot+k){
            tot-=nums[l];
            l+=1;


        }
        res=max(res,(r-l+1));
        r+=1;
    }
    return res;
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();

    for (auto it : v)
    {
        cout << it << " ";
    }
}