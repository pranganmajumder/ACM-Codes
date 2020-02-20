#include<iostream>
#include<bits/stdc++.h>
#define NMAX    10004 

using namespace std ;

int n , query , a[NMAX] , q[NMAX];

int bin(int num)
{
    int lo = 1 , hi = n , mid , res = 0 ;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2 ;
        if(num < a[mid]){
            hi = mid - 1 ;
        }
        else if(a[mid] < num){
            lo = mid + 1 ;
        }
        else if(a[mid] == num){
            hi = mid - 1 ;
            res = mid ;
        }
    }
    return res ;
    
}


int main()
{
    int cas = 1 ;
    while (cin >> n >> query)
    {
        if(n == 0 && query == 0)break ;
        for(int i = 1 ; i<=n ; i++)cin >> a[i] ;
        sort(a+1 , a+n+1) ;
        printf("CASE# %d:\n",cas++);
        for(int i = 1 ; i<=query ; i++){
            int x ; cin >> x ;
            int res = bin(x) ;
            if(res)printf("%d found at %d\n",x,res);
            else printf("%d not found\n",x);
        }
    }
    
}