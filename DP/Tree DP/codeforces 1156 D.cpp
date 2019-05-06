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


/*****************************************************====>>>>START FROM HERE<<<<<=======******************************************/
ll n,u,v,c;

struct node{
        ll x,cost;// x= (node) c= (cost)
        node(){};
        node(ll a , ll b){
                x = a ;
                cost = b;
        }
};

struct info{
        ll on,ze;

}tree[200005];


vector<node>EDGE[200005];
vector<node>onlyOne[200005],onlyZero[200005];
ll visit[200005];

void dfs1(ll u)//nice theke uporer dike uthbo // age child update then parent update
{
        if( visit[u] == 1){//if leaf node or visited
                return ;
        }
        visit[u] = 1;

        for(ll i=0;i<EDGE[u].size();i++){
                node v = EDGE[u][i];
                if(visit[v.x]==0){
                        dfs1(v.x);/**akbare niche cole zabe , pore uthar somoy nicer dui line dia update hote thakbe**/
                        if(v.cost == 0)tree[u].ze += tree[v.x].ze + 1;
                        if(v.cost == 1)tree[u].on += tree[v.x].on + 1;
                }
        }
}



void dfs2(ll u)//age parent update then child update
{
        if(visit[u] == 1)return ;
        visit[u] = 1;

        for(int i =0;i<EDGE[u].size();i++){
                node v = EDGE[u][i];
                if(visit[v.x] == 0){

                        if(v.cost == 0)tree[v.x].ze = tree[u].ze;
                        if(v.cost == 1)tree[v.x].on = tree[u].on;
                        dfs2(v.x);/**uporer dui line dia age update hobe, then dfs2() dia depth a  zabe**/
                }
        }
}



ll res;
void dfs3(ll u)
{
        if(visit[u] == 1)return ;
        visit[u] = 1;
        for(int i = 0;i<onlyOne[u].size();i++){
                node v = onlyOne[u][i];
                if(visit[v.x] == 0){
                        res++;
                        dfs3(v.x);
                }
        }
}


void dfs4(ll u)
{
        if(visit[u] == 1)return ;
        visit[u] = 1;
        for(int i = 0;i<onlyZero[u].size();i++){
                node v = onlyZero[u][i];
                if(visit[v.x] == 0){
                        res++;
                        dfs4(v.x);
                }
        }
}

void input()
{
        cin >> n;
        for(int i =1 ;i<=n-1 ;i++){
                cin >> u >> v >> c;
                EDGE[u].pb(node(v,c));
                EDGE[v].pb(node(u,c));

                if(c==0){
                        onlyZero[u].pb(node(v,c));
                        onlyZero[v].pb(node(u,c));
                }
                else if(c==1){
                        onlyOne[u].pb(node(v,c));
                        onlyOne[v].pb(node(u,c));
                }
        }
}



ll total;
int main()
{
        input();
        dfs1(1);
        mems(visit,0);
        dfs2(1);

        mems(visit,0);
        for(ll i=1 ;i<=n;i++){
                if(visit[i] == 0){
                        res = 1;
                        dfs3(i);
                        total += (res * (res-1));
                }
        }

        mems(visit,0);
        for(ll i=1 ;i<=n;i++){
                if(visit[i] == 0){
                        res = 1;
                        dfs4(i);
                        total += (res * (res-1));
                }
        }

        //cout<<"total  =  "<<total<<endl;

        for(int i =1 ;i<=n;i++){
                total += (tree[i].on * tree[i].ze);
        }
        cout<<total<<endl;



return 0;
}




//
//for(ll i =1 ;i<=n ;i++)
//{
//        cout<<"i = "<<i<<"      "<<tree[i].ze<<"         "<<tree[i].on<<endl;
//}
//cout<<endl;
