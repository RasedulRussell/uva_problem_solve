#include<bits/stdc++.h>

using namespace std ;


int main( )
{
    int test ;
    cin >> test ;
    getchar( ) ;
    while( test-- ){
        getchar( ) ;
        map<int , string>huha ;
        string line ;
        int temp ;
        vector<int>number ;
        stringstream st ;
        getline( cin , line ) ;
        st << line ;
        while( st >> temp ){
            number.push_back( temp ) ;
        }
        int sz = number.size( ) ;
        string bal ;
        for( int i = 1 ; i <= sz ; i++ ){
            cin >> bal ;
            huha[number[i-1]] = bal ;
        }
        map<int,string>::iterator itr ;
        for( itr = huha.begin() ; itr != huha.end() ; itr++ ){
            cout << itr->second << endl ;
        }
        if( test != 0 ){
            cout << endl ;
        }
        getchar( ) ;
    }
    return 0 ;
}

