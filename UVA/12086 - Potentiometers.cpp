/**segment tree**/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;
#define pii pair<int, int>
#define mem(x,y) memset(x,y,sizeof(x))
#define sc scanf
#define pf printf
#define pb push_back
#define pu push
#define uu first
#define vv second
#define DIST(x1,y1,x2,y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define pi acos(-1)
#define ull unsigned long long int
#define MOD 1000000007
int fx[]={1,-1,0,0,-1,-1,1,1};
int fy[]={0,0,1,-1,-1,1,-1,1};
ll a[200005];
ll tree[4*200005];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if(b>j||e<i)
    {
        return 0;
    }
    if(b>=i&&e<=j)
    {
        return tree[node];
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b)
    {
        return;
    }
    if(b>=i&&e<=i)
    {
        tree[node]=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}

int main()
{
    ll n, i, j=1;
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);
    while(sc("%lld",&n)==1&&n!=0)
    {
        for(i=1; i<=n; i++)
        {
            sc("%lld",&a[i]);
        }
        init(1,1,n);
        char s[5];
        if(j>1)
        {
            pf("\n");
        }
        pf("Case %lld:\n", j);

        j++;
        while(sc("%s",&s))
        {
            ll x, y;
            if(strcmp(s,"END")==0)
            {
                break;
            }
            sc("%lld %lld",&x,&y);
            if(s[0]=='S')
            {
                update(1,1,n,x,y);
            }
            else
            {
                ll sum=query(1,1,n,x,y);
                pf("%lld\n",sum);
            }
        }

    }
    return 0;
}
