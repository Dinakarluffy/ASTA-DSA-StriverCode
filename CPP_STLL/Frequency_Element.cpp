#include <bits/stdc++.h>
using namespace std;
int frequency(int e, int a[], int n)
{

    // TC=>O(Q(n))
    // Q=Number of times for search
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == e)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 5;
    int a[5] = {1, 1, 1, 1, 1};
    //int f = frequency(1, a, n);
    //cout << "The frequecny of element is=>" << f << endl;

    // Hashing in numbers
    int hash[13] = {0};
    // The maximum element array can store in INT is 10^6 (only inside the main(in boolean size is 10^7))
    // If you want to store mean array store in INT upto 10^7(it only applicable only when array is global=>in boolean size is 10^8)
    for (int i = 0; i < n; i++)
    {
        // Fetching operation
        hash[a[i]] += 1;
    }

    cout << hash[13] << endl;

    // hashing in charecters to find frequency in charecters
    string s = "hello";
    int hashC[256] = {0};

    for (int i = 0; i < n; i++)
    {
        // Fetching operation
        hashC[s[i]] += 1; // or hashC[s[i]] += 1;
    }
    cout << hashC['l'] << endl; // or hashC['c']

    // Hashing using map
    /*
        map TC is=>O(logN)=>for worst,average,best cases and N is the number of elements because it store the value in sorted manner
        unorder_map TC+>O(1) for average,best cases ,worst case=>TC=O(N) because it doesn't store sorted manner
    */
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        // Fetching operation
        m[a[i]] += 1;
    }

    cout << m[1] << endl;


    //Hashing in charecter using in map

    unordered_map<char, int> mc;
    for (int i = 0; i < n; i++)
    {
        // Fetching operation
        mc[s[i]] += 1;
    }

    cout << mc['h'] << endl;
}