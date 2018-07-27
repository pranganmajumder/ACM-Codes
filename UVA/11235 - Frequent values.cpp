
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

#define pf                      printf
#define sc                      scanf
#define inf                     -100000000
#define mx                      100005
#define DBG                     pf("i am here\n")
#define mx                      100005

ll arr[mx],freqArr[mx],tree[mx*3];


void createTree(int node,int lo,int hi)
{
    if(lo==hi){
        tree[node]=freqArr[lo];
        return ;
    }
    int left=node*2;
    int right=left+1;
    int mid=(lo+hi)/2;

    createTree(left,lo,mid);
    createTree(right,mid+1,hi);
    tree[node]=max(tree[left],tree[right]);
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

    return max(p1,p2);
}



int main()
{

    //freopen("A1.in","r",stdin);
    //freopen("single.in","r",stdin);
    //freopen("A1.out","w",stdout);
    ll n,i,j,S,E,q;
while(sc("%lld",&n)){
    if(n==0)break;
    else sc("%lld",&q);

    mems(arr,0);
    mems(freqArr,0);
    map<ll,ll>mymap;
    for(i=1;i<=n;i++){
        sc("%lld",&arr[i]);
        mymap[arr[i]]++;
    }

    pair<ll,pair<ll,ll>>pIii[n+5];
    for(i=1;i<=n;i++)//update main array with their frequency;
        freqArr[i]=mymap[arr[i]];
//
//    for(i=1;i<=n;i++)
//        cout<<arr[i]<<" ";
//    cout<<endl;


    for(i=1;i<=n;i=j){
        S=i;//S for starting && E for Ending
        for(j=i;;j++){
            if(arr[i]!=arr[j]){E=j-1;break;}
            else if(arr[i]==arr[j]&&j==n){E=j;break;}
        }
        for(j=S;j<=E;j++)
            pIii[j]=mk(arr[j],mk(S,E));
    }

//    for(i=1;i<=n;i++)
//        cout<<pIii[i].ff<<"  "<<pIii[i].ss.ff<<"   "<<pIii[i].ss.ss<<endl;
//

        ll a,b;
        createTree(1,1,n);
        while(q--){
            sc("%lld%lld",&i,&j);
            int lo=pIii[i].ss.ss;
            int hi=pIii[j].ss.ff;
            if(i==j){
                pf("1\n");
                continue;
            }
            else if(pIii[i].ss.ff==pIii[j].ss.ff&&pIii[i].ss.ss==pIii[j].ss.ss){
                pf("%lld\n",j-i+1);
                continue;
            }
            a=lo-i+1;
            b=j-hi+1;
            ll res=0;
            if(lo+1<=hi-1){
                //createTree(1,lo+1,hi-1);
                res=query(1,1,n,lo+1,hi-1);
            }
            //cout<<max(a,max(b,res))<<endl;
            pf("%lld\n",max(a,max(b,res)));
        }
}

return 0;
}
