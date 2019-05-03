/**OOO**/
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long ull;
using namespace std;


#define mems(arr,VAL)           memset(arr,VAL,sizeof(arr))
#define pb                      push_back
#define LL                      long long int
#define MAXsize                 105

/****************************************************************************************************************************/
int t,T,n,N;
int arr[MAXsize];
int tot;

void solve()
{
        tot = 0;
        for(int i = 1 ;i<=N;i++){

                while(arr[i] != i){
                        swap(arr[arr[i]],arr[i]);
                        tot++;
                }
        }
}

int main()
{
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

        scanf("%d",&T);
        for(t = 1 ;t<=T ;t++){

                scanf("%d",&N);
                for(n = 1 ;n<=N; n++){
                        scanf("%d",&arr[n]);
                }
                solve();
                printf("Case %d: %d\n",t,tot);
        }


}
