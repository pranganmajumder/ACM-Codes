/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;


#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<int,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define PI                      acos(-1.0)

#define pf                      printf
#define sc                      scanf
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000

void pri(const vector<ll>&v);


ll mark[10000002];//1e6
ll nPrime;//3e5
vector<ll>allPrimeUp2N;

void sieve(ll n)
{   ll i,j,sq=sqrt(1.0*n)+2;
    mark[0]=1;
    mark[1]=1;
    for(i=4;i<=n;i=i+2)mark[i]=1;//1 mane not prime. 0 mane prime


    for(i=3;i<=sq;i=i+2){
        if(!mark[i]){//prime
            for(j=i*i;j<=n;j+=2*i)//mark all odd multiple of i
                mark[j]=1;
        }
    }

    for(i=1;i<=n;i++){
        if(mark[i]==0)allPrimeUp2N.pb(i);
    }
    nPrime=allPrimeUp2N.size();//total prime upto n;
}

int flag[124];

int main()
{
    sieve(100000);


   int input,i,j,k,len,cas=1;
   scanf("%d",&input);
   while(input--)
   {
       mems(flag,0);

        string st;
        cin>>st;
        len=st.size();
        for(i=0;i<len;i++)
            flag[st[i]]++;

        bool f=0;
        printf("Case %d: ",cas++);
        for(i=48;i<=57;i++){
            if(mark[flag[i]]==0){cout<<(char)i;f=1;}
        }
        for(i=65;i<=90;i++){
            if(mark[flag[i]]==0){cout<<(char)i;f=1;}
        }
        for(i=97;i<=122;i++){
            if(mark[flag[i]]==0){cout<<(char)i;f=1;}
        }
        if(!f)cout<<"empty";
        cout<<endl;
    }

return 0;
}



