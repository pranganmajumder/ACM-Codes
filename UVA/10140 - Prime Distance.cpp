/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<ll,ll>
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


ll mark[10000000];
vector<ll>Prime;
void sieve(ll n)
{
    ll i,j,sq=sqrt(1.0*n)+2;
    mark[1]=1;//not prime
    for(i=4;i<=n;i=i+2)mark[i]=1;
    for(i=3;i<=sq;i=i+2){
        if(!mark[i]){
            for(j=i*i;j<=n;j+=(2*i))mark[j]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(!mark[i])Prime.pb(i);
    }
}

int arr[1000005];
ll res,mn,mx;
pii lo,hi;
ll k1,k2;
bool f1,f2;

bool segment(ll a,ll b){
    ll sqB=sqrt(1.0*b)+2,i,j;
    mems(arr,0);

    if(a==1)a++;
    for(i=0;i<Prime.size()&&Prime[i]<=sqB;i++){
        int p=Prime[i];
        j=p*p;
        if(j<a)j=((a+p-1)/p)*p;
        for(;j<=b;j+=p){
            arr[j-a]=1;/*mark as not prime*/
        }
    }

    res=0;
    f1=0,f2=0;
    for(i=a;i<=b;i++){
        if(f1&&f2)break;
        if(!arr[i-a]&&!f1){k1=i;f1=1;res++;}
        else if(!arr[i-a]&&!f2){k2=i;f2=1;res++;}

    }
    if(f1==1&&f2==1){
        lo=mk(k1,k2),hi=mk(k1,k2);
        mn=k2-k1,mx=k2-k1;
        for(i=k2+1;i<=b;i++){
            if(!arr[i-a]){
                k1=k2;
                k2=i;
                if(k2-k1<mn)mn=k2-k1,lo=mk(k1,k2);
                if(k2-k1>mx)mx=k2-k1,hi=mk(k1,k2);
                res++;//total prime but its not needed for this problem.
            }
        }
        return 1;
    }
    else return 0;
}


int main()
{
    ll n=sqrt(2147483650);
    sieve(n);

    ll a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        bool dustbin=segment(a,b);
        //pf("%lld\n",res);//res= total prime between that range
        if(dustbin){
            pf("%lld,%lld are closest, %lld,%lld are most distant.\n",lo.ff,lo.ss,hi.ff,hi.ss);
        }
        else pf("There are no adjacent primes.\n");
    }
return 0;
}




