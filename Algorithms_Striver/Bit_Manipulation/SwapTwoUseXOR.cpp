#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b){ // for a>b always 
    a=a-b;
    b=a+b;
    a=b-a;
    return pair<int,int>(a,b);
  }
int main()
{
    int a = 10;
    int b = 20;
    cout << a << " " << b << endl;

    a = a ^ b;
    b = a ^ b; // b get a value
    a = a ^ b; // a get b vaule

    cout << a << " " << b << endl;
    return 0;
}