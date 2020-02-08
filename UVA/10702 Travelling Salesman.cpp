#include<iostream>
#define    NMAX      110 
typedef long long int LL ; 


using namespace std ;

LL C , N , S , E , T , dp[NMAX][1010] , last[NMAX] , profit[NMAX][NMAX] ; 
void initDp( ) ;


LL fun(LL u , LL d)
{
    if(d == 0 )return 0 ;
    if(dp[u][d] != -1 )return dp[u][d] ;

    LL mx = 0 ;
    if(d == 1){
        for(int i = 1 ; i<=N ; i++)
            if(last[i])mx = max(mx , profit[u][i]) ;
    }
    else{
        for(int i = 1 ; i<=N ; i++)
            mx = max(mx , profit[u][i] + fun(i , d-1)) ;
    }
    return dp[u][d] = mx ;
}

int main()
{	//freopen("A1.in","r",stdin) ;
	//freopen("A1.out","w",stdout) ;


    while(cin >> C >> S >> E >> T){
        if(C == 0 && S == 0 && E == 0 && T==0 )break ;
		initDp() ;

        for(int i = 1 ; i<=C ; i++){
            for(int j = 1 ; j<=C ; j++)
                cin >> profit[i][j] ; 
        }

        for(int i = 1 ; i<=E ; i++){
            int x ; cin >> x ; 
            last[x] = 1 ; 
        }

        N = C ;
        cout << fun(S , T) << endl ;
    }

}


void initDp()
{
    for(int i = 0 ; i <=100 ; i++){
        last[i] = 0 ;
        for(int j = 0 ; j<=1000 ; j++){
            dp[i][j] = -1 ;
        }
    }
}
