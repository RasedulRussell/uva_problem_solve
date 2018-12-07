#include<bits/stdc++.h>

using namespace std ;

string gun( string number , int n )
{
    string ans = "" ;
    int tamp , carry = 0 ;
    reverse( number.begin() , number.end() ) ;
    for( int i = 0 ; i < number.size() ; i++ )
    {
        tamp = ( number[i] - '0' ) * n + carry ;
        ///cout << tamp << endl ;
        if( tamp > 9 )
        {
            ans += tamp%10 + '0' ;
            carry = tamp/10 ;
        }
        else
        {
            ans += tamp + '0' ;
            carry = 0 ;
        }
    }
    if( carry != 0 )
    {
        while( carry != 0 )
        {
            ans += carry%10 + '0' ;
            carry /= 10 ;
        }
    }
    reverse( ans.begin( ) , ans.end( ) ) ;
    return ans ;
}

string vag( string number , int divisor )
{
    string ans = "" ;
    int idx = 0 ;
    int tamp = number[idx] - '0' ;
    while( divisor > tamp )
    {
        tamp = tamp*10 + number[++idx] - '0' ;
    }
    while( number.size(  ) > idx )
    {
        ans += tamp/divisor + '0' ;
        tamp = (tamp%divisor)*10 + number[++idx] - '0' ;
    }
    return ans ;
}

string binomialCofficent( int n , int k )
{
    if( k > n - k ){
        k = n - k ;
    }
    string bCofficent = "1" ;
    for( int i = 0 ; i < k ; i++ )
    {
        bCofficent = gun( bCofficent , n-i ) ;
        bCofficent = vag( bCofficent , i+1 ) ;
    }
    return bCofficent ;
}

bool CM( string s )
{
    string cm ="1000000000000000000000000000000000000000000000000000000000000" ;
    ///cout << "ahdsgh " <<  cm.size() << endl ;
    if( s == cm )
        return true ;
    if( s.size() >= 61 )
        return true ;
    return false ;
}


int main()
{
    cout << "1" << endl ;
    bool exit = false ;
    for( int i = 1 ; i < 1000 ; i++ )
    {
        for( int j = 0 ; j <= i ; j++ )
        {
            string ncr = binomialCofficent( i , j ) ;
            if( CM( ncr ) )
            {
                ///cout << endl <<  i << j << endl ;
                exit = true ;
                ///break ;
            }
            cout << ncr ;
            if( j!=i )
            {
                cout << " " ;
            }
        }
        cout << endl ;
        if( exit )
        {
            return 0 ;
        }
    }
    }
}
