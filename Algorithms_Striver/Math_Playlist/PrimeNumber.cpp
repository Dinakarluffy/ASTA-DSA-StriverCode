#include <bits/stdc++.h>
using namespace std;
// Prime numbers definition=the number contain only 2 divisors
void prime(int N)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            cnt++;
    }
    if (cnt == 2)
        cout << "The number is prime number" << endl;
    else
        cout << "The number is not prime number" << endl;
}
void prime_optimal(int N)
{
    // TC=>O(sprt(n))
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
        cout << "The number is prime number" << endl;
    else
        cout << "The number is not prime number" << endl;
}
int main()
{
    prime(6);
    prime_optimal(5);
    return 0;
}