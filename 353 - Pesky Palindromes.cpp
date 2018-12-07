#include<bits/stdc++.h>

using namespace std ;

bool check( string s )
{
    int len = s.size( ) - 1 ;
    for( int i = 0 ; i <= ( len/2 ) ; i++ ){
        if( s[i] != s[len-i] ){
            return false ;
        }
    }
    return true ;
}


int main(  )
{
    string s ;
    while( cin >> s ){
        set<string>total ;
        for( int i = 0 ; i < s.size( ) ; i++ ){
            for( int j = 1 ; j <= s.size( )-i ; j++ ){
                string sub = s.substr( i , j ) ;
                if( check( sub ) ){
                    total.insert( sub ) ;
                }
            }
        }
        cout << "The string '" << s <<"' contains "<< total.size() << " palindromes." << endl ;
    }
    return 0 ;
}
