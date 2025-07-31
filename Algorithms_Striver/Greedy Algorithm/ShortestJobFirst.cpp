#include <bits/stdc++.h>
using namespace std;
// Sheduling Policy that select the waiting process with the smallest execution time to execute next
void sjs(vector<int> &arr)
{
    //TC=>O(log n)+O(n)
    //SC=>O(1)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int t = 0;
    int waitTime = 0;
    for (int i = 0; i < n; i++)
    {
        waitTime += t;
        t += arr[i];
    }
    waitTime = waitTime / n;
    cout << waitTime << endl;
}
int main()
{
    vector<int> bt = {4, 3, 7, 1, 2};
    sjs(bt);
}