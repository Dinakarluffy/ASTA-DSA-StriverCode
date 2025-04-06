#include <bits/stdc++.h>

using namespace std;
// Every number appear twice in list ,but tow distince number present in list
void singleNumber_brute(vector<int> &arr)
{
    // TC=>O(N*logm)+O(m)
    // SC=>O(m)
    // m=(n/2+1)
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            cout << it.first << " ";
        }
    }
    cout << endl;
}
void singleNumber_bitManipulation_optimal2(vector<int> &arr)
{
    // Use buckets concept here,oneBucket(contain 1sr bit 1),twoBucket(1st bit 0)
    int ones = 0;
    int twos = 0;
    int n = arr.size();
    long  Xor = 0;//because -2^31 &(-2^31) for small for int
    //TC=>O(2n)
    //SC=>O(1)
    for (int i = 0; i < n; i++)
    {
        Xor = Xor ^ arr[i];
    }
    int rightmost =  Xor & -Xor;//or use this  (Xor & (Xor-1))^Xor
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightmost)  // XOR elements with the rightmost bit set
        {
            ones = ones ^ arr[i];
        }
        else
        {
            twos = twos ^ arr[i]; // XOR elements with the rightmost bit not set
        }
    }
    cout << ones << " " << twos << " " << endl;
}
int main()
{
    vector<int> arr = {5, 5, 2, 3, 4, 4};
    singleNumber_brute(arr);
    singleNumber_bitManipulation_optimal2(arr);
}