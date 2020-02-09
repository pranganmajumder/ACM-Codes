/** without stl  https://paste.ubuntu.com/p/3tTnwZ8hsx/    **/


#include<bits/stdc++.h>
typedef long long int LL ;
#define NMAX       110
#define pb          push_back

using namespace std ;

vector<int>graph[NMAX] ;
int C , L , S , E , D , dp[NMAX][220];


void initDp() ;

int fun(int u , int d)
{
    if(d == 0 ){
        if(u == E)return dp[u][d] =  1 ;
        return dp[u][d] = 0 ;
    }
    if(dp[u][d]  != -1 )return dp[u][d] ;

    int res  = 0 ; 
    for(int i = 0 ; i<graph[u].size() ; i++){
        int v = graph[u][i] ;
        res += fun(v , d-1) ;
    }
    return dp[u][d] = min(res , 1 )  ; // amar dorkar 1 return kora tai .. sudhu res return korle int overflow 
}

int main()
{

    //freopen("A1.in" , "r" , stdin) ;
    //freopen("A1.out" , "w" , stdout) ;


        while (cin >> C >> L )
        {   if(C == 0 && L == 0 )break ;
            initDp() ;
            for(int i = 1 ; i<=L ; i++){
                int u , v ;
                cin >> u >> v ;
                graph[u].pb(v) ;
                graph[v].pb(u) ;
            }
            cin >> S >> E >> D ;
            if(fun(S , D))cout << "Yes, Teobaldo can travel." << endl ;
            else cout << "No, Teobaldo can not travel." << endl ;
        }
        
        
}




void initDp()
{
    for(int i = 0 ; i<NMAX ; i++){
        for(int  j= 0 ; j<220 ; j++)dp[i][j] = -1 ;
        graph[i].clear() ;
    }
}

