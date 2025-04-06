#include<bits/stdc++.h>
using namespace std;
int fibnocci(int n){

    //TC=>O(2^n)
    if(n<=1){
        return n;
    }
    int last=fibnocci(n-1);
    int slast=fibnocci(n-2);
    return last+slast;
}
int main(){
    
    int n=fibnocci(4);
    cout<<"Fibnocci numbers using recursion"<<endl;
    cout<<fibnocci(4);
}