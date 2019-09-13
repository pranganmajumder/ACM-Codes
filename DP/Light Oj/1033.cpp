/**OOO**/
#include<bits/stdc++.h>
#define pb push_back
#define mems(arr,Val)       memset(arr,Val,sizeof(arr))
using namespace std;

int dp[1005][1005];
int visit[1005][1005];
string st1,st2;
int len1,len2;

int LCS(int i,int j)
{
    if(i==len1||j==len2)return 0;

    if(visit[i][j]==1)return dp[i][j];

    int ans;
    if(st1[i]==st2[j]){
        ans=1+LCS(i+1,j+1);
    }
    else{
        int p1=LCS(i+1,j);
        int p2=LCS(i,j+1);
        ans= max(p1,p2);
    }
    visit[i][j]=1;
    return dp[i][j]=ans;
}


int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        mems(visit,0);
        mems(dp,0);
        cin>>st1;
        len1 = (int)st1.size();
        len2 = len1;
        st2 = st1;
        reverse(st2.begin(),st2.end());
        int temp = LCS(0,0);
        printf("Case %d: %d\n",t,len1 - temp);
    }
    return 0;
}

