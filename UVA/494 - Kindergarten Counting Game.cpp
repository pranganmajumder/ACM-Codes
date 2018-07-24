#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    while(getline(cin,st))
    {
       int len=st.size(),i;
       int sum=0;

       bool f=0;
       for(i=0;i<=len;i++){
          if(st[i]>=65&&st[i]<=90){
                f=1;
                continue;
          }
          else if(st[i]>=97&&st[i]<=122){
                f=1;
                continue;
          }
          else{
            if(f){
                f=0;
                sum++;
            }
          }
       }
       cout<<sum<<endl;
    }
}

