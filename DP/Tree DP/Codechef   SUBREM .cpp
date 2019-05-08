/**OOO**/
#include<bits/stdc++.h>
/**problem link : https://www.codechef.com/problems/SUBREM **/
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
#define LL                      long long int

LL t,T,n,N,x,X,u,v,A[100005],totSum=0;
vector<LL>EDGE[100005];
struct info{
        LL sum,f;
}tree[100005];
bool visit[100005];

void dfs1(LL u)
{
        if(visit[u] == 1)return;
        visit[u] = 1;

        for(LL i = 0; i<EDGE[u].size(); i++){
                LL v = EDGE[u][i];
                if(visit[v] == 0){
                        dfs1(v);
                        tree[u].sum += tree[v].sum;
                }

        }
        tree[u].sum = max(tree[u].sum,-X);

}

int main()
{

        scanf("%lld",&T);
        while(T--){
                mems(visit,0);
                totSum= 0 ;

                sc("%lld%lld",&N,&X);
                for(LL i =1 ;i<=N; i++){
                        sc("%lld",&A[i]);
                        tree[i].sum = A[i];
                }
                for(LL i =1 ;i<=N-1;i++){
                        sc("%lld%lld",&u,&v);
                        EDGE[u].pb(v);
                        EDGE[v].pb(u);

                }
                dfs1(1);

                cout<<tree[1].sum<<endl;

                for(int i =1 ;i<=100000;i++)
                        EDGE[i].clear();
        }


//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}



