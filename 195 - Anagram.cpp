#include<bits/stdc++.h>

using namespace std ;

map<char , int>mp ;

bool cmp( char a ,  char b )
{
    return ( mp[a] < mp[b] ) ;
}

int main()
{

    int j = 0 ;
    for( int i = 0 ; i < 26 ; i++ ){
        mp['A'+i] = j++ ;
        mp['a'+i] = j++ ;
    }

    int t ;
    cin >> t ;
    while( t-- ){
        string s ;
        vector<char>v ;
        cin >> s ;
        for( int i = 0 ; i < s.size( ) ; i++ ){
            v.push_back( s[i] ) ;
        }
        sort( v.begin() , v.end() , cmp ) ;
        do{
            for( int i = 0 ; i < v.size() ; i++ ){
                cout << v[i] ;
            }
            cout << endl ;
        }while( next_permutation( v.begin() , v.end() ) ) ;
    }
}
