#include <bits/stdc++.h>
using namespace std;
bool linear_search(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}
void longest_consecutive_sequence_brute(vector<int> &arr)
{
    // TC=>O(N)*~O(N)~O(N^2)
    //SC=>O(1)
    int n = arr.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int counter = 1;
        while (linear_search(arr, x + 1) == true)
        {
            x = x + 1;
            counter += 1;
        }
        longest = max(longest, counter);
    }
    cout << longest << endl;
}
void longest_consecutive_sequence_better(vector<int> &arr)
{
    // TC=>O(NlogN)+O(N)
    //SC=>O(1)
    int n = arr.size();

    sort(arr.begin(), arr.end());
    int longest = 1;
    int curcount = 0;
    int lastSmallest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmallest)
        {
            curcount += 1;
            lastSmallest = arr[i];
        }
        else if (arr[i] != lastSmallest)
        {
            curcount = 1;
            lastSmallest = arr[i];
        }
        longest = max(longest, curcount);
    }
    cout << longest << endl;
}
void longest_consecutive_sequence_optimal(vector<int> &arr)
{
    //TC=>O(N)+O(2N)
    //SC=>O(n)
    int n=arr.size();
    if(n==0){
        return;
    }
    int longest=1;
    unordered_set<int>st;//Normal TC=>O(1) if collision happens(rare cases) O(n)
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int cnt=1;
            //O(2N)
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt+=1;
            }
            longest=max(longest,cnt);
        }
    }
    cout<<longest<<endl;
}

int main()
{
    vector<int> ve = {7, 1, 5, 3, 0, 4};
    longest_consecutive_sequence_brute(ve);
    longest_consecutive_sequence_better(ve);
    longest_consecutive_sequence_optimal(ve);
}