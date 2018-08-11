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
    for(int i=1;i<20005;i++)
        EDGE[i].clear();
}

int bfs(int s)
{
    int vampire=0,lykan=0;

    queue<int>Q;
    Q.push(s);
    visit[s]=2;//coloured as vampire
    vampire++;

    while(!Q.empty()){
        int father=Q.front();
        Q.pop();
        for(int i=0;i<EDGE[father].size();i++){
            int child=EDGE[father][i];
            if(visit[child]==0){
                if(visit[father]==1){visit[child]=2;vampire++;}//colored as vampire
                else if(visit[father]==2){visit[child]=1;lykan++;}//colored as lykane
                Q.push(child);
            }
        }
    }
    return max(vampire,lykan);
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
            res+=bfs(i);
        }
    }

    pf("Case %d: %lld\n",cas++,res);
    refresh();
}
return 0;
}
