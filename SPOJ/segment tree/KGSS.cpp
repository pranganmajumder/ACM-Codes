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
#define mx                      100000

ll arr[mx*4];

struct info{
    ll a,b;
};

info tree[mx*4];

info f(info s1,info s2)
{
    vector<ll>v;
    info t;

    v.pb(s1.a);
    v.pb(s1.b);
    v.pb(s2.a);
    v.pb(s2.b);
    sort(v.begin(),v.end());
    t.a=v[3];
    t.b=v[2];
    return t;
}

void createTree(ll node,ll lo,ll hi){
    if(lo==hi){
        tree[node].a=arr[lo];
        tree[node].b=0;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(lo+hi)>>1;
    createTree(left,lo,mid);
    createTree(right,mid+1,hi);
    tree[node]=f(tree[left],tree[right]);
}

void update(ll node,ll lo,ll hi,ll i,ll newvalue)
{
    if(lo>i||hi<i)return ;
    if(lo==hi){
        tree[node].a=newvalue;
        tree[node].b=0;
        return;
    }
    ll left=node<<1;
    ll right=left+1;
    ll mid=(lo+hi)>>1;
    update(left,lo,mid,i,newvalue);
    update(right,mid+1,hi,i,newvalue);
    tree[node]=f(tree[left],tree[right]);
}

info query(ll node,ll lo,ll hi,ll i,ll j)
{
    if(hi<i||lo>j){//range ar baire cole gele
        info t;
        t.a=0;
        t.b=0;
        return t;
    }
    if(lo>=i&&hi<=j){//completely range ar vitore thakle
        return tree[node];
    }

    ll left=node<<1;
    ll right=left+1;
    ll mid=(lo+hi)>>1;

    info p1=query(left,lo,mid,i,j);
    info p2=query(right,mid+1,hi,i,j);
    info res=f(p1,p2);
    return res;
}


ll n,q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)cin>>arr[i];
    createTree(1,1,n);

    cin>>q;
    while(q--){
        char ch;ll i,j;
        cin>>ch>>i>>j;
        if(ch=='U'){
            update(1,1,n,i,j);
        }
        else if(ch=='Q'){
            info res=query(1,1,n,i,j);
            cout<<res.a+res.b<<endl;
        }

    }
return 0;
}



