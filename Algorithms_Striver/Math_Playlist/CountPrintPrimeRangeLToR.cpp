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
            if ((N / i) != i)
                cnt++;
        }
    }
    if (cnt == 2)
        return true;
    return false;
}
vector<int> Sieve_Of_Eratosthenes(int N)
{
    vector<int> ans(N + 1, 1);
    ans[1] = 0;
    ans[0] = 0; // because both 0 and 1 are not prime numbers
    for (int i = 2; i * i <= N; i++)
    {
        if (prime(i))
        {
            for (int j = i * i; j <= N; j += i)
            {
                ans[j] = 0;
            }
        }
    }
    return ans;
}
void CountPrime(vector<vector<int>> &arr)
{
    // TC=>O(q*(r-l+1)*sqrt(n))
    vector<int> ans;
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int l = arr[i][0];
        int r = arr[i][1];
        for (int j = l; j <= r; j++)
        {
            if (prime(j))
                cnt++;
        }
        ans.push_back(cnt);
        cnt = 0;
    }
    int i = 1;
    for (auto it : ans)
    {
        cout << "The Number of Prime Number present in Q range " << i++ << ":" << it << endl;
    }
    cout << endl;
}
void CountPrime_better(vector<vector<int>> &arr)
{
    // TC=>O(q*(r-l+1)*sqrt(n))
    vector<int> ans;
    int N = 10;

    vector<int> primeValue = Sieve_Of_Eratosthenes(N);
    int cnt;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int l = arr[i][0];
        int r = arr[i][1];
        cnt = 0;
        for (int j = l; j <= r; j++)
        {
            if (primeValue[j] == 1)
                cnt++;
        }
        ans.push_back(cnt);
    }
    int i = 1;
    for (auto it : ans)
    {
        cout << "The Number of Prime Number present in Q range " << i++ << ":" << it << endl;
    }
    cout << endl;
}
void CountPrime_optimal(vector<vector<int>> &arr)
{
    //TC=>O(N log log N)+O(N)+O(arr)
    vector<int> primeN = Sieve_Of_Eratosthenes(100);
    int cnt = 0;
    vector<int> ans;
    for (int i = 2; i < 100; i++)
    {
        cnt += primeN[i];
        primeN[i] = cnt;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int l = arr[i][0];
        int r = arr[i][1];
        int tot = primeN[r] - primeN[l - 1];//l-1 because we need value of primeN[2] because the starting prime number is 2
        cout << "The Number of Prime Number present in Q range " << i+1 << ":" << tot << endl;
    }
}

int countPrimes(int n) {
    int count = 0 ;
    vector<bool> isPrime(n+1,true);//assuming all elelemnts be prime
    for(int i = 2 ; i < n ; ++i){
        if(isPrime[i] == true){
            count++;
        }
        for(int j = i*2 ; j < n ; j = j + i){
            isPrime[j] = false;//Discarding all the multiple of current elemeney(i)
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> arr = {{3, 5}, {1, 10}};
    CountPrime(arr);
    CountPrime_better(arr);
    CountPrime_optimal(arr);
}