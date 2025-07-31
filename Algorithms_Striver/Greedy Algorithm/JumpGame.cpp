#include <bits/stdc++.h>
using namespace std;
void jumpGame(vector<int> &arr)
{
    //TC=>O(n)
    //SC=>O(1)
    int n = arr.size();
    int maxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxIndex)
        {
            cout << "False" << endl;
            break;
        }
        maxIndex = max(maxIndex, i + arr[i]);
        if (maxIndex >= n - 1)
        {
            break;

        }
    }
    cout << maxIndex << endl;
}
int main()
{
    vector<int> arr1 = {2, 3, 1, 0, 4};
    vector<int> arr2 = {3, 2, 1, 0, 4};
    jumpGame(arr1);
    return 0;
}