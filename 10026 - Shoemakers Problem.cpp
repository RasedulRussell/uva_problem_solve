#include<bits/stdc++.h>

using namespace std ;

struct job
{
    int time , panalty ;
    int po ;
};

bool cmp( job a , job b )
{
    return ( a.panalty*b.time > b.panalty*a.time ) ;
}

int main( )
{
    int test , t = 1 ;
    cin >> test ;

    while( test-- ){
        if( t != 1 ){
            cout << endl ;
        }
        t++ ;

        int n ;
        cin >> n ;

        vector<job>v ;
        job temp ;

        for( int i = 1 ; i <= n ; i++ ){
            cin >> temp.time >> temp.panalty ;
            temp.po = i ;
            v.push_back( temp ) ;
        }

        sort( v.begin(),v.end() , cmp ) ;

        for( int i = 0 ; i < n ; i++ ){
            cout << v[i].po ;
            if( i == n-1 ){
                cout << endl ;
            }
            else{
                cout << " ";
            }
        }
    }
}

