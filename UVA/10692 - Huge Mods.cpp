/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;

ll n;
ll arr[100];
int phi[5000005];


void euler(ll n)
{   ll i,j;
    for(i=1;i<=n;i++)phi[i]=i;

    for(i=2;i<=n;i++){
        if(phi[i]==i){
            for(j=i;j<=n;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}


ll bigmod(ll base,ll p,ll mod)//base, p bar gun
{
    ll res=1;
    base=base%mod;
    while(p>0){
        if(p%2==1)res=((res%mod)*(base%mod))%mod;
        base=((base%mod)*(base%mod))%mod;
        p=p/2;
    }
    return res;
}

ll f(ll i,ll m)
{   ll p,base;
    if(i+1==n+1){
        base=arr[i];
        p=1;
        return bigmod(base,p,m);
    }
    base=arr[i];
    p=f(i+1,phi[m])+phi[m];//if i dont use +phi[m] then it would wrong for if a & m is not coprime.
    return bigmod(base,p,m);
}

int main()
{   euler(5000000);

ll cas=1;

ll mod,i,j,z;

while(true){
    vector<ll>v;
    string st;
    getline(cin,st);
    if(st=="#")break;

    stringstream ss(st);
    while(ss>>z)
        v.push_back(z);



    mod=v[0];
    n=v[1];
    for(i=1,j=2;i<=n;i++,j++)
        arr[i]=v[j];
    ll res=f(1,mod);

    printf("Case #%lld: %lld\n",cas++,res);
    v.clear();
}
return 0;
}

