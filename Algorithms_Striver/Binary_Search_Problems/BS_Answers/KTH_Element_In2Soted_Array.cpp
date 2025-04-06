#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    vector<int> arr3;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < m)
        arr3.push_back(a[i++]);
    while (j < n)
        arr3.push_back(b[j++]);
    return arr3[k - 1];
}

int kthElement_optimal(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
    {
        kthElement_optimal(b,a,k);
    }
    int n = n1 + n2;
    int left = k;
    int low = max(0,k-n2);//if we assigh low=0 it pick nothing 
    int high = min(k,n1);
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if (mid1 < n1)
        {
            r1 = a[mid1];
        }
        if (mid2 < n2)
        {
            r2 = b[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = a[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = b[mid2 - 1];
        }
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return 0;
}
int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
