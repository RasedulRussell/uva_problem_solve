#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

bitset<10000010>bits ;
vector<ull>prime ;
vector<ull>result ;
map<ull , int>mp ;
vector<ull>anagramicPrime ;

int digit( ull n )
{
    int cnt = 0 ;
    while( n > 0 ){
        n /= 10 ;
        cnt++;
    }
    return cnt ;
}

void sieve()
{
    bits.set( );
    bits[0] = bits[1] = 0 ;

    for( int i = 2 ; i*i <= 10000000 ; i++ ){
        if( bits[i] ){
            for( int j = i*2 ; j <= 10000000 ; j += i ){
                bits[j] = 0 ;
            }
        }
    }

    for( int j = 2 ; j < 10000000 ; j++ ){
        if( bits[j] ){
            prime.push_back( j ) ;
        }
    }
}

ull numberMaker( vector<int>&arr)
{
    ull ans = 0 ;
    for( int i = 0 ; i < arr.size() ; i++ ){
        ans = ans*10 + arr[i]  ;
    }
    return ans ;
}

bool isPrime( ull a )
{
    if( a <= 10000000 ){
        return bits[a] ;
    }

    for( int i = 0 ; i < prime.size() ; i++ ){
        if( a % prime[i] == 0 ){
            return false ;
        }
    }
    return true ;
}

int main()
{
    /*sieve( ) ;
    ///cout << prime.size( ) << endl ;

    for( int i = 0 ; i < prime.size( ) ; i++ ){
        if( mp[prime[i]] == 0 ){
            vector<int>v;
            int cnt = 0 ;
            ull n = prime[i] ;
            while( n > 0 ){
                v.push_back( n%10 ) ;
                n/=10 ;
            }
            sort( v.begin() , v.end() ) ;
            bool flag = true ;
            do{
                ull a = numberMaker( v ) ;
                if( isPrime( a ) == false ){
                    flag = false ;
                    break ;
                }
            }while( next_permutation( v.begin() , v.end() ) ) ;

            if( flag ){
                ///cout << "ok" << endl ;
                do{
                    ull a = numberMaker( v ) ;
                    anagramicPrime.push_back( a ) ;
                    mp[a] = 1 ;
                }while( next_permutation( v.begin() , v.end() ) ) ;
            }
            else{
                do{
                    ull a = numberMaker( v ) ;
                    mp[a] = 2 ;
                }while( next_permutation( v.begin() , v.end() ) ) ;
            }
            ////cout << prime[i] << endl ;
        }
   }*/
   ull huha[23] = { 2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991 } ;
   ull n ;
   while( cin >> n && n != 0 ){
     ull ans = 0 ;
     int cnt = digit( n ) ;
      for( int i = 0 ; i < 23 ; i++){
        if( huha[i] > n ){
            if( digit(huha[i]) == cnt ){
                ans = huha[i] ;
            }
            break ;
        }
      }
      cout << ans << endl ;
   }
}










