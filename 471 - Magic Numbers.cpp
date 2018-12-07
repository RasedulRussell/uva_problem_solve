#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

bool check( ull n )
{
    map<int , int>mp ;

    while( n > 0 ){
        mp[n%10]++ ;
        if( mp[n%10] >= 2  ){
            return false ;
        }
        n /= 10 ;
    }
    return true ;
}

int main( )
{
    int test ;
    cin >> test ;
    for( int t = 0 ; t < test ; t++ ){
        ull n ;
        cin >> n ;
        for( int i = 1 ; n*i <= 9876543210; i++ ){
            if( check( n*i )== true && check( i ) == true ){
                cout << n*i << " / " << i << " = " << n << endl ;
            }
        }
        if( t != test-1 ){
            cout << endl;
        }
    }
}
