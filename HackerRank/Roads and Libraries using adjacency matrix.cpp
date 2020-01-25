/** if n is smaller then this solution would work **/

#include<bits/stdc++.h>
#define SIZE    1000
typedef long long int ll ;

using namespace std ;

ll graph[SIZE][SIZE] ;
bool vis[SIZE] ;
void initVis(ll x) ;
void initGraph(ll x) ;

ll Q[SIZE] , head , tail ;

void initQueue(){
    head = tail = 0 ;
}

void push(ll x){
    Q[tail++] = x ;
}

ll isEmpty(){
    return (head == tail) ;
}

ll Front(){
    return Q[head] ;
}

void pop(){
    head++ ;
}

ll bfs(ll s , ll n )
{
    initQueue() ;
    push(s) ;
    vis[s] = 1 ;
    ll totNode = 1 ;

    while(!isEmpty()){
        int u = Front() ;
        pop() ;
        for(int i = 1 ; i<=n ; i++){
            if(graph[u][i] && vis[i] == 0){
                vis[i] = 1 , totNode++ , push(i) ;
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
            graph[u][v] = 1 ;
            graph[v][u] = 1 ;
        }

        ll totCost = 0 ;
        for(ll i = 1 ; i<=n ; i++){
            if(vis[i] == 0){
                ll res = bfs(i , n) ;
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
    for(ll i = 0 ; i<=n ; i++){
        for(ll j = 0 ; j<=n ; j++)graph[i][j] = 0 ;
    }
}
