#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull ;

int n , m ;
ull arr[10000] ;

void input(  )
{
    for( int i = 0 ; i < m ; i++ ){
        cin >> arr[i] ;
    }
}

set<vector<ull>>s ;

void f( ull sum , int po , vector<ull>v )
{
    if( po > m ){
        return ;
    }
    if( sum == n ){
        s.insert( v ) ;
        return ;
    }
    f( sum , po+1 , v ) ;
    v.push_back( arr[po] ) ;
    f( sum+arr[po] , po+1 , v ) ;
}

void p( vector<ull>v )
{
    for( int i = 0 ; i < v.size( ) ; i++ ){
        cout << v[i] ;
        if( i < v.size()-1 ){
            cout << "+" ;
        }
        else{
            cout << endl ;
        }
    }
}

int main()
{
    while( cin >> n >> m && n != 0 && m != 0 ){
        input() ;
        vector<ull>v ;
        f( 0 , 0 , v ) ;
        ///Sums of 5:
        cout << "Sums of " << n << ":" << endl ;
        if( s.size( ) == 0 ){
            cout << "NONE" << endl ;
        }
        else{
            vector<ull>v ;
            set<vector<ull>>::iterator itr = s.end() ;
            for( --itr ; itr != s.begin() ; --itr ){
                v = *itr ;
                p(v) ;
            }
            p( *itr ) ;
        }
        s.clear() ;
    }
}










