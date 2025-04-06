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
            if ((N / i) != N)
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
        return true;
    return false;
}
void SeiveOfEratosthenes(int N)
{
    // TC=>O(N)+O(N log (logN))+O(N)
    //  vector<int> arr(N + 1, 1);
    //  or
    int prime[N + 1];
    for (int i = 2; i <= N; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    SeiveOfEratosthenes(31);
}