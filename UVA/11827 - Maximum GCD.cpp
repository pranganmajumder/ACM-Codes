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


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }


int n;
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    sc("%d",&q);
    getchar();
    while(q--){
        string st;
        getline(cin,st);
        vector<int>v,mx;
        stringstream ss(st);
        while(ss>>n)v.pb(n);
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++)mx.pb(gcd(v[i],v[j]));
        }
        sort(mx.begin(),mx.end());
        printf("%d\n",mx.back());
    }
return 0;
}


