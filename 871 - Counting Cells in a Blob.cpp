#include<bits/stdc++.h>

using namespace std ;

int adjx[] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1  } ;
int adjy[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 } ;
char grid[26][26] ;
int visit[26][26] ;
int row ;
int colam ;

void clear(  )
{
    for( int i = 0 ; i < 26 ; i++ )
    {
        for( int j = 0 ; j < 26 ; j++ )
        {
            visit[i][j] = 0 ;
        }
    }
}

int BFS( int sx, int sy )
{
    queue<int>q ;
    int count = 1 ;
    q.push( sx ) ;
    q.push( sy ) ;
    visit[sx][sy] = 1 ;
    while( !q.empty() )
    {
        int ux = q.front() ;
        q.pop() ;
        int uy  = q.front() ;
        q.pop() ;
        for( int i = 0 ; i  < 8 ; i++ )
        {
            int vx = ux + adjx[i] ;
            int vy = uy + adjy[i] ;
            if( vx >= 0 && vx < row && vy >= 0 && vy < colam && visit[vx][vy] == 0 && grid[vx][vy] == '1' ){
             ///  cout << vx << " " << vy << endl ;
                visit[vx][vy] = 1 ;
                count++ ;
                q.push( vx ) ;
                q.push( vy ) ;
            }
        }
    }
    return count ;
}

int main()
{
    int test , t ;
    cin >> test ;
    getchar( ) ;
    getchar( ) ;
    for( t = 1 ; t <= test ; t++ )
    {
        clear();
        string line ;
        row = 0 ;
        while( getline( cin, line ) )
        {
            if( line == "" )break ;
            colam = line.size( ) ;
            for( int i = 0 ; i < line.size( ) ; i++ )
            {
                grid[row][i] = line[i] ;
            }
            row++ ;
        }
        int max = 0 ;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < colam ; j++ )
            {
                if( visit[i][j] == 0 && grid[i][j] == '1' )
                {
                    int huha = BFS( i, j ) ;
                    if( huha > max )
                    {
                        max = huha ;
                    }
                }
            }
        }
        cout << max   ;
        if( t != test ){
            cout << endl ;
        }
    }
    return 0 ;
}

