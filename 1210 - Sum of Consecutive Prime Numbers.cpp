#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

bool status[100000+10] ;
vector<ull>prime ;

void seive( )
{
    memset( status, true, sizeof( status ) ) ;

    for( int i = 2 ; i < 100000+5 ; i++ )
    {
        if( status[i] )
        {
            for( int j = i*2 ; j < 10000+5 ; j = i + j  )
            {
                status[j] = false ;
            }
        }
    }
    for( int i = 2 ; i <= 10000 ; i++ ){
        if( status[i] ){
            prime.push_back( i ) ;
        }
    }
}


int main()
{
    seive() ;
    ull n ;
    while( cin >> n ){
        if( n == 0 )return 0 ;
        ull cnt = 0 ;
        ull sz = prime.size() ;
        for( int i = 0 ; i < sz ; i++ ){
            ull sum = 0 ;
            for( int j = i ; j < sz ; j++ ){
                sum+=prime[j] ;
                if( sum == n ){
                    cnt++ ;
                    break ;
                }
                if( sum > n ){
                    break ;
                }
            }
            if( prime[i] > n ){
                break ;
            }
        }
        cout << cnt << endl ;
    }
}
