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

int p[27];
int parentFind(int x)//x ar parent find kora jay
{
    if(p[x]==x)return x;
    return p[x]=parentFind(p[x]);
}

void Union(int a,int b)//a ar parent b ar parent ar parent hobe
{
    p[parentFind(b)]=parentFind(a);
}

int main()
{
    int t,T,i,j,total,a,b,totalsubgraph;
    string st,L;
    char blank;

    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

    scanf("%d",&T);
    getchar();
    getchar();

    for(t=1;t<=T;t++){
        getline(cin,L);//Largest Node
        total=L[0]-'A'+1;

        totalsubgraph=total;
        for(i=0;i<total;i++)p[i]=i;//by default sobar parent set kore dao

        while(getline(cin,st)){
                if(st.size()==0)break;
                a=st[0]-'A';
                b=st[1]-'A';

                int p1=parentFind(a);
                int p2=parentFind(b);

                if(p1!=p2){//jodi parent soman na hoy
                    Union(a,b);
                    totalsubgraph--;
                }

        }


        if(t!=1)printf("\n");
        printf("%d\n",totalsubgraph);
    }

//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}



