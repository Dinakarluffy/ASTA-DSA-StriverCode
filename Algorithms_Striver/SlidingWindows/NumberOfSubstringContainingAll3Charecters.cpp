#include <bits/stdc++.h>

using namespace std;

void numberofSubstring3charecters_brute(string s)
{
    // TC=>O(N^2)
    // SC=>O(1)
    int n = s.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> arr(3, 0); // For 'a', 'b', 'c' only

        for (int j = i; j < n; j++)
        {
            if (s[j] >= 'a' && s[j] <= 'c') // ensure we're only working with a, b, c
            {
                arr[s[j] - 'a'] = 1;
            }

            if (arr[0] + arr[1] + arr[2] == 3)
            {
                cnt += (n - j);
                break;
            }
        }
    }
    cout << cnt << endl;
}

void numberofSubstring3charecters_better(string s)
{
    // TC=>O(N^2)
    // SC=>O(1)
    int n = s.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> arr(3, 0); // For 'a', 'b', 'c' only

        for (int j = i; j < n; j++)
        {
            if (s[j] >= 'a' && s[j] <= 'c') // ensure we're only working with a, b, c
            {
                arr[s[j] - 'a'] = 1;
            }

            if (arr[0] + arr[1] + arr[2] == 3)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
void numberofSubstring3charecters_optimal(string s)
{
    //TC=>O(n)
    //SC=>O(1)
    int n = s.size();
    int l = 0;
    int r = 0;
    int cnt = 0;
    vector<int>lastSeen(3, -1);
 
        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
    
    cout << cnt << endl;
}
int main()
{
    string s = "bbacba";
    numberofSubstring3charecters_brute(s);
    numberofSubstring3charecters_better(s);
    numberofSubstring3charecters_optimal(s);

}