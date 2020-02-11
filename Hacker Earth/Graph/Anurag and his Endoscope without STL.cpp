#include<bits/stdc++.h>
/** shar vai  code   https://paste.ubuntu.com/p/Sy7vYWsD4p/   **/
using namespace std ;

int T , N , M ,  R , C ,  L , greed[1005][1005] , head , tail  , tot , visited[1005][1005] ;
int fy[] = {1 , 0 , -1 , 0 } ; // R , D , L , U 
int fx[] = {0 , 1 ,  0 , -1 } ; // R , D , L , U 

struct info
{
    int p1 , p2 , cost ;
    info(){} ;
    info(int a , int b , int c ){
        p1 = a , p2 = b , cost = c ;
    }
} Q[1000006];

void initVisit() ;
void initQueue() ; 
void push(info v) ;
void pop() ;
info front() ;
bool isEmpty() ;
bool Up(int ux , int uy , int x , int y) ;
bool Right(int ux , int uy , int x , int y) ;
bool Down(int ux , int uy , int x , int y) ; 
bool Left(int ux , int uy , int x , int y) ; 




bool isOk(int x , int y , int cost )
{
    if(0<= x && x <N && 0<=y && y<M && visited[x][y] == 0 && cost <= L)return 1 ;
    return 0 ;
}

int val(info u)
{
    return greed[u.p1][u.p2] ;
}


int bfs()
{
    initVisit() ;
    initQueue() ;
    tot = 0 ;

    push(info(R, C , 1 )) ;
    visited[R][C] = 1 ;
    if(greed[R][C])tot++ ;

    while (!isEmpty())
    {
        info u = front() ;
        pop() ;

        for(int i = 0 ; i<4 ; i++){
            if(val(u)==1 || (val(u) == 2 && i!=0 && i!=2) || (val(u) == 3 && i!=1 && i!=3) || (val(u) == 4 && i!=1 && i!=2) ||
                (val(u) == 5 && i!= 2 && i!=3) || (val(u) == 6 && i!= 0 && i!=3) || (val(u) == 7 && i!=0 && i!=1)){ 
               
                int vx = u.p1 + fx[i] ;
                int vy = u.p2 + fy[i] ;
                if(isOk(vx , vy , u.cost + 1 )){
                    if(Up(u.p1 , u.p2 , vx , vy) || Right(u.p1 , u.p2 , vx , vy ) || Down(u.p1 , u.p2 , vx , vy ) || Left(u.p1 , u.p2 , vx , vy)){
                        push(info(vx, vy , u.cost+1)) ;
                        visited[vx][vy] = 1 ;
                        tot++ ;
                    }
                }
            }   
        }

    }
    
    return tot ; 
}


int main()
{
    cin >> T ;
    while (T--)
    {
        cin >> N >> M >> R >> C >> L ;
        for(int i = 0 ; i<N ; i++){
            for(int j = 0 ; j<M ; j++)
                cin >> greed[i][j] ;
        }
        cout << bfs() << endl ;
    }

}


void initQueue()
{
    head = tail = 0 ;
}

void push(info v )
{
    Q[tail++] = v ;
}

void pop()
{
    head++ ;
}

info front()
{
    return Q[head] ;
}

bool isEmpty()
{
    if(head == tail)return 1 ;
    return 0 ;
}

bool Up(int ux , int uy , int x , int y)
{
    if(x - ux == -1 && y == uy && (greed[x][y] == 1  || greed[x][y] == 2 || greed[x][y] == 5 || greed[x][y] == 6) )return 1 ;
    return 0 ;
}

bool Right(int ux , int uy , int x , int y)
{
    if(x == ux && y - uy == 1 && (greed[x][y] == 1  || greed[x][y] == 3 || greed[x][y] == 6 || greed[x][y] == 7))return 1 ;
    return 0 ;
}

bool Down(int ux , int uy , int x , int y)
{
    if(x - ux == 1 && y == uy && (greed[x][y] == 1  || greed[x][y] == 2 || greed[x][y] == 4 || greed[x][y] == 7))return 1 ;
    return 0 ;
}

bool Left(int ux , int uy , int x , int y)
{
    if(x == ux && y - uy == -1 && (greed[x][y] == 1  || greed[x][y] == 3 || greed[x][y] == 4 || greed[x][y] == 5))return 1 ;
    return 0 ;
}


void initVisit()
{
    for(int i = 0 ; i<=1000 ; i++){
        for(int j = 0 ; j<=1000; j++)
            visited[i][j] = 0 ;
    }
}
