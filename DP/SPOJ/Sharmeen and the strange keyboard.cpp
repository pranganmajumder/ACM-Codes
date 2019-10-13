/**OOO
problem link : https://www.spoj.com/problems/MOZSATSK/

mozahid solution : https://paste.ubuntu.com/p/6qzcQ5W8qs/
graph solution   : https://paste.ubuntu.com/p/SxjCf5KxKC/



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
//#define Mod                     1000000007
#define hiii                    1e9//1000000000
#define looo                   -1e9//-1000000000
#define NMAX                    100005

string s;
int len , dp[NMAX][5];

bool ok(int pos)
{
    if(0<=pos && pos<len)return 1;
    return 0;
}

int dif(char ch1 , char ch2)
{
    int a = ch1 - 48 , b = ch2 - 48;
    return abs(a-b);
}

int fun1(int pos , int jump)
{
    if(pos == len-1 )return 0;
    if(dp[pos][jump] != -1 )return dp[pos][jump];

    int r = NMAX ;
    if(s[pos] != '0' && s[pos]!='9'){
        if( ok(pos-1) && jump == 2 && dif( s[pos] , s[pos-1] ) <= 1)
            r = min(r ,  fun1(pos-1 , 0) );
        if( ok(pos+1) && dif( s[pos] , s[pos+1] ) <= 1 )
             r = min(r ,  fun1(pos+1 , 1) );
        if( ok(pos+2) && dif( s[pos] , s[pos+2] ) <= 1 )
             r = min(r ,  fun1(pos+2 , 2) );
    }
    else{
        if( ok(pos-1) && jump == 2 && ( dif( s[pos] , s[pos-1] ) <= 1 || dif( s[pos] , s[pos-1] ) == 9) )
             r = min(r ,  fun1(pos-1 , 0) );
        if( ok(pos+1)  && ( dif( s[pos] , s[pos+1] ) <= 1 || dif( s[pos] , s[pos+1] ) == 9) )
              r = min(r ,  fun1(pos+1 , 1) );
        if( ok(pos+2)  && ( dif( s[pos] , s[pos+2] ) <= 1 || dif( s[pos] , s[pos+2] ) == 9) )
            r = min(r ,  fun1(pos+2 , 2) );
    }

    return dp[pos][jump] = 1 + r ; //min(r , min(r1 , r2) );

}

int main()
{

    cin >> s ;
    len = s.size();

    memset(dp , -1 , sizeof(dp) );

    int res = fun1(0 , 0 );
    if(res>=NMAX)cout<<"no"<<endl;
    else {
        cout<<"yes\n"<<res<<'\n';
    }


//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}
