#include<bits/stdc++.h>

using namespace std ;

int adjx[] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1  } ;
int adjy[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 } ;
char grid[100][100] ;
int visit[100][100] ;
int row ;
int colam ;

void clear(  )
{
    for( int i = 0 ; i < 100 ; i++ )
    {
        for( int j = 0 ; j < 100 ; j++ )
        {
            visit[i][j] = 0 ;
        }
    }
}

void BFS( int sx, int sy )
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
            if( vx >= 1 && vx <= row && vy >= 1 && vy <= colam && visit[vx][vy] == 0 && grid[vx][vy] == 'W' ){
              ///cout << vx << " " << vy << " " << grid[vx][vy] << endl ;
                visit[vx][vy] = 1 ;
                count++ ;
                q.push( vx ) ;
                q.push( vy ) ;
            }
        }
    }
    cout << count << endl ;
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
        row = 1 ;
        vector< pair<int,int> >quary ;
        while( getline( cin, line ) )
        {
            if( line == "" )break ;
            if( line[0] >= '0' && line[0] <= '9' ){
                stringstream st ;
                int a , b ;
                st << line ;
                st >> a ;
                st >> b ;
                st.clear() ;
                quary.push_back( make_pair( a , b ) ) ;
                continue ;
            }
            colam = line.size( ) ;
            for( int i = 1 ; i <= line.size( ) ; i++ )
            {
                grid[row][i] = line[i-1] ;
            }
            row++ ;
        }
        row-- ;
        ///cout << row << " " << colam << endl ;
        for( int i = 0 ; i < quary.size( ) ; i++ ){
            pair<int,int>pi = quary[i] ;
            ///cout << "quary " << pi.first << " " << pi.second << " " << grid[pi.first][pi.second] << endl ;
            BFS( pi.first , pi.second ) ;
            clear() ;
        }
        if( t != test ){
            cout << endl ;
        }
    }
    return 0 ;
}


