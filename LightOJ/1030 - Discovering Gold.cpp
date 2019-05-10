/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;


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

int t,T,n;
double E[10000],G[10000];
double res = 0.0;

int main()
{
        sc("%d",&T);
        for(t = 1; t<=T ;t++){
                sc("%d",&n);
                for(int i =1 ;i<=n;i++)sc("%lf",&G[i]);

                E[n] = 0.0;

                for(int i = n-1 ;i> n-6;i--){

                        double tot = 0;
                        for(int j = i+1; j<=n; j++){
                                tot+= G[j] + E[j];
                        }
                        E[i] = tot/(n-i);
                }

                for(int i =n-6;i>=1;i--){

                        double tot = 0;
                        for(int j = i+1; j<=i+6; j++){
                                tot+= G[j] + E[j];
                        }
                        E[i] = tot/6;
                }
                res = G[1] + E[1];
                printf("Case %d: %.6lf\n",t,res);

        }


return 0;
}


