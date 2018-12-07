#include<bits/stdc++.h>

using namespace std ;

bitset<10000010>bs ;
vector<int>prime ;

void seive()
{
    bs.set() ;
    for( long long i = 2 ; i <= 10000000 ; i++ ){
        if( bs[i] ){
            for( long long j = i*i ; j <= 10000000 ; j+=i ){
                bs[j] = 0 ;
            }
        }
        prime.push_back((int)i) ;
    }
}


int numDI( long long N )
{
    int ans = 1 ;
    int idx = 0 ;
    while( prime[idx]*prime[idx] <= N ){
        int count = 0 ;
        while( N%prime[idx] == 0 ){
            count++ ;
            N /= prime[idx] ;
        }
        ans *= ( count+1 ) ;
        idx++ ;
    }
    if( N!=1 ){ans *= 2 ;}
    return ans ;
}

int main()
{
    seive() ;
    int test ;
    cin >> test ;
    while( test-- ){
        long long u , h ;
        int max = 0 ;
        long long n ;
        cin >> u >> h ;
        for( long long i = u ; i <= h ; i++ ){
            int huha = numDI( i ) ;
            if( huha > max ){
                n = i ; max = huha ;
            }
        }
       /// Between 1 and 10, 6 has a maximum of 4 divisors.
        cout << "Between " << u << " and " << h << ", " << n << " has a maximum of " << max << " divisors." << endl ;
    }
    return 0 ;
}

