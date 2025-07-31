#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
void longestRepeatingCharecterReplacement_brute(string s, int k)
{
    //TC=>O(n)*O(n)
    //SC=>O(26)
    int n = s.size();
    int maxlen = 0;

    for (int i = 0; i < n; i++) // Start of the substring
    {
        vector<int> hash(26, 0); // Frequency array for characters A-Z
        int changes = 0;         // Number of characters to change
        int maxfreq = 0;         // Maximum frequency of any character in the current substring

        for (int j = i; j < n; j++) // End of the substring
        {
            hash[s[j] - 'A']++;                       // Increment the frequency of character s[j]
            maxfreq = max(maxfreq, hash[s[j] - 'A']); // Update the max frequency for the current window
            changes = (j - i + 1) - maxfreq;          // Number of changes needed to make all chars the same

            if (changes <= k) // If changes are within the allowed limit
            {
                maxlen = max(maxlen, j - i + 1); // Update the max length of the substring
            }
            else // If the number of changes exceeds k, break out of the loop
            {
                break;
            }
        }
    }

    cout << "Brute Force Result: " << maxlen << endl; // Output the result
}

// Optimal Sliding Window Approach
void longestRepeatingCharecterReplacement_optimal(string s, int k)
{
    // TC=>(O(n)+O(N))*O(26)
    int n = s.size();
    int maxlen = 0;
    int maxfreq = 0;
    int l = 0;
    vector<int> hash(26, 0);

    for (int r = 0; r < n; r++)
    {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

        // If the window size minus the most frequent char count exceeds k, shrink the window
        while ((r - l + 1) - maxfreq > k)
        {
            hash[s[l] - 'A']--;
            l++;

            // Recompute maxfreq by scanning the hash array
            maxfreq = *max_element(hash.begin(), hash.end());
        }

        maxlen = max(maxlen, r - l + 1);
    }

    cout << "Optimal Result: " << maxlen << endl;
}

void longestRepeatingCharecterReplacement_optimal1(string s, int k)
{
    // TC=>(O(n))
    int n = s.size();
    int maxlen = 0;
    int maxfreq = 0;
    int l = 0;
    vector<int> hash(26, 0);

    for (int r = 0; r < n; r++)
    {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

        // If the window size minus the most frequent char count exceeds k, shrink the window
        if ((r - l + 1) - maxfreq > k)
        {
            hash[s[l] - 'A']--;
            l++;           
        }

        maxlen = max(maxlen, r - l + 1);
    }

    cout << "Optimal Result: " << maxlen << endl;
}

int main()
{
    string s = "AABABBA";
    int k = 2;
    longestRepeatingCharecterReplacement_brute(s, k);
    longestRepeatingCharecterReplacement_optimal(s, k);
    return 0;
}
