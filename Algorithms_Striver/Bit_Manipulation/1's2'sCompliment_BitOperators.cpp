#include <bits/stdc++.h>
using namespace std;
string reverse_string(string res)
{
    int start = 0;
    int end = res.size() - 1;
    while (start <= end)
    {
        char temp = res[start];
        res[start] = res[end];
        res[end] = temp;
        start++;
        end--;
    }
    return res;
}
string convertToBinary(int n)
{
    // TC=>O(log2n)
    string rem = "";
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            rem += '1';
        }
        else
        {
            rem += '0';
        }
        n = n / 2;
    }
    string res = reverse_string(rem);
    //cout << "The binary term is=>" << res;
    cout<<endl;
    return res;
}
int covertToDecimal(string x)
{
    
    int p = 0;
    int res = 0;
    /*reverse(x.begin(),x.end());
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        if(x[i]=='1'){
            res =res+( pow(2, i));

        }           
    }*/
   int p2=1;
   
   for(int i=x.size()-1;i>=0;i--){
        if(x[i]=='1'){
            res=res+p2;
        }
        p2=p2*2;
   }
    //cout << res << endl;
    return res;
}
int main()
{
    int n1 = 12;
    string x = convertToBinary(n1);
    cout << "The binary term is=>" << x<<endl;
    string x1="1011";
    int n = covertToDecimal(x);
    
    cout<<"the value=>"<<n<<endl;
    
    return 0;
}