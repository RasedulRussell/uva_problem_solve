#include<bits/stdc++.h>

using namespace std ;

int coin[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 } ;

long long table[30000+3] ;


long long process( )
{
    ///memset( table , 0 , sizeof( table ) ) ;
    table[0] = 1 ;
    for( int i = 0 ; i < 11 ; i++  )
    {
        for( int j = coin[i] ; j <= 30000 ; j++ )
        {
            ///if( j >= coin[i] ){
            table[j] += table[j-coin[i]] ;
            ///}
        }
    }
}

int main( )
{
    process( ) ;
    double n ;
    while( cin >> n )
    {
        if( n == 0.00 )
        {
            return 0 ;
        }
        n+=0.001 ;
        /// cout << n << endl ;
        long long tk = n*100 ;
        ///cout << tk << endl ;
        printf("%6.2lf%17lld\n",n,table[tk]) ;
    }
}
