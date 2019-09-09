/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;

#define LL                      ll
#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pii                     pair<int,int>
#define mk                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define PI                      acos(-1.0)
#define inputFile               freopen("desk.in","r",stdin);
#define outputFile              freopen("desk.out","w",stdout);

#define pf                      printf
#define sc                      scanf
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define nxam                    200005
#define debug(x)                cout<<"hey  "<<x<<endl;
#define RUN_CASE(t,T)           for(int t=1;t<=T;t++)
#define GREY                    1
#define BLACK                   2






char s1[100],s2[100];
int color[10005];
bool visited[10005];
vector<int>graph[10005];

int cycle = 0;
void dfs(int u)
{
    color[u] = GREY;
    for(int i=0;i<graph[u].size();i++){
        if(color[graph[u][i]] == GREY){//contains cycle
            cycle = 1;
            return ;
        }
        if(color[graph[u][i]]==0)//white
            dfs(graph[u][i]);
    }
    color[u] = 2;//make black
}


int main()
{

    int t,T;
    sc("%d",&T);

    RUN_CASE(t,T){
        map<string,int>mmap;
        cycle= 0;
        int M,m,id=1;

        scanf("%d",&M);

        for(m=1;m<=M;m++){
            sc("%s%s",s1,s2);
            if(!mmap[s1])mmap[s1]=id++;
            if(!mmap[s2])mmap[s2]=id++;
            graph[mmap[s1]].pb(mmap[s2]);
        }
        for(int i=1;i<id;i++){
            if(color[i]==0)dfs(i);
        }
        if(cycle)pf("Case %d: No\n",t);
        else pf("Case %d: Yes\n",t);


        for(int i=0;i<=10000;i++){//refresh
            graph[i].clear();
            visited[i]= 0;
            color[i] = 0;
        }
    }
return 0;
}


