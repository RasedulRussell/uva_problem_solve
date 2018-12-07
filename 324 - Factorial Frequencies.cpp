#include<bits/stdc++.h>

using namespace std ;

int huha[10] ;
string fact = "1" ;

void prosess(  )
{
    memset( huha , 0 , sizeof( huha ) ) ;
    for( int i = 0 ; i < fact.size( ) ; i++ )
    {
        int te = fact[i] - 48 ;
        huha[te]+=1 ;
    }
}

void gun( int num )
{
    reverse( fact.begin( ), fact.end( ) ) ;
    string ss = "" ;
    int temp, carry = 0 ;
    for( int i = 0 ; i < fact.size( ) ; i++ )
    {
        temp = ( fact[i] - 48 ) * num + carry ;
        if( temp > 9 )
        {
            ss += temp%10 + 48 ;
            carry = temp/10 ;
        }
        else
        {
            ss += temp + 48 ;
            carry = 0 ;
        }
    }
    if( carry > 0 )
    {
        while( carry > 0 )
        {
            ss+=carry%10 +48 ;
            carry /= 10 ;
        }
    }
    reverse( ss.begin( ), ss.end() ) ;
    fact = ss ;
}

void fac( int fa )
{
    for( int i = 1 ; i <= fa ; i++ )
    {
        gun( i ) ;
    }
    prosess( ) ;
}

void print( )
{
    for( int i = 0 ; i < 10 ; i++ )
    {
        cout << "(" << i << ") " << huha[i] ;
        if( i == 4 )
            cout << endl ;
        else if( i != 9 ){
            cout << " " ;
        }
    }
    cout << endl ;
}

int main( )
{
    int n ;
    while( cin >> n && n != 0 )
    {
        fac( n ) ;
        cout << fact << endl ;
        ///cout << n << "! --" << endl ;
       /// print(  ) ;
        fact = "1" ;
    }
    return 0 ;
}
