/**OOO

problem link : https://codeforces.com/contest/1234/problem/C
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

void refresh();
int n,q;
string s[3] ;
int dp[4][200005][4];/** cell (row,col) a pechon / upor / niche 3 ta direction theke asa zay tai dir akta state **/



int fun( int row , int col , int dir )//dir(0) = soja , dir (-1) upore , dir (+1) nice
{
    if(row == 1 && col==n)return 1;
    if(row == 0 && col==n)return 0;
    if( !(0<=row && row<=1) )return 0;//zodi kokhono row exit kore

    if( dp[row][col][dir] != -1 )return dp[row][col][dir];

    int r = 0;
    if(s[row][col] == '1' || s[row][col] == '2'){/**zodi cell a 1/2 thake**/
        if(dir == 0)r+=fun(row , col+1 , 0 );/**& soja pechon theke asle samner col a cole zabe && direction same thake**/
        else r += 0; /** but jodi oi cell a niche / upore theke asle samne ar zaite parbe na tai 0 return kore dite hobe**/
    }
    else{/**zodi oi cell a 3,4,5,6 thake **/
        if(dir == 0){/**zodi soja pechon theke ase **/
            if(row == 0)/**current cell ar row uporer row hole **/
                r+=fun(row+1 , col , 1 );/** same column ar nicher row te cole zabe tai  dir (+1) niye zabe **/
            else if(row == 1)/**current cell ar row nicer ta hole**/
                r+=fun(row-1 , col , -1);/**same col ar uporer row te cole zabe tai dir(-1) niye zabe **/
        }
        else if(dir == -1 || dir == +1){/**zodi oi cell a niche / upor theke ase **/
                r+=fun(row , col+1 , 0);/**tahole  just samner column a cole cole zabe soja , since soja tai dir(0) nia zabe **/
        }
    }

    return dp[row][col][dir] = r ;
}

int main(){

cin>>q;
while(q--){

        cin >> n ;
        refresh();
        cin >> s[0] >> s[1];

        int r =  fun( 0, 0 , 0) ; /** (0,0) cell a aschi soja pechon theke tai dir (0 ) , target hocce (0,0) cell theke (1,n) cell a zabo **/
        if(r)puts("YES");
        else puts("NO");

}

return 0;
}

void refresh()
{
    for(int i =0;i<4;i++){
        for(int j = 0; j<=n ; j++){
            for(int k = 0; k<4; k++)
                dp[i][j][k] = -1;
        }
    }
}

