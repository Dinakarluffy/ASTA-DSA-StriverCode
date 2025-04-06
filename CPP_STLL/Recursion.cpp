#include <bits/stdc++.h>
using namespace std;
void printNtime(int i, int n)
{
    // TC=>O(n)
    // SC=>O(N)->stact space
    if (i > n)
    {
        return;
    }
    cout << "Asta" << endl;
    printNtime(i + 1, n);
}
void print1ToN(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;

    print1ToN(i + 1, n);
}
void printNTo1(int i,int n)
{
    if(i<1){
        return;
    }
    cout<<i<<endl;
    printNTo1(i-1,n);
}
void print1ToNBacktracking(int i,int n){
    if(i<1){
        return;
    }
    
    print1ToNBacktracking(i-1,n);
    cout<<i<<endl;

}
void printNTo1Backtracking(int i,int n){
    if(i>n){
        return;
    }
    
    printNTo1Backtracking(i+1,n);
    
    cout<<i<<endl;
    

}

int main()
{
    cout<<"Print N time using Recursion"<<endl;
    printNtime(1, 4);
    cout<<"Print 1 to N using Recursion"<<endl;
    print1ToN(1, 7);
    cout<<"Print N to 1 using Recursion"<<endl;
    printNTo1(5,5);
    cout<<"Print 1 to N using Recursion(BackTracking)"<<endl;
    print1ToNBacktracking(5,5);
    cout<<"Print N to 1 using Recursion(BackTracking)"<<endl;
    printNTo1Backtracking(1,5);
}