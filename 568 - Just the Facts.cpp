#include<bits/stdc++.h>

using namespace std ;

int huha[10001] ;
string last_ten_digit = "2" ;

void gun( int n )
{
    string tmp = "" ;
    int temp , carry = 0 ;
    ///cout << last_ten_digit[0] << endl ;
    for( int i = 0 ; i < last_ten_digit.size( ) ; i++ )
    {
        temp = ( last_ten_digit[i] - 48 )*n + carry ;
        ///cout << temp << endl ;
        if( temp > 9 )
        {
            tmp += temp%10 + 48 ;
            carry = temp/10 ;
        }
        else
        {
            tmp += ( temp + 48 ) ;
            carry = 0 ;
        }
    }
    if( carry > 0 )
    {
        while( carry > 0 )
        {
            tmp += carry%10 + 48 ;
            carry /= 10 ;
        }
    }
    int i = 0 ;
    while( tmp[i] == '0' )
    {
        i++ ;
    }
    if( tmp.size(  )-i > 9 )
    {
        last_ten_digit = tmp.substr( i , i+9 ) ;
    }
    else
    {
        last_ten_digit = tmp.substr( i , tmp.size() - i  ) ;
    }
   /// cout << last_ten_digit << endl ;
}

void prosess( )
{
    huha[0] = 1 ;
    huha[1] = 1 ;
    huha[2] = 2 ;
    for( int i = 3 ; i <= 10000 ; i++ )
    {
        gun( i ) ;
        huha[i] = last_ten_digit[0] - 48 ;
    }
}

int digit( int hh )
{
    int cnt = 0 ;
    while( hh > 0 )
    {
        cnt++ ;
        hh /= 10 ;
    }
    return cnt ;
}

int main( )
{
    prosess( ) ;
    /*
    for( int i = 0 ; i < 10001 ; i++ )
        cout << huha[i] << endl ;
        */
    int n ;
    while( cin >> n )
    {
        int dg = digit( n ) ;
        for( int i = 1 ; i <= 5-dg ; i++ )
        {
            cout << " " ;
        }
        cout << n << " -> " << huha[n] << endl ;
    }
    return 0 ;
}
