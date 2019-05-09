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

int t,T,i,n;
double res;

int main()
{
sc("%d",&T);
for(t = 1;t<=T;t++){

       res = 1;
       sc("%d",&n);
       for( i =n ;i>=1;i--){
                double d = (double)i/n;
                res = res*d;
                if(res<=0.5)break;
       }
       printf("Case %d: %d\n",t,n-i);
}


return 0;
}
//reference : https://medium.com/i-math/the-birthday-problem-307f31a9ac6f



