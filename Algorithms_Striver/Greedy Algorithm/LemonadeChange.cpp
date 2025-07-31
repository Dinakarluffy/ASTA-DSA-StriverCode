#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &arr)
{
    int five = 0, ten = 0;

    for (int bill : arr) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five == 0)
                return false;
            five--;
            ten++;
        } else if (bill == 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    vector<int> bills = {5,5,10,10,20};
    bool t = lemonadeChange(bills);
    if (t == 1)
        cout << "True";

    else
        cout << "False";
    return 0;
}