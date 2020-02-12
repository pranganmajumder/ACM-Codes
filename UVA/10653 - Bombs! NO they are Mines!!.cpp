#include<iostream>
#define NMAX    1005
using namespace std ;


int R , C , LINE , greed[NMAX][NMAX] , str , stc , endR , endC ,  head , tail , dis[NMAX][NMAX];

int fy[] = {1 , 0 , -1 , 0 } ;
int fx[] = {0 , 1 , 0  , -1} ;
bool visited[NMAX][NMAX] ;

struct info
{
    int x , y ;
    info(){} ;
    info(int a , int b ){
        x = a , y = b ;
    }
}Q[1000006];


void initQ() ; 
void refresh() ;
void push(info v);
info front() ;
void pop() ; 
bool isEmpty() ;

bool isOk(int xx , int yy)
{
    if(0 <= xx && xx < R && 0<=yy && yy <C)return 1 ;
    return 0 ;
}

void bfs()
{
    initQ() ;
    push(info(str , stc)) ;
    visited[str][stc] = 1 ;
    dis[str][stc] = 0 ;

    while (!isEmpty())
    {
        info u = front() ;
        pop() ;

        for(int i = 0 ; i<4 ; i++){
            int vx = u.x + fx[i] ;
            int vy = u.y + fy[i] ; 
            if(isOk(vx , vy) == 1  && visited[vx][vy] == 0 && greed[vx][vy] == 0){
                dis[vx][vy] = dis[u.x][u.y] + 1 ;
                push(info(vx , vy)) ;
                visited[vx][vy] = 1 ;
            }
        }
    }
    cout << dis[endR][endC] << endl ;
}



int main()
{
    while (cin >> R >> C )
    {
        if(R == 0 && C == 0 )break ;
        cin >> LINE ;
        for(int i = 0 ; i<LINE ; i++){
            int row , elem ;
            cin >> row >> elem ;
            for(int j = 0 ; j<elem ; j++){
                int xx ; cin >> xx ;
                greed[row][xx] = 1 ;  
            }
        }
        cin >> str >> stc ;
        cin >> endR >> endC ;
        bfs() ;

        refresh() ; 
    }
}


void initQ(){
    head = tail = 0 ;
}

void push(info v)
{
    Q[tail++] = v ;
}

info front(){
    return Q[head] ;
}

void pop(){
    head++ ;
}

bool isEmpty()
{
    if(head == tail)return 1 ;
    return 0 ;
}


void refresh()
{
    for(int i = 0 ; i<=1000 ; i++){
        for(int j = 0 ; j<=1000 ; j++){
            visited[i][j] = greed[i][j] = dis[i][j]  = 0 ;
        }
    }
}