// using stl  //

#include<iostream>
#include<bits/stdc++.h>
#define NMAX       15
typedef long long int LL ;
using namespace std ;

int Set(int N , int pos){
    return N = N | (1<<pos) ;
}

bool Check(int N , int pos){
    return (bool)(N&(1<<pos)) ;
}

int Reset(int N , int pos){
    return N = N & ~(1<<pos) ;
}


LL n , query , greed[NMAX][NMAX] , dp[1<<15] ;

LL  fun(int mask)
{
    if(mask == (1<<n)-1)return 0 ;
    if(dp[mask] != -1)return dp[mask] ;

    LL price , ans = 1<< 28 ;
    for(int i = 0 ; i<n ; i++){
        if(Check(mask , i ) == 0 ) { // if ith not buy , akn i kinbo
            price = greed[i][i] ; // price of i
            for(int j = 0 ; j<n ; j++){ // baki sob element dekho , kena hoyeche kina
                if(Check(mask , j) == 1){ // ager kena thakle , i ar original price ar sathe , j ar surcharge add koro
                    price+=greed[i][j] ; // add surcharges greed[i][j]
                }
            }
            ans = min(ans , price + fun(Set(mask , i))) ;
        }
    }
    return dp[mask] = ans ;
}

int main()
{   scanf("%d",&query) ;
    for(int t = 1 ; t<=query ; t++){
        scanf("%d",&n) ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++)
                scanf("%d",&greed[i][j]) ;
        }
        memset(dp , -1 , sizeof dp) ;
        printf("Case %d: %lld\n",t , fun(0)) ;
    }

}
