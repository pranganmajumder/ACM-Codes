/**OOO
//problem link : https://www.codechef.com/problems/NOPC10

problem : day of a given date
**/

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
#define LL                      long long int

int arr1[14]={31,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int num)
{
        if(num%400==0 || (num%4==0 && num%100!=0))return 1;
        return 0;
}
vector<string>vec;

int month,date,year;

int main()
{


        int mm,dd,yy;

        cin>>dd>>mm>>yy;
        date = 10;  month = 6;  year = 2019;
        vec.pb("Monday");  vec.pb("Tuesday");  vec.pb("Wednesday");  vec.pb("Thursday");  vec.pb("Friday");  vec.pb("Saturday"); vec.pb("Sunday");



    int cnt = 0;
    if(yy>year || (yy==year && mm >month) || (yy == year && mm ==month && dd > date))
    {

        while(1)
        {
                date++;

                if(date == 29 && month == 2 && isLeap(year) == 1)
                {

                }
                else if(date == 29 && month ==2 && isLeap(year) != 1)
                {
                        date = 1;
                        month++;
                }
                else if(date == 30 && month == 2 )
                {
                        date = 1;
                        month++;
                }
                else if(date == 31 && (month==4 || month ==6 || month==9 || month==11))
                {
                        date = 1;
                        month++;
                }
                else if(date == 32 && (month ==1 || month ==2 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                {
                        date = 1;
                        month++;
                        if(month==13){
                                month = 1;
                                year++;
                        }
                }

                if(date == dd && month==mm && year==yy)
                {
                        cnt++;
                        cout<<vec[cnt%7]<<endl;
                        break;
                }
                else
                {
                        //cout<<date<<' '<<month<<' '<<year<<endl;
                        cnt++;
                }
        }
    }
    else if(yy == year && mm ==month && dd == date)
    {
                cout<<vec[cnt]<<endl;
    }
    else
    {

        while(1)
        {
                date--;

                if(date == 0)
                {
                        if(isLeap(year))arr1[2]=29;
                        else arr1[2] = 28;

                        date = arr1[month-1];
                        month--;

                        if(month==0)
                        {
                                month = 12;
                                year --;
                        }

                }

                if(date == dd && month==mm && year==yy)
                {
                        cnt--;
                        if(cnt<0)cnt+=7;
                        cout<<vec[cnt]<<endl;
                        break;
                }
                else
                {
                        //cout<<date<<' '<<month<<' '<<year<<endl;
                        cnt--;
                        if(cnt<0)cnt+=7;
                }

        }

    }

return 0;
}

