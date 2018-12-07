#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

bitset<65005>bits ;
vector<ull>prime ;

void sieve( )
{
    bits.set( ) ;

    bits[0] = bits[1] = 0 ;

    for( int i = 2 ; i*i <= 65000 ; i++ ){
        if( bits[i] ){
            for( int j = i*2 ; j <= 65000 ; j+=i ){
                bits[j] = 0 ;
            }
        }
    }

    for( int i = 2 ; i <= 65000 ; i++ ){
        if( bits[i] ){
            prime.push_back( i ) ;
        }
    }
}

ull mode( ull a , ull n )
{
    ull ans = 1 ;

    for( int i = 1 ; i <= n ; i++ ){
        ans = (ans*a)%n ;
    }

    return ans%n ;
}

bool isPrime( ull n )
{
    return bits[n] ;
}

bool check( ull n )
{
    if( isPrime( n ) ){
        return false ;
    }

    int cnt = 0 ;

    for( int i = 0 ; i < prime.size() ; i++ ){
        if( n%prime[i] == 0 ){
            while( n%prime[i] == 0 ){
                n /= prime[i] ;
            }
            cnt++ ;
        }
        if( n <= 1 ){
            break ;
        }
    }

    if( cnt >= 3 ){
        return 1 ;
    }
    return 0 ;
}

int main()
{
    sieve();

    int huha[65000] ;
    ull n ;
    while( cin >> n  && n != 0 ){
        if( check( n ) ){
            cout << "The number " << n << " is a Carmichael number." << endl ;
        }
        else{
            cout << n << " is normal." << endl ;
        }
    }
}
