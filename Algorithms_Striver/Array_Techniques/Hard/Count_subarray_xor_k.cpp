#include <bits/stdc++.h>
using namespace std;
void count_subarray_xor_k(vector<int> &arr, int k)
{
    // TC=>O(N^3)
    // SC=>O(1)
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int Xor = 0;
            for (int k = i; k <= j; k++)
            {
                Xor = Xor ^ arr[k];
            }
            if (Xor == k)
            {
                cnt += 1;
            }
        }
    }
    cout << cnt << endl;
}
void count_subarray_xor_k_better(vector<int> &arr, int k)
{
    // TC=>O(N^3)
    // SC=>O(1)
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int Xor = 0;
        for (int j = i; j < n; j++)
        {
            Xor = Xor ^ arr[j];
            if (Xor == k)
            {
                cnt += 1;
            }
        }
    }
    cout << cnt << endl;
}
void count_subarray_xor_k_optimal(vector<int> &arr, int k)
{
    // TC=>O(N) or O(N log N)
    // SC=>O(N)
    int n = arr.size();
    int cnt = 0;
    int Xor=0;
    map<int,int>mp;
    mp[Xor]++;//it help to insert  {0,1}
    for (int i = 0; i < n; i++)
    {
        
        Xor=Xor ^arr[i];

        cout<<"The Xor value=>"<<Xor<<endl;
        int x=Xor ^ k;
        cnt+=mp[x];
        mp[Xor]++;
    }
    cout << cnt << endl;
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

}

int main()
{
    vector<int> v = {4, 2, 2, 6, 4};
    count_subarray_xor_k(v, 6);
    count_subarray_xor_k_better(v, 6);
    count_subarray_xor_k_optimal(v, 6);
}