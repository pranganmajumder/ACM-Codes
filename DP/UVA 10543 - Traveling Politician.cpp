/** without stl  https://paste.ubuntu.com/p/6vTrmgqJN7/     **/

#include<bits/stdc++.h>
using namespace std ;


vector<int>graph[55] ;

int n , m , k , dp[55][55] , mn ;
void initDp() ;

int fun(int node , int present )
{
    if(node == n-1 ){
        if(k<= present && present <=20){
           mn = min(mn , present) ;
            return dp[node][present] = present ;
        }
        return dp[node][present] = 999999 ;
    }

    if(dp[node][present] != -1 )return dp[node][present] ;

    int res = 999999 ;
    for(int i = 0 ; i < graph[node].size() ; i++){
        int v = graph[node][i] ;
        res = min(res , fun(v , present + 1 ) ) ;
    }
    return dp[node][present]  = res ;
}

int main()
{
    while (cin >> n >> m >> k)
    {
        if(n == 0 && m==0 && k == 0)break ;
        initDp() ;


        for(int i = 0 ; i<m ; i++){
            int u , v ; cin >> u >> v ;
            graph[u].push_back(v) ;
        }
        int res = fun(0 , 1 ) ;
        if(res != 999999)cout << mn << endl ;
        else cout << "LOSER" << endl ;
    }

}


void initDp()
{
    for(int i = 0 ; i<=50 ; i++){
        for(int j = 0 ; j<=50 ; j++)dp[i][j] = -1 ;
        graph[i].clear() ;
    }
    mn = 10000000 ;
}
