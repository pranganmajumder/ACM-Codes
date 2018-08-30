
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;


string month1,month2,comma1,comma2;
ll date1,date2,year1,year2,A,B,C;
bool f1,f2;
bool isLeap(ll year);
void scanner1(){cin>>month1; cin>>date1;cin>>comma1;cin>>year1;}
void scanner2(){cin>>month2;cin>>date2;cin>>comma2;cin>>year2;}



int main()
{

    string arr[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
    map<string,int>mp;
    ll t,cas=1,i;
    //freopen("A1.in","r",stdin);
    //freopen("A1.out","w",stdout);

    for(i=0;i<12;i++)
        mp[arr[i]]=i;

    cin>>t;
    while(t--){
        f1=f2=0;
        scanner1();
        scanner2();
        ll sum=0;
        f1=isLeap(year1);
        f2=isLeap(year2);
        if(f1){
            if(month1==arr[0])f1=true;
            else if(month1==arr[1]&&date1<=29)f1=true;
            else f1=false;
        }
        if(f2){
            if(month2==arr[0])f2=false;
            else if(month2==arr[1]&&date2<29)f2=false;
            else f2=true;
        }
        ll total=year2-year1;
        if(total>20){
            ll t1,t2;
            for(i=year1+1;;i++){
                if(isLeap(i)){t1=i;break;}
            }
            for(i=year2-1;;i--){
                if(isLeap(i)){t2=i;break;}
            }
            A=(t2/4)-(t1/4);
            B=(t2/100)-(t1/100);
            C=(t2/400)-(t1/400);
            sum+=(A-B+C)+1;
        }
        else{
            for(i=year1+1;i<=year2-1;i++)if(isLeap(i))sum++;
        }
        if(f1)sum++;
        if(f2)sum++;
        if(year1==year2){
            if(isLeap(year1)){
                if(mp[month1]>=2)sum=0;
                else if(mp[month2]==0)sum=0;
                else if(mp[month1]==mp[month2]&&mp[month1]==1){if(date2==29)sum=1;else sum=0;}
                else{
                    ll x=mp[month2]-mp[month1];
                    if(x==1){
                        if(mp[month2]==1){if(date2==29)sum=1;else sum=0;}
                        else if(mp[month2]==2){
                            if(mp[month1]==0)sum=1;
                            else if(mp[month1]==1){
                                if(date1<=29)sum=1;
                                else sum=0;
                            }
                        }
                    }
                    else sum=1;
                }
            }
            else sum=0;
        }
        cout<<"Case "<<cas++<<": "<<sum<<endl;
    }
return 0;
}

bool isLeap(ll year)
{
    if(year%4 == 0)
    {
        if( year%100 == 0)
        {
            if ( year%400 == 0)return true;
            else return false;
        }
        else return true;
    }
    else return false;
}
