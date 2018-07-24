
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

#define pf                      printf
#define sc                      scanf
#define inf                     100000000
#define mx                      100005

ll arr[mx],tree[mx*3];

void createTree(int node,int lo,int hi)
{
    if(lo==hi){
        tree[node]=arr[lo];
        return ;
    }
    int left=node*2;
    int right=left+1;
    int mid=(lo+hi)/2;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);
    tree[node]=min(tree[left],tree[right]);
}

ll query(int node,int lo,int hi,int i,int j)
{
    if(lo>=i&&hi<=j)return tree[node];
    if(hi<i||lo>j)return inf;

    int left=node*2;
    int right=left+1;
    int mid=(lo+hi)/2;

    ll p1=query(left,lo,mid,i,j);
    ll p2=query(right,mid+1,hi,i,j);

    return min(p1,p2);
}

//void update(int node,int lo,int hi,int i,int newValue)
//{
//    if(lo>i||hi<i)return ;
//    if(lo==hi){
//        tree[node]=newValue;
//        return ;
//    }
//    int left=node*2;
//    int right=left+1;
//    int mid=(lo+hi)/2;
//    update(left,lo,mid,i,newValue);
//    update(right,mid+1,hi,newValue);
//    tree[node]=min(tree[left],tree[right]);
//}

int main()
{
    ll t,cas=1;
    sc("%lld",&t);
while(t--)
{
    ll n,q,i,j;
    sc("%lld%lld",&n,&q);

    for(i=1;i<=n;i++)
        sc("%lld",&arr[i]);
    createTree(1,1,n);//Create Tree//
    printf("Case %lld:\n",cas++);
    while(q--){
        sc("%lld%lld",&i,&j);
        ll res=query(1,1,n,i,j);//search into range i==>> j /
        printf("%lld\n",res);
    }

}
return 0;
}
