#include <bits/stdc++.h>
using namespace std;
void best_time_buy_sell_stocks(vector<int> &arr)
{
    //Buy should happen first and selling is second (buy and sell is once)
    int n = arr.size();
    int max_profit = 0; // For selling the stocks
    int mini = arr[0];  // For buy the stocks
    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        max_profit = max(max_profit, cost);
        mini = min(mini, arr[i]);
    }
    cout<<max_profit<<endl;
}
int main()
{
    vector<int> ve = {7, 1, 5, 3, 6, 4};
    best_time_buy_sell_stocks(ve);
}