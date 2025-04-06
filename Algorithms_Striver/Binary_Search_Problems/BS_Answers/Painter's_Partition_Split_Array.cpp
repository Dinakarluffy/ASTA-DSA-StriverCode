#include <bits/stdc++.h>
using namespace std;
//Painter's partition and split array is same concept
//Split array=>split the array into k subarrays such that the max subarray sum is minimum
int cntStudent(vector<int> &arr, int pages)
{
    int n = arr.size();
    int st = 1;
    int pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            st++;
            pagesStudent = arr[i];
        }
    }
    return st;
}
int PaintersPartition_orSplitArray(vector<int> &arr, int s)
{
    //TC=>O(sum -max+1)*O(N)
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int cntStu = 0;
    if (s > n)
    {
        return -1;
    }
    for (int pages = low; pages <= high; pages++)
    {
        cntStu = cntStudent(arr, pages);
        if (cntStu == s)
        {
            return pages;
        }
    }
    return low;
}
int PaintersPartition_orSplitArray_BS(vector<int> &arr, int s)
{
    //TC=>O(log2(sum -max+1))*O(N)
    int n = arr.size();
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int cntStu = 0;
    if (s > n)
    {
        return -1;
    }
    while(low<=high){
        long long mid=(low+high)/2;
        cntStu=cntStudent(arr,mid);
        if(cntStu>s){
            low=mid+1;
            
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {10,20,30,40};
    int painter = 2;
    int n = PaintersPartition_orSplitArray(arr, painter);
    cout << n << endl;
    int n1= PaintersPartition_orSplitArray_BS(arr, painter);
    cout << n1 << endl;
}