#include<bits/stdc++.h>

using namespace std ;

char table[105][105] ;

int main()
{
    string s ;
    int row = -1 ;
    int n = 0 ;
    int max_len = 0 ;
    for( int i = 0 ; i <= 100 ; i++ ){
        for( int j = 0 ; j <= 100 ; j++ ){
            table[i][j] = ' ' ;
        }
    }
   /// cout << table[0][0] << "a" << endl ;
    while( getline( cin , s ) && s.size( ) > 0 ){
        row++ ;
        for( int i = 0 ; i < s.size( ) ; i++ ){
            table[row][i] = s[i] ;
            ///cout << table[row][i] ;
            max_len = max( max_len , (int)s.size( ) ) ;
        }
        ////cout << endl ;
    }

    for( int i = 0 ; i < max_len ; i++ ){
        for( int j = row ; j >= 0 ; j-- ){
            cout << table[j][i] ;
        }
        cout << endl ;
    }
}
