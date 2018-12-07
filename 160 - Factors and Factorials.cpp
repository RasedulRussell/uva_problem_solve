///russell_07
/// 160 - Factors and Factorials
/// 23 07 2017

#include<bits/stdc++.h>
using namespace std ;

bool status[200] ;
vector<int>prime ;
int maxPrime = 2 ;

void seive()
{
    memset( status , true , sizeof( status ) ) ;
    for( int i = 2 ; i*i < 104 ; i++ )
    {
        if( status[i]==true )
        {
            for( int j = i*2 ; j < 104 ; j+=i )
            {
                status[j] = false ;
            }
        }
    }
    for( int i = 2 ; i < 104 ; i++ )
    {
        if( status[i]==true )
        {
            prime.push_back( i ) ;
        }
    }
}

void divisor( int n , int huha[] )
{
    for( int i = 0 ; prime[i] <= n ; i++ )
    {
        if( n%prime[i]==0 )
        {
            maxPrime = ( maxPrime >= prime[i] ) ? maxPrime : prime[i] ;
            while( n%prime[i]==0 )
            {
                huha[prime[i]]++;
                n = n/prime[i] ;
            }
        }
        ///cout << prime[i] << " " << n << endl ;
    }
   /// if( n > 1 )
       /// huha[n]++;i
       /// maxPrime = ( maxPrime >= n ) ? maxPrime : n ;
}

int main()
{
    seive( ) ;
    ///cout<<prime[prime.size()-1] <<" "<< prime.size() <<  endl ;
    int n ;
    while( cin >> n )
    {
        if( n==0 )
            return 0 ;
        int huha[110] ;
        ///cout<<"hsgdaj" << endl ;
        memset( huha , 0 , sizeof( huha ) ) ;
        for( int i = 2 ; i <= n ; i++ )
        {
            divisor( i , huha ) ;
            ///cout<<i<<endl ;
        }
        ///cout<<"ahsdfk"<<endl ;
        if( n < 10 )
            cout<< "  " << n << "! ="  ;
        else if( n==100 )
            cout<< n << "! ="  ;
        else
            cout<< " " << n << "! ="  ;
        for( int i = 0 ; i < prime.size() ; i++ )
        {
            if( huha[prime[i]] < 10 )
                cout << "  " << huha[prime[i]] ;
            else
                cout << " " << huha[prime[i]] ;
            ///cout<<" @ " ;
            if( prime[i] == maxPrime )
                break ;
            if( i == 14 )
                 cout << endl << "      " ;
        }
        cout << endl ;
        maxPrime = 0 ;
    }
    return 0 ;
}

