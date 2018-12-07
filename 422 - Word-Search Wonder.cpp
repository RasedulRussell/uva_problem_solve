#include<bits/stdc++.h>

using namespace std ;

char grid[101][101] ;
int row, colam, n ;
vector< pair<int,int> >huha ;

bool boundary_check( int i, int j )
{
    if( i >= 1 && i <= n && j >= 1 && j <= n )
    {
        return true ;
    }
    return false ;
}

bool finding( string word, int i, int j, pair<int,int>pi )
{
    int sz = 0 ;
    int sx = i;
    int sy = j ;
    char ch = word[sz] ;
    char gChar = grid[i][j] ;
    while( gChar == ch )
    {
        sz++ ;
        ch = word[sz] ;
        if( sz == word.size( ) )
        {
            /*if( sx >= i && sy >= j  )
            {
                cout << "Not found" ;
                return true ;
            }*/
            cout << sx << "," << sy << " " << i << "," << j  ;
            return true ;
        }
        i += pi.first ;
        j += pi.second ;
        gChar = grid[i][j] ;
        ///cout << gChar << " " << ch << "sz = " << sz << endl ;
        if( boundary_check( i, j )==false )
        {
            break ;
        }
    }
    return false ;
}



void check( string word )
{
    int sz = 0 ;
    char ch = word[0] ;
    for( int i = 1 ; i <= n ; i++ )
    {
        for( int j = 1 ; j <= n ; j++ )
        {
            char gch = grid[i][j] ;
            if( gch == ch )
            {
                for( int k = 0 ; k < 8 ; k++ )
                {
                    if( finding( word, i, j, huha[k] ) )
                    {
                        return ;
                    }
                }
            }
        }
    }
    cout << "Not found" ;
}


int main()
{
    huha.push_back( make_pair( 0, 1 ) ) ;
    huha.push_back( make_pair( 0, -1 ) ) ;
    huha.push_back( make_pair( -1, 0 ) ) ;
    huha.push_back( make_pair( 1, 0 ) ) ;
    huha.push_back( make_pair( 1, 1 ) ) ;
    huha.push_back( make_pair( 1, -1 ) ) ;
    huha.push_back( make_pair( -1, 1 ) ) ;
    ///huha.push_back( make_pair( -1, -1 ) ) ;
    int t = 0 ;
    while( cin >> n  )
    {
        if( n == 0 )return 0 ;
        /// if( t != 0 )cout << endl ; t++ ;
        for( int i = 1 ; i <= n ; i++ )
        {
            for( int j = 1 ; j <= n ; j++ )
            {
                cin >> grid[i][j] ;
            }
        }
        vector<string>word ;
        string bal ;
        getchar( ) ;
        while( getline( cin, bal ) )
        {
            if( bal.size( ) == 0 )break ;
            word.push_back( bal ) ;
        }
        /// cout << "sajdfh" << endl ;
        ///int cnt = 0 ;
        for( int i = 0 ; i < word.size() ; i++ )
        {
            ///cnt++ ;
            string srch = word[i] ;
            if( i != word.size() - 1 )
            {
                check( srch ) ;
            }
            if( i != word.size() )
            {
                cout << endl ;
            }
        }
        ///cout << "sdf " << cnt << endl ;
    }
    return 0 ;
}

