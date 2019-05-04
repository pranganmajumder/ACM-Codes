/**OOO**/
/**problem link : https://codeforces.com/contest/1084/problem/D  **/
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
#define DEBUG                   cout<<"IM here"<<endl
//// Ordered set
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
////orderset<int> s ; //orderset<int>::iterator it ;
////orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
////cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
////cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

//struct info
//{
//
//    ll w,indx;
//    info(ll a,ll b){
//        w=a;
//        indx=b;
//    }
//    bool operator<(const info& p)const{
//        if(w==p.w){
//            return indx<p.indx;
//        }
//        else{
//            return w>p.w;
//        }
//    }
//};


struct node{
    ll x,c;
    ll m1=0,m2=0;
    node(){};
    node(ll a,ll b){
        x=a;
        c=b;
    }
};

ll n,edge;
vector<node>EDGE[300005];
ll w[300005];
ll tree[300005];
ll visit[300005];
ll source=1;

ll secondMax[300005];

void input()
{   ll i,u,v,c;
    scanf("%lld",&n);
    edge=n-1;
    for(i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(i=0;i<edge;i++){
        scanf("%lld%lld%lld",&u,&v,&c);
        EDGE[u].pb(node(v,c));
        EDGE[v].pb(node(u,c));
    }
}


ll mxxx1[300005];
ll mxxx2[300005];

void dfs(node s)
{
    ll u=s.x;
    if(visit[u]==1)return ;
    visit[u]=1;
    if(EDGE[u].size()==1&&u!=1){
        tree[u]=w[u];
        mxxx1[u]=0;
        mxxx2[u]=0;
        return ;
    }

    node U = s;
    for(ll i=0;i<EDGE[u].size();i++){
        node v=EDGE[u][i];
        dfs(v);
        U.m2=max((ll)U.m2,max((ll)0,min((ll)U.m1,-v.c+tree[v.x])));
        U.m1=max((ll)U.m1,-v.c+tree[v.x]);
    }
    if(U.m1>=0)tree[u]=U.m1+w[u];
    else tree[u]=w[u];
    mxxx1[u]=U.m1;
    mxxx2[u]=U.m2;

    return ;
}

int main()
{

    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

    ll i,u,v,c;
    input();
    dfs(node(1,w[1]));

    vector<ll>vec;
    for(ll i=1;i<=n;i++){
        vec.pb(mxxx1[i]+w[i]+mxxx2[i]);
    }

    sort(vec.begin(),vec.end());
    printf("%lld\n",vec.back());

return 0;
}
