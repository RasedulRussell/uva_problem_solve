#include<bits/stdc++.h>

using namespace std ;

bool bits[1000005] ;
///vector<int>self_number ;
typedef unsigned long long ull ;

ull sum_digit( int n )
{
    ull sum = n ;
    while( n > 0 ){
        sum += n%10 ;
        n /= 10 ;
    }
    ///cout << sum << endl ;
    return sum ;
}

void process(  )
{
    memset( bits , true , sizeof( bits ) ) ;

    for( int i = 1 ; i <= 1000000 ; i++ ){
        if( bits[i] ){
            ull n = i ;
            ////cout << "generator  " << i << endl ;
            ///int cnt = 0 ;
            while( 1 ){
                ///cnt++ ;
                 n = sum_digit( n ) ;
                if( n > 1000000 || bits[n] == false ){
                    break ;
                }
                bits[n] = false ;
            }
            ///cout << cnt << endl ;
        }
    }
    ///cout << "start" << endl ;
    for( int i = 1 ; i <= 1000000 ; i++ ){
        if( bits[i] ){
            cout << i << endl ;
        }
    }
}

int main( )
{
    ///cout << sum_digit( 1 ) << endl ;
    process( ) ;
}
