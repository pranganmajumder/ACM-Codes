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


int mod;
bool cmp(pii a,pii b)
{
    int t1=a.ff%mod;
    int t2=b.ff%mod;

    int x1=a.ss;
    int x2=b.ss;

    if(t1<t2)return true;
    else if(t1>t2)return false;

    else if(t1==t2){
        if(x1==1&&x2==0)return true;
        else if(x1==0&&x2==1)return false;
        else if(x1==1&&x2==1){
            if(a.ff>b.ff)return true;
            else if(a.ff<b.ff)return false;
            else if(a.ff==b.ff)return false;//

        }
        else if(x1==0&&x2==0){
            if(a.ff<b.ff)return true;
            else if(a.ff>b.ff)return false;
            else if(a.ff==b.ff)return false;//
        }

    }
}

int main()
{
    int n;
    while(cin>>n>>mod){
        if(n==0&&mod==0)break;


        pii arr[n+5];
        for(int i=0;i<n;i++){
            cin>>arr[i].ff;

            if(abs(arr[i].ff)%2)arr[i].ss=1;
            else arr[i].ss=0;
        }

        sort(arr,arr+n,cmp);
        printf("%d %d\n",n,mod);
        for(int i=0;i<n;i++)
            cout<<arr[i].ff<<endl;
    }
printf("0 0\n");
}

