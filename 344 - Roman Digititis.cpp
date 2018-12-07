#include<bits/stdc++.h>

using namespace std ;

int result[5] ;

void dosok( char ch )
{
    if( ch == '1' ){
        result[2]++ ;
    }
    else if( ch == '2' ){
        result[2] += 2 ;
    }
    else if( ch == '3' ){
        result[2] += 3 ;
    }
    else if( ch == '4' ){
        result[2]++ ;
        result[3]++ ;
    }
    else if( ch == '5' ){
        result[3]++ ;
    }
    else if( ch == '6' ){
        result[2]++ ;
        result[3]++ ;
    }
    else if( ch == '7' ){
        result[3]++ ;
        result[2]+=2 ;
    }
    else if( ch == '8' ){
        result[3]++ ;
        result[2]+=3 ;
    }
    else if( ch == '9' ){
        result[4]++ ;
        result[2]++ ;
    }
}

void akok( char ch )
{
    if( ch == '1' ){
        result[0]++ ;
    }
    else if( ch == '2' ){
        result[0] += 2 ;
    }
    else if( ch == '3' ){
        result[0] += 3 ;
    }
    else if( ch == '4' ){
        result[0]++ ;
        result[1]++ ;
    }
    else if( ch == '5' ){
        result[1]++ ;
    }
    else if( ch == '6' ){
        result[0]++ ;
        result[1]++ ;
    }
    else if( ch == '7' ){
        result[1]++ ;
        result[0]+=2 ;
    }
    else if( ch == '8' ){
        result[1]++ ;
        result[0]+=3 ;
    }
    else if( ch == '9' ){
        result[2]++ ;
        result[0]++ ;
    }
}

string process( int n )
{
    string ans = "" ;
    while( n > 0 ){
        ans += n%10 + 48 ;
        n /= 10 ;
    }
    reverse( ans.begin( ) , ans.end( ) ) ;
    return ans ;
}

int main( )
{
    int num ;
    while( cin >> num ){
        memset( result , 0 , sizeof( result ) ) ;
        if( num == 0 ){return 0 ;}
        for( int i = 1 ; i <= num ; i++ ){
            string n = process( i ) ;
            int sz = n.size( ) ;
            ///cout << sz << endl ;
            if( sz == 3 ){
            result[4]++ ;
            dosok( n[1] ) ;
            akok( n[2] ) ;
        }
        else if( sz == 2 ){
            dosok( n[0] ) ;
            akok( n[1] ) ;
        }
        else{
            akok( n[0] ) ;
        }
        }
       /// 1: 1 i, 0 v, 0 x, 0 l, 0 c
        cout << num << ": " << result[0] << " i, " << result[1] << " v, " << result[2] << " x, " << result[3] << " l, " << result[4] << " c" << endl ;
    }
}
