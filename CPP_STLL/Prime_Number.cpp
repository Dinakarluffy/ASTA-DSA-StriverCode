#include<bits/stdc++.h>
using namespace std;
int main(){
    //optimal solution

    int n=4;
    int count=0;
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }

    if(count==2){
        cout<<"The given number is prime number"<<endl;
    }
    else{
        cout<<"It's not prime number"<<endl;
    }
}