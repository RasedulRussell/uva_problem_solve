#include<bits/stdc++.h>

using namespace std ;

char grid[51][51] ;
int row, colam ;
vector< pair<int,int> >huha ;

bool boundary_check( int i, int j )
{
    if( i >= 1 && i <= row && j >= 1 && j <= colam )
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
    if( ch >= 'A' && ch <= 'Z' )
    {
        ch = (char)tolower(ch) ;
    }
    char gChar = grid[i][j] ;
    if( gChar >= 'A' && gChar <= 'Z' )
    {
        gChar = (char)tolower(gChar) ;
    }
    while( gChar == ch )
    {
        sz++ ;
        ch = word[sz] ;
        if( ch >= 'A' && ch <= 'Z' )
        {
            ch = (char)tolower(ch) ;
        }
        if( sz == word.size( ) )
        {
            cout << sx << " " << sy << endl ;
            return true ;
        }
        i += pi.first ;
        j += pi.second ;
        gChar = grid[i][j] ;
        if( gChar >= 'A' && gChar <= 'Z' )
        {
            gChar = (char)tolower(gChar) ;
        }
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
    int len = word.size( ) ;
    bool flag = false ;
    char ch = word[0] ;
    if( ch >= 'A' && ch <= 'Z' )
    {
        ch = (char)tolower( ch ) ;
    }
    for( int i = 1 ; i <= row ; i++ )
    {
        for( int j = 1 ; j <= colam ; j++ )
        {
            char gch = grid[i][j] ;
            if( gch >= 'A' && gch <= 'Z' )
            {
                gch = (char)tolower( gch ) ;
            }
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
    ///cout << "not find" << endl ;
}


int main()
{
    huha.push_back( make_pair( 1, 1 ) ) ;
    huha.push_back( make_pair( 1, 0 ) ) ;
    huha.push_back( make_pair( 1, -1 ) ) ;
    huha.push_back( make_pair( 0, 1 ) ) ;
    huha.push_back( make_pair( 0, -1 ) ) ;
    huha.push_back( make_pair( -1, 1 ) ) ;
    huha.push_back( make_pair( -1, 0 ) ) ;
    huha.push_back( make_pair( -1, -1 ) ) ;
    int test , t ;
    cin >> test ;
    for( t = 1 ; t <= test ; t++ )
    {
        cin >> row >> colam ;
        for( int i = 1 ; i <= row ; i++ )
        {
            for( int j = 1 ; j <= colam ; j++ )
            {
                cin >> grid[i][j] ;
            }
        }
        int quary ;
        vector<string>word ;
        cin >> quary ;
        while( quary-- )
        {
            string bal ;
            cin >> bal ;
            word.push_back( bal ) ;
        }
        for( int i = 0 ; i < word.size() ; i++ )
        {
            string srch = word[i] ;
            check( srch ) ;
        }
        if( t != test ){
            cout << endl ;
        }
    }
    return 0 ;
}

