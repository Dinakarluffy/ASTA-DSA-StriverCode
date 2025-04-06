#include<bits/stdc++.h>
using namespace std;
void linear_search(vector<int>&arr,int s){
    int n=arr.size();

    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==s){
            index=i;
            break;
        }
    }
    cout<<"The searching element present in "<<index<<" (index)"<<endl;
}
int main(){
    vector<int>v={1,2,3,45};
    linear_search(v,3);
}