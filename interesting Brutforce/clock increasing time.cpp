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




int main()
{
        int h,m,s,hour,minit,second;
        cin >> h >> m >> s;
        hour = h;
        minit = m;
        second = s;

        bool f1,f2,f3;
        f1=f2=f3=0;

        while(1)
        {
                second++;
                if(second == 60)
                {
                        second = 0;
                        minit++;

                        if(minit == 60)
                        {
                                minit = 0;
                                hour++;

                                if(hour == 24)
                                {
                                        hour = 0;
                                }
                        }
                }

                if(hour ==0 && minit==0 && second==0)break;
                else
                {
                         cout<<hour<<':'<<minit<<':'<<second<<endl;
//                         string st="",th="",tm="",ts="";
//
//                         if(hour/10 == 0)
//                         {
//                                 th+='0';
//                                 th+=
//                         }
                }

        }
return 0;
}



