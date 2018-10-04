/**joyram**/
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

#define pf                      printf
#define sc                      scanf
#define mx                      100005

struct info{
    ll p,zero,one,two;
}tree[mx*4];

void createTree(int node,int lo,int hi)
{
    if(lo==hi){
        tree[node].zero=hi-lo+1;
        tree[node].one=0;
        tree[node].two=0;
        return ;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);

    tree[node].zero = tree[left].zero+tree[right].zero;
    tree[node].one=tree[node].two=0;
}



ll query(int node,int lo,int hi,int i,int j,int carry)
{
    if(hi<i||lo>j)return 0;
    if(lo>=i&&hi<=j){
        ll a=carry%3;
        if(a==0)return tree[node].zero;
        else if(a==1)return tree[node].two;
        else if(a==2) return tree[node].one;
    }

    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    ll p1=query(left,lo,mid,i,j,carry+tree[node].p);
    ll p2=query(right,mid+1,hi,i,j,carry+tree[node].p);

    return p1+p2;
}

void prop(ll p,ll node,ll a0,ll a1,ll a2)
{
        if(p==0){
            tree[node].zero=a0;
            tree[node].one=a1;
            tree[node].two=a2;
        }
        else if(p==1){
            tree[node].zero=a2;
            tree[node].one=a0;
            tree[node].two=a1;
        }
        else if(p==2){
            tree[node].zero=a1;
            tree[node].one=a2;
            tree[node].two=a0;
        }
}




void update(int node,int lo,int hi,int i,int j)
{

    if(hi<i||lo>j)return ;
    if(lo>=i&&hi<=j){
        tree[node].p+=1;
        tree[node].p%=3;

        ll a0=tree[node].zero;
        ll a1=tree[node].one;
        ll a2=tree[node].two;

        //prop(tree[node].p,node,a0,a1,a2);
        tree[node].zero=a2;
        tree[node].one=a0;
        tree[node].two=a1;
        return ;
    }

    int left=node<<1;
    int right=left+1;
    int mid=(lo+hi)>>1;

    update(left,lo,mid,i,j);
    update(right,mid+1,hi,i,j);

    ll a0=tree[left].zero+tree[right].zero;
    ll a1=tree[left].one+tree[right].one;
    ll a2=tree[left].two+tree[right].two;

    prop((tree[node].p)%3,node,a0,a1,a2);

}

int main()
{
    int n,q;
    sc("%d%d",&n,&q);
    createTree(1,1,n);
    for(int i=1;i<=q;i++){
        int type,a,b;
        sc("%d%d%d",&type,&a,&b);
        a++;b++;
        if(type){//query
            ll res=query(1,1,n,a,b,0);
            pf("%lld\n",res);
        }
        else if(!type){
            update(1,1,n,a,b);
        }
    }
}

/**
1. prothom a prottek node a koyta 0,1,2 ache set kore debo.

2. update ar somoy left & right node a koyta 0,1,2 ache set kore upore uthar somoy
parent node a dekhte hobe oi parent node a  propaget value koto sei propaget value onuzayi
prop() dia parent node a 0,1,2 update kore debo...

3. query korar somoy zei zei  range ar node gulo fully amar query range ar vitor thakbe
sei node ar kache ase agei tar uporer node gulor propagate value jog kore asbo..carry variable dia

arpor carry%3 joto hoy toto onuzayi oi node theke 0 naki 1 naki 2 ar value return kora lagbe seta kore debo.
**/
