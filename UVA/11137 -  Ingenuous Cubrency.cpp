/**OOO**/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mems(arr,Val)       memset(arr,Val,sizeof(arr))
#define mod                 100000007
using namespace std;



ll dp[25][10005];//koto number array, color
//int visit[105][105];
int coin[25];

int k;

ll fun(int pos,int curr)
{
    if(pos==22){
        if(curr==k)return 1;
        return 0;
    }

    if(dp[pos][curr]!=-1)return dp[pos][curr];

    ll p1=0,p2=0;
    if(curr+coin[pos]<=k)
        p1+=fun(pos,curr+coin[pos]);
    p2=fun(pos+1,curr);
    return dp[pos][curr]=p1+p2;
}

void coin_gen()
{
    for(int i=1;i<=22;i++){
        coin[i]=i*i*i;
    }
}


int main()
{
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);
    coin_gen();
    while(scanf("%lld",&k)!=EOF)
    {
        mems(dp,-1);
        ll res=fun(1,0);
        cout<<res<<endl;
    }
    return 0;
}

