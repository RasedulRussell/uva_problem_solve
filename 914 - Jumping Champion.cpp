#include<bits/stdc++.h>

using namespace std ;

typedef long long ull ;

bitset<1000009>bits ;
vector<ull>prime ;

ull difference[1000000] ;

void sieve()
{
    bits.set( ) ;

    for( int i = 2 ; i*i <= 1000000 ; i++ ){
        if( bits[i] ){
            for( int j = i*2 ; j <= 1000000 ; j+=i ){
                bits[j] = 0 ;
            }
        }
    }

    for( int i = 2 ; i <= 1000000 ; i++ ){
        if( bits[i] ){
            prime.push_back( i ) ;
        }
    }
}

void store_difference()
{
     difference[0] = 0 ;
     for( int i = 1 ; i < prime.size( )-1 ; i++ ){
        difference[i-1] = prime[i] - prime[i-1] ;
     }
}

ull upb( ull n )
{
    ull lo = 0 , hi = prime.size( ) - 1 ;
    ull mid ;
    ull ans ;
    while( lo <= hi ){
        mid = ( lo+hi )/2 ;

        if( prime[mid] == n || lo == hi ){
            return mid ;
        }

        if( prime[mid] > n ){
            hi = mid - 1 ;
            ans = mid ;
        }
        else{
            lo  = mid  + 1 ;
            ans = mid ;
        }
        ///cout << lo << " " << hi << endl ;
    }
    return ans ;
}

ull lwb( ull n )
{
    ull lo = 0 , hi = prime.size( ) ;
    ull mid ;
    ull ans ;

    while( lo <= hi ){

        mid = (lo+hi)/2 ;

        if( prime[mid] == n ){
            ///cout << "a" << endl;
            return mid ;
        }

        if( prime[mid] > n ){
            hi = mid - 1 ;
            ans = mid ;
        }
        else{
            lo = mid + 1 ;
            ans = mid ;
        }
    }
    return hi ;
}

int main()
{
    sieve() ;
    store_difference() ;
    cout << prime.size() << endl ;

    int test ;
    cin >> test ;
    while( test-- ){
    ull a , b ;

        cin >> a >> b ;

        if( a == b ){
            cout << "No jumping champion" << endl ; continue ;
        }

        ull st = upb( a ) ;
        ull ed = lwb( b )  ;

        map<ull , int>fre ;

        for( int i = st ; i < ed ; i++ ){
            fre[difference[i]]++ ;
        }

        ull ans , max_fre = 0 ;
        int cnt = 0 ;
        for( map<ull , int>::iterator it = fre.begin( ) ; it != fre.end( ) ;++it  ){
            if( it->second > max_fre ){
                max_fre = it->second ;
                ans = it->first ;
                cnt = 0 ;
            }
            if( it->second == max_fre ){
                cnt++ ;
            }
        }

        if( cnt > 0 || max_fre == 1 ){
            cout << "No jumping champion" << endl ;
        }
        else{
            cout << "The jumping champion is " << ans << endl;
        }
    }
}






