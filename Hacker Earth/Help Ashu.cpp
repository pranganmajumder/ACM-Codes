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

ll arr[mx];//tree[mx*3];

struct info{
    ll odd,even;
};


info tree[mx*3];

void createTree(ll node,ll lo,ll hi)
{
    if(lo==hi){
        if(arr[lo]%2==1){
            tree[node].odd=1;
            tree[node].even=0;
        }
        else{
            tree[node].even=1;
            tree[node].odd=0;
        }
        return ;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(lo+hi)/2;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);
    tree[node].even=tree[left].even+tree[right].even;
    tree[node].odd=tree[left].odd+tree[right].odd;
}

struct info query(ll node,ll lo,ll hi,ll i,ll j)
{
    if(lo>=i&&hi<=j)return tree[node];
    if(hi<i||lo>j){
       struct info temp2;
       temp2.odd=0;
       temp2.even=0;
        return temp2;
    }

    ll left=node*2;
    ll right=left+1;
    ll mid=(lo+hi)/2;

    struct info p1=query(left,lo,mid,i,j);
    struct info p2=query(right,mid+1,hi,i,j);

    struct info temp;
    temp.even=p1.even+p2.even;
    temp.odd=p1.odd+p2.odd;

    return temp;
}

void update(ll node,ll lo,ll hi,ll i,ll newValue)
{
    if(lo>i||hi<i)return ;
    if(lo==hi){
        if(newValue%2==1){
            tree[node].odd=1;
            tree[node].even=0;
        }
        else{
            tree[node].even=1;
            tree[node].odd=0;
        }
        return ;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(lo+hi)/2;
    update(left,lo,mid,i,newValue);
    update(right,mid+1,hi,i,newValue);
    tree[node].even=tree[left].even+tree[right].even;
    tree[node].odd=tree[left].odd+tree[right].odd;
}

int main()
{
    ll t,cas=1;
//    sc("%lld",&t);
//while(t--)
//{
    ll n,q,type,i,j;
    sc("%lld",&n);

    for(i=1;i<=n;i++)
        sc("%lld",&arr[i]);
    createTree(1,1,n);//Create Tree//
    sc("%lld",&q);

    //printf("Case %lld:\n",cas++);
    while(q--){

        sc("%lld%lld%lld",&type,&i,&j);
        if(type==0){//modify;
            update(1,1,n,i,j);
        }
        else{
            struct info res=query(1,1,n,i,j);
            if(type==1){
                printf("%lld\n",res.even);
            }
            else if(type ==2){
                printf("%lld\n",res.odd);
            }
        }
    }

//}
return 0;
}
