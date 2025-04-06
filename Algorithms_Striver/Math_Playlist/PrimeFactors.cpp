#include <bits/stdc++.h>
using namespace std;
bool prime(int N)
{
    int cnt = 0;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            cnt++;
            if (N / i != i)
                cnt++;
        }
    }
    if (cnt == 2)
        return true;
    return false;
}
void primeFactors(int N)
{
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            if (prime(i))
            {
                arr.push_back(i);
            }
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void primeFactors_best(int N)
{
    vector<int> arr;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0 && prime(i))
        {

            arr.push_back(i);
            if ((N / i) != i)
            {
                if (prime(N / i) == true)
                {
                    arr.push_back(N / i);
                }
            }
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void primeFactors_optimal(int N)
{
    // TC cases
    // For large Number TC is prime Number=>O(N)
    //
    vector<int> ans;
    // i=2 because it starting prime number
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            ans.push_back(i);
        }
        while (N % i == 0)
        {
            N = N / i;
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
void primeFactors_optimal1(int N)
{
    // TC =>O(sqrt(N)*log N)
    vector<int> ans;
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ans.push_back(i);
        }
        while (N % i == 0)
        {
            N = N / i;
        }
    }
    if (N != 1)
        ans.push_back(N);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<int> findPrimeFactors(int N)
{

    // Write your code here
    vector<int> ans;

    for (int i = 2; i * i <= N; i++)
    {
        // Check if 'i' is a divisor of N
        while (N % i == 0)
        {
            ans.push_back(i); // Add 'i' to the result each time it divides N
            N = N / i;        // Reduce N by dividing by 'i'
        }
    }

    // If there's any prime factor larger than sqrt(N) left (i.e., N > 1), add it
    if (N > 1)
    {
        ans.push_back(N);
    }

    return ans;
}
int main()
{
    primeFactors(36);
    primeFactors_best(780);
    primeFactors_optimal(780);
    primeFactors_optimal1(780);
}