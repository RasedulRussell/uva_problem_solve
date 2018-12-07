#include<bits/stdc++.h>

using namespace std ;

string vag( string number, unsigned long long divisor )
{
    string ans = "" ;
    int idx = 0 ;
    unsigned long long tamp = number[idx] - '0' ;
    while( divisor > tamp )
    {
        tamp = tamp*10 + number[++idx] - '0' ;
    }
    while( number.size(  ) > idx )
    {
        ans += tamp/divisor + '0' ;
        /// if( idx < number.size() ){
        tamp = (tamp%divisor)*10 + number[++idx] - '0' ;
        /// }
        ///cout << tamp << endl ;
    }
    if( ans.size() == 0 )
        ans = "0" ;
    return ans ;
}

string gun( string ans , unsigned long long n )
{
    reverse( ans.begin( ) , ans.end() ) ;
    unsigned long long temp , carry = 0 ;
    string huha = "" ;
    ///cout << ans << " " << n << endl ;
    for( int i = 0 ; i < ans.size( ) ; i++ )
    {
        temp = ( ans[i]- '0' ) * n + carry ;
        if( temp > 9 )
        {
            huha += temp%10 + '0' ;
            carry = temp / 10 ;
        }
        else
        {
            huha += temp + 48 ;
            carry = 0 ;
        }
    }
    while( carry != 0 )
    {
        huha += carry%10 + '0' ;
        carry /= 10 ;
    }
    ///cout << huha << " " ;
    reverse( huha.begin( ) , huha.end() ) ;
    ///cout << huha << endl ;
    return huha ;
}

string biog( string a , string b )
{
    if( a.size( ) > b.size() )
    {
        for( int i = b.size( ) ; i < a.size( ) ; i++ )
        {
            b = "0" + b ;
        }
    }
    reverse( a.begin( ) , a.end() ) ;
    reverse( b.begin( ) , b.end( ) ) ;
    int temp ;
    int carry = 0 ;
    string ans = "" ;
    for( int i = 0 ; i < a.size( ) ; i++ )
    {
        int f = a[i] - '0' ;
        int s = b[i] - '0' + carry ;
        if( f < s )
        {
            f = f + 10 ;
            carry = 1 ;
        }
        else
        {
            carry = 0 ;
        }
        ans += ( f - s ) + '0' ;
    }
    reverse( ans.begin( ) , ans.end( ) ) ;
    int i = 0 ;
    while( ans[i] == '0' )
    {
        i++ ;
    }
    ans = ans.substr( i , ans.size( ) - i  ) ;
    return ans ;
}

int main(  )
{
    /*
    string a , b ;
    while( cin >> a >> b )
    {
        cout << biog( a , b ) << endl ;
    }
    */
    string num ;
    string sign ;
    unsigned long long n ;
    int test ;
    cin >> test ;
    while( test-- )
    {
        cin >> n >> num ;
        string ans = vag( num , n ) ;
        ans = gun( ans , n ) ;
        ans = biog( num , ans ) ;
        if( ans.size( ) == 0 )
        {
            cout << "0" << endl ;
            continue ;
        }
        cout << ans << endl ;
    }
    return 0 ;
}

