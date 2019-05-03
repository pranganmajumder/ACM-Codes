/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;


#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pb                      push_back
#define LL                      long long int
#define MAXsize                 50005

/****************************************************************************************************************************/
int t,T;
int Y[MAXsize],X[MAXsize],N,W;
int mov;


void solve()
{
        mov = 0;
        for(int i =1 ;i<=N;){

               int val = Y[i] + W;

               while(Y[i] <= val && i<= N){
                        i++;
               }
                mov ++ ;
        }
}

int main()
{
        //freopen("A1.in","r",stdin);
        //freopen("A1.out","w",stdout);

        scanf("%d",&T);
        for(t = 1 ;t<=T ;t++){

                scanf("%d%d",&N,&W);

                for(int n = 1 ;n<=N ; n++){

                        scanf("%d%d",&X[n],&Y[n]);
                }
                sort(Y+1,Y+N+1);
                solve();
                printf("Case %d: %d\n",t,mov);

        }

}
