#include<bits/stdc++.h>


using namespace std ;

typedef unsigned long long  ull ;
typedef long long  ll ;

map<char , int> process( string s )
{
   /// cout << s << endl ;
    map<char , int>mp ;
    for( int i = 0 ; i < s.size( ) ; i++ ){
        char a = tolower( s[i] ) ;
        mp[a]++ ;
    }
    return mp ;
}

int main( )
{

    string s ;
    vector<pair<string , map<char , int>>>store ;

    while( getline( cin , s ) ){
        if( s == "#" ){
            break ;
        }
        stringstream st ;
        st << s ; string temp ;
        while( st >> temp ){
            map<char , int>mp = process( temp ) ;
            store.push_back( make_pair( temp , mp ) ) ;
        }
    }

    set<string>result ;
    bool check[store.size()+1] ;
    memset( check , true , sizeof( check ) ) ;
    ///cout << store.size() << endl ;
    for( int i = 0 ; i < store.size( ) ; i++ ){
        pair<string , map<char , int>>parent = store[i] ;
        bool flag = true ;
        if( check[i] == true ){
            ///check[i] = false ;
            ///cout << "parent   " << parent.first << endl ;
            for( int j = i+1 ; j < store.size( ) ; j++ ){
            pair<string , map<char , int>>child = store[j] ;
            if( parent.second == child.second ){
                ///cout << child.first << endl ;
                check[j] = false ;
                check[i] = false ;
                flag = false ;
              }
           }
           ///cout << "hsdjhsja" << endl ;
        }
        if( check[i] ){
            result.insert( parent.first ) ;
        }
    }
    for( set<string>::iterator itr = result.begin( ) ; itr != result.end() ; ++itr ){
        cout << *itr << endl ;
    }
    return 0 ;
}

