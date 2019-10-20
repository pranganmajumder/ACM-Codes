/**OOO

**/
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

#define pf                      printf
#define sc                      scanf
#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define NMAX                    100005


LL m , n , T  ;
LL S[10] , a[10]  , dp[10][10][5] ; // [num][digit][jump]

bool ok(LL num )
{
    if(0<= num && num<=9 && S[num])return true;
    return false ;
}

LL fun(LL num , LL digit , LL jump )
{
    if(digit == n )return 1 ;
    if(dp[num][digit][jump] != -1 ) return dp[num][digit][jump] ;

    LL r = 0 ;
    for(int i = -2 ; i<=2 ; i++){
        if( ok(num+i) )r+=fun(num+i , digit+1 , i ) ;
    }
    return dp[num][digit][jump] = r ;
}


int main()
{  scanf("%lld", &T);
    for(LL cas = 1 ; cas<=T ; cas++){

        scanf("%lld%lld",&m, &n) ;
        for(int i = 1 ; i<=m ; i++){
            scanf("%lld" , &a[i]);
            S[a[i]]++ ;
        }

        LL tot = 0 ;
        for(int i = 1 ; i<=m ; i++){
            mems(dp , -1 ) ;
            tot+=fun(a[i] , 1 , 0 ) ;
        }
        printf("Case %lld: %lld\n" , cas, tot ) ;

        memset(S , 0 , sizeof(S) ) ;
        memset(dp, -1 , sizeof(dp)) ;
    }
}
