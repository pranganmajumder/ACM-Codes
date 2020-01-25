#include<bits/stdc++.h>
#define SIZE    100005
typedef long long int ll ;

using namespace std ;

vector<vector<ll>>graph(SIZE) ;
bool vis[SIZE] ;
void initVis(ll x) ;
void initGraph(ll x) ;

ll bfs(ll s)
{
    queue<ll>Q ; Q.push(s) ; ll totNode = 1 ; vis[s] = 1 ;

    while(!Q.empty()){
        ll u = Q.front() ;
        Q.pop() ;
        for(ll i = 0 ; i<graph[u].size() ; i++){
            ll v = graph[u][i] ;
            if(vis[v] == 0){
                totNode++ ;  vis[v] = 1 ; Q.push(v) ;
            }
        }
    }
    return totNode ;
}



int32_t main()
{
    ll q , n , m , c_lib , c_road ;
    cin >> q ;
    while(q--)
    {
        cin >> n >> m >> c_lib >> c_road ;
        initVis(n) ;
        initGraph(n) ;

        for(ll i = 0 ; i<m ; i++){
            ll u , v ;
            cin >> u >> v ;
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }

        ll totCost = 0 ;
        for(ll i = 1 ; i<=n ; i++){
            if(vis[i] == 0){
                ll res = bfs(i) ;
                totCost+=((res-1) * c_road) + c_lib ;
            }
        }
        cout << min(n*c_lib , totCost) << endl ;
    }
}


void initVis(ll n){
    for(ll i = 0 ; i<=n; i++)vis[i] = 0 ;
}

void initGraph(ll n){
    for(ll i = 0 ; i<=n ; i++)graph[i].clear() ;
}
