#include<bits/stdc++.h>

using namespace std ;

int adjx[] = { -1, -1, -1, 0, 0, 1, 1, 1 } ;
int adjy[] = { 0, 1, -1, -1, 1, -1, 1, 0 } ;

int visit[101][101] ;
char grid[101][101] ;
int n ;

void clear( )
{
    for( int i = 0 ; i < 101 ; i++ )
    {
        for( int j = 0 ; j < 101 ; j++ ){
            visit[i][j] = 0 ;
        }
    }
}

void BFS( int sx , int sy )
{
   /// cout << "bal" << endl ;
    queue<int>q ;
    q.push( sx ) ;
    q.push( sy ) ;
    visit[sx][sy] = 1 ;
    while( !q.empty() )
    {
        int ux = q.front() ;
        q.pop() ;
        int uy = q.front() ;
        q.pop() ;
        for( int i = 0 ; i < 8 ; i++ )
        {
            int vx = ux + adjx[i] ;
            int vy = uy + adjy[i] ;
            if( vx >= 0 && vx < n && vy >= 0 && vy < n && grid[vx][vy] == '1' && visit[vx][vy] == 0 )
            {
                visit[vx][vy] = 1 ;
                q.push( vx ) ;
                q.push( vy ) ;
            }
        }
    }
}


int main()
{
    int t = 1 ;
    clear( ) ;
    while( cin >> n )
    {
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j  = 0 ; j < n ; j++ )
            {
                cin >> grid[i][j] ;
            }
        }
        int count = 0 ;
        for( int i = 0 ; i < n ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == '1' && visit[i][j] == 0 )
                {
                    count++ ;
                    BFS( i , j ) ;
                }
            }
        }
        ///Image number 1 contains 3 war eagles.
        cout << "Image number " << t++ << " contains " << count << " war eagles." << endl ;
        clear( ) ;
    }
    return 0 ;
}
