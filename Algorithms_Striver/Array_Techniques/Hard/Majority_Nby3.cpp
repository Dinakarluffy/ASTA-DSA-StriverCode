#include <bits/stdc++.h>
using namespace std;
void majority_2_brute(vector<int> &arr)
{
    //TC=>O(n^2)
    //SC=>O(1)
    int n = arr.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.size() == 0 || ans[0] != arr[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 3)
            {
                ans.push_back(arr[i]);
            }
            if (ans.size() == 2)
            {
                break;
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout<<endl;
}
void majority_2_better(vector<int>&arr){
    int n=arr.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>n/3){
            cout<<it.first<<" ";
        }
    }
    cout<<endl;
}
void majority_2_better2(vector<int>&arr){
    //TC=>O(n)*log n
    //SC=>O(n)
    int n=arr.size();
    map<int,int>mpp;
    int min=(int)(n/3)+1;
    vector<int>ans;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==min){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2){
            break;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
        
    }
    cout<<endl;
}
void majority_2_optimal(vector<int>&arr){
    int n=arr.size();
    int cnt1=0;int cnt2=0;
    int el1,el2;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(cnt1==0){
            el1=arr[i];
            cnt1++;
        }
        else if(cnt2==0){
            el2=arr[i];
            cnt2++;
        }
        else if(el1==arr[i]){
            cnt1++;
        }
        else if(el2==arr[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]){cnt1++;}
        if(el2==arr[i]){cnt2++;}
    }
    int mini=(int)(n/3)+1;
    if(cnt1>=mini){ans.push_back(el1);}
    if(cnt2>=mini){ans.push_back(el2);}
    sort(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }

}
int main()
{
    vector<int> v = {2, 4, 2, 3,3, 3, 3, 3, 4, 4, 4, 4};
    majority_2_brute(v);
    majority_2_better(v);
    majority_2_better2(v);
    majority_2_optimal(v);
}