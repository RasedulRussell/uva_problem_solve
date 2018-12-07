#include<bits/stdc++.h>

using namespace std ;

long long number[11] ;

void gNumber( )
{
    number[0] = 1 ;
    for( int i = 1 ; i <= 10 ; i++ )
    {
        number[i] = ( ( 4*i - 2 )*number[i-1] )/( i+1 ) ;
    }
}

int main()
{
    gNumber() ;
    int n ;
    int c = 0 ;
    while( cin >> n )
    {
        if( c!=0 )
        {
            cout << endl ;
        }
        c = 1;
        cout << number[n] << endl ;
    }
    return 0 ;
}
