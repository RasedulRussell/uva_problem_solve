#include<bits/stdc++.h>

using namespace std ;
map<string , int>huha ;

void process( string s )
{
    int sz = s.size( ) ;
    string ans = "" ;
    for( int i = 0 ; i < sz ; i++ ){
        if( s[i] == 'Q' || s[i] == 'Z' ){
            continue ;
        }
        else if( s[i] == 'A' || s[i] == 'B' || s[i] == 'C' ){
            ans +=  "2" ;
        }
        else if( s[i] == 'D' || s[i] == 'E' || s[i] == 'F' ){
            ans += "3" ;
        }
        else if( s[i] == 'G' || s[i] == 'H' || s[i] == 'I' ){
            ans += "4" ;
        }
        else if( s[i] == 'J' || s[i] == 'K' || s[i] == 'L' ){
            ans += "5" ;
        }
        else if( s[i] == 'M' || s[i] == 'N' || s[i] == 'O' ){
            ans += "6" ;
        }
        else if( s[i] == 'P' || s[i] == 'R' || s[i] == 'S' ){
            ans += "7" ;
        }
        else if( s[i] == 'T' || s[i] == 'U' || s[i] == 'V' ){
            ans += "8" ;
        }
        else if( s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' ){
            ans += "9" ;
        }
        else if( s[i] != '-' ){
            ans += s[i] ;
        }
        if( ans.size() == 3 ){
            ans += "-" ;
        }
    }
    huha[ans]++ ;
}

int main( )
{
    int test ;
    cin >> test ;
    while( test-- ){
        int n ;
        cin >> n ;
        string faul ;
        for( int i = 0 ; i < n ; i++ ){
            cin >> faul ;
            process( faul ) ;
        }
        map<string,int>::iterator itr ;
        bool flag = true ;
        for( itr = huha.begin( ) ; itr != huha.end( ) ; ++itr ){
            if( itr->second > 1 ){
                cout << itr->first << " " << itr->second << endl ;
                flag = false ;
            }
        }
        if( flag ){
            cout << "No duplicates." << endl ;
        }
        huha.clear( ) ;
    }
    return 0 ;
}
