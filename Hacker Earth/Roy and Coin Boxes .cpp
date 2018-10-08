/**OOO**/
/**segment tree with lazy**/
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
#define mx                      1000005


struct info{
    int sum,p;
}tree[mx*4];


void createTree(int node,int lo,int hi)
{
    if(lo==hi){
        tree[node].sum=0;
        return ;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);
    //tree[node]=tree[left]+tree[right];
}
vector<ll>vec;
void query(int node,int lo,int hi,int i,int j,int carry)
{
    if(hi<i||lo>j)return ;
    if(lo>=i&&hi<=j){
        vec.pb(carry+tree[node].p);//vector a push koro.
        return ;
    }


    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    query(left,lo,mid,i,j,carry+tree[node].p);
    query(right,mid+1,hi,i,j,carry+tree[node].p);
    //ahane tree ar left right ar kaj amader dorkar hoy nai.tai kori nai.
}

void update(int node,int lo,int hi,int i,int j)
{
    if(hi<i||lo>j)return ;
    if(lo>=i&&hi<=j){//if present node range complete in update range
        tree[node].p+=1;
        return ;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    update(left,lo,mid,i,j);
    update(right,mid+1,hi,i,j);
    //tree[node]=tree[left]+tree[right];
}

int main()
{
  ll n,i,M,L,R,Q,X;
  scanf("%lld",&n);
  //create tree
  createTree(1,1,n);
  scanf("%lld",&M);
  for(i=0;i<M;i++){
    scanf("%lld%lld",&L,&R);
    //update tree
    update(1,1,n,L,R);
  }

  /**precalculate via query**/
  for(i=1;i<=n;i++){
        query(1,1,n,i,i,0);
  }
  sort(vec.begin(),vec.end());

  scanf("%lld",&Q);
  for(i=0;i<Q;i++){
        scanf("%lld",&X);
        //now start your binary search;
        ll it=lower_bound(vec.begin(),vec.end(),X)-vec.begin();
        pf("%lld\n",vec.size()-it);
  }
return 0;
}
