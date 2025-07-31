#include <bits/stdc++.h>

using namespace std;

int f(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;

  if (dp[n] != -1)
    return dp[n];
  return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main()
{

  // Memorization
  int n = 5;
  vector<int> dp(n + 1, -1);
  cout << f(n, dp);
  cout << endl;

  // Tabulation Format
  int m = 5;
  vector<int> dp_tab(m + 1, -1);

  dp_tab[0] = 0;
  dp_tab[1] = 1;

  for (int i = 2; i <= m; i++)
  {
    dp_tab[i] = dp_tab[i - 1] + dp_tab[i - 2];
  }
  cout << dp_tab[n];
  cout << endl;

  // Space Optimization
  int p = 5;

  int prev2 = 0;
  int prev = 1;

  for (int i = 2; i <= p; i++)
  {
    int cur_i = prev2 + prev;
    prev2 = prev;
    prev = cur_i;
  }
  cout << prev;
  return 0;
}