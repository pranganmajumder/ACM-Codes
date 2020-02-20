


#include<iostream>
#include<bits/stdc++.h>
typedef long long int LL ;
#define NMAX    25

/** using all possible subset code link  =  https://paste.ubuntu.com/p/SrNcCRWjp9/  **/

using namespace std ;

int N , freq ,  a[NMAX] , mx , ans , cnt ;

int Set(int n , int pos)
{
    return n = n | (1 << pos) ;
}

bool Check(int n , int pos)
{
    return (bool)(n & (1<<pos)) ;
}

void fun(int pos , int curr , int mask , int nilam) 
{   
    if(pos == freq){
        if(curr <= N && curr >= mx){
            if(curr > mx){
                mx = curr ;
                cnt = nilam ;
                ans = mask ;
            }
            if(curr == mx && nilam > cnt){
                cnt = nilam ;
                ans = mask ;
            }
        }
        return ;  
    }

    if(curr + a[pos] <= N){ // nia samne zao 
        fun(pos + 1 , curr + a[pos] , Set(mask , pos) , nilam+1 ) ;
    }
    fun(pos + 1 , curr ,  mask , nilam) ; // na nia samne zao 
}



int main()
{

    while(cin >> N >> freq){
        for(int i = 0 ; i<freq ; i++)cin >> a[i] ;
        fun(0 , 0 , 0 , 0) ;
        for(int i = 0 ; i<freq ; i++){
            if(Check(ans , i))cout << a[i] << ' ' ;
        }
        cout << "sum:"<< mx << endl ;
        mx = ans = cnt = 0 ;
    }
    
}