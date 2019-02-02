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

int c,r;
string st,z,u,v;
map<string,int>mmap;
int p[5005];
int freq[5005];

int parentFind(int x){
    if(p[x]==x)return x;
    return p[x]=parentFind(p[x]);
}
void Union(int a,int b)
{
    p[parentFind(b)]=parentFind(a);
}

int main()
{
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

    while(cin>>c>>r&&c!=0){
        getchar();//age integer input && pore getline() tai getchar() deya lagbe
        for(int i=1;i<=c;i++){
            getline(cin,st);
            mmap[st]=i;
            p[i]=i;//by default parent set kore dao
        }
        set<int,greater<int> >mset;//set a descending order a sort hobe
        set<int,greater<int> >::iterator it;

        for(int i=1;i<=r;i++){
            cin>>u>>v;
            int a=parentFind(mmap[u]);
            int b=parentFind(mmap[v]);
            if(a!=b){
                Union(a,b);
            }
        }
        for(int i=1;i<=c;i++){
            freq[parentFind(i)]++;//ith child ar  parent ar koyta child ache count korbe
        }
        for(int i=1;i<=c;i++)
            mset.insert(freq[i]);
        it=mset.begin();//je parent ar maximum child ache seta print korbe
        printf("%d\n",*it);

        mems(p,0);
        mems(freq,0);

    }



//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
return 0;
}




