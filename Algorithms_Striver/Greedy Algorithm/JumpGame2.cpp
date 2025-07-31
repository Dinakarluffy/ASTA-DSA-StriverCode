#include <bits/stdc++.h>
using namespace std;
void jumpGame2(vector<int> &arr)
{
    // TC: O(n)
    // SC: O(1)
    int n = arr.size();
    int jumps = 0, currentEnd = 0, farthest = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        farthest = max(farthest, i + arr[i]);

        // when we reach the end of the current jump range
        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;

            // early exit if we already reached or passed the end
            if (currentEnd >= n - 1)
                break;
        }
    }

    cout << jumps << endl;
}
int main()
{
    vector<int> arr = {2, 3, 1, 4, 1, 1, 1, 2};
    jumpGame2(arr);
}