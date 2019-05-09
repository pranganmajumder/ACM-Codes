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
#define Ppll                    pair<ll,pair<ll,ll> >
int t,T,n,x[105];
int totNeg,Sum;

int main()
{
        sc("%d",&T);

        for(int t = 1 ;t<=T ;t++){
                totNeg = Sum = 0;
                sc("%d",&n);

                for(int i =1 ;i<=n;i++){
                        sc("%d",&x[i]);
                        Sum += abs(x[i]);
                        if(x[i]<0)totNeg++;
                }
                printf("Case %d: ",t);

                int dd = n - totNeg;
                int gc = __gcd(Sum,dd);

                int a = Sum / gc;
                int b = dd / gc;

                if(b==0)printf("inf\n");
                else printf("%d/%d\n",a,b);
        }
return 0;
}




