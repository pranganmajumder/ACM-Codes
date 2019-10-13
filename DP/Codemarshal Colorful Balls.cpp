/**OOO

another recursive :
https://paste.ubuntu.com/p/zrvYxvrJj8/
https://paste.ubuntu.com/p/h7gKRRWPkX/
https://paste.ubuntu.com/p/WxT4XHWWMw/


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
//WRGB = 0123

void refresh();

char s[NMAX];
int len , T ;

int dp[NMAX][6];//position state , color state . color 3 ta hote parbe maximum

int fun(int pos , int c ) // current position , ager position a kon color chilo
{
    if(s[pos] == 'R' && c == 0 )return 0; // zodi current position a R thake & ager color oo R(0) hoy tahole 0 return kore dibe
    if(s[pos] == 'G' && c == 1 )return 0; // zodi current position a R thake & ager color oo R(1) hoy tahole 0 return kore dibe
    if(s[pos] == 'B' && c == 2 )return 0; // zodi current position a R thake & ager color oo R(2) hoy tahole 0 return kore dibe
    if(pos == len )return 1;
    if(dp[pos][c] != -1)return dp[pos][c];

    int tot = 0 ;
    if( s[pos] == 'W' ){//zodi current postion a W thake tahole R(0), G(1) , B(2) tintai bosabo zabe .
            if(c!=0)tot+= fun(pos+1 , 0)  % Mod ; // c!=0 means ager positon ar color zodi R(0) na hoy tahole se current pos a R bosabe means next state  a R(0) niya zabe
            if(c!=1)tot+= fun(pos+1 , 1 ) % Mod ; // c!=1 means ager positon ar color zodi G(1) na hoy tahole se current pos a G bosabe means next state  a G(1) niya zabe
            if(c!=2)tot+= fun(pos+1 , 2 ) % Mod ; // c!=2 means ager positon ar color zodi B(2) na hoy tahole se current pos a  B bosabe means next state a B(2) niya zabe
    }
    else{
        if(s[pos] == 'R' && c!=0 )//current pos zodi R hoy & ager positon ar color zodi R(0) na hoy tahole current position a zei R(0) ache seta bosaya next pos+1 a zete parbe
            tot+= fun(pos+1 , 0) % Mod ;

        else if(s[pos] == 'G' && c!=1)
            tot+= fun(pos+1 , 1) % Mod ;

        else if(s[pos] == 'B' && c!=2)
            tot+= fun(pos+1 , 2) % Mod ;
    }
    return dp[pos][c] = tot % Mod ;
}

int main()
{
    sc("%d",&T);
    for(int t = 1 ; t<=T ; t++){

            sc("%s",s);
            len = strlen(s);
            refresh();

            int tot = 0;
            if(s[0]=='W'){//JODI FIRST POSITION A W THAKE
                tot = ( tot + fun(1,0) ) % Mod ; //first position a R(0) diya next postion (1) a zao
                refresh();

                tot = (tot + fun(1,1) ) % Mod ; //first position a G(1) diya next postion (1) a zao
                refresh();

                tot = (tot + fun(1,2) ) % Mod ; //first position a B(2) diya next postion (1) a zao
                refresh();
            }
            else{
                if(s[0] == 'R')tot+=fun(1,0);//first postion R hole next postion a cole zao , & zabar somoy R(0) niya zao
                if(s[0] == 'G')tot+=fun(1,1);
                if(s[0] == 'B')tot+=fun(1,2);
            }
            pf("Case %d: %d\n",t,tot);

    }

//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}


void refresh()
{
    for(int i=0;i<=len;i++){
        for(int j=0;j<=4;j++){
            dp[i][j]=-1;
        }
    }
}


