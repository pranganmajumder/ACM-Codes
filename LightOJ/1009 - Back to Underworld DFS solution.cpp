/**OOO**/
/**author : Prangan Majumder **/
#include<bits/stdc++.h>
using namespace std;
#define ll                      long long
#define ull                     unsigned long long
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<int,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second

#define pf                      printf
#define sc                      scanf
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define arraysize(arr)          sizeof(arr)/sizeof(arr[0])

vector<int>EDGE[20005];
int visit[20005];
bool flag[20005];
int color[20005];
int vampire=0;
int lykane=0;


void addEDGE(int x,int y){
    EDGE[x].pb(y);
    EDGE[y].pb(x);
}
void execute(int u,int v){
    addEDGE(u,v);
    flag[u]=1;
    flag[v]=1;
}
void refresh()
{
    mems(flag,0);
    mems(visit,0);
    mems(color,0);
    for(int i=1;i<20005;i++)
        EDGE[i].clear();
    vampire=lykane=0;
}




void DFS(int father)
{
    if(visit[father]==1) return;
    visit[father] = 1;

    for(int i=0; i < EDGE[father].size(); i++){
        int child=EDGE[father][i];
        if(visit[child]==0){
            if(color[father]==2){
                color[child]=1;lykane++;//colored as lykane
            }
            else if(color[father]==1){
                color[child]=2;vampire++;//colored as vampire
            }
        }
        DFS(child);
    }
}

int main()
{
    int n,t,i,j,u,v,cas=1;
sc("%d",&t);
while(t--){
    sc("%d",&n);
    for(i=1;i<=n;i++){
        sc("%d%d",&u,&v);
        execute(u,v);
    }

    ll res=0;
    for(i=1;i<=20005;i++){
        if(visit[i]==0&&flag[i]==1){
            color[i]=2;//colored as vampire
            vampire++;
            DFS(i);
            res+=max(vampire,lykane);
        }
        vampire=lykane=0;
    }

    pf("Case %d: %lld\n",cas++,res);
    refresh();
}
return 0;
}



