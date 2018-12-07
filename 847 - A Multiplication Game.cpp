#include<bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ;

ull n ;
/*ull stp = 1000000000 ;
ull ans ;
ull cnt1 , cnt ;

vector<int>st ;
vector<int>oli ;
set<int>s ;

void fun( ull N , ull a , ull step , ull st )
{

    if( N >= n ){
        ///cout << step << endl ;
        s.insert( step ) ;
        if( stp > step ){
            stp = step ;
            st = step;
        }
        return  ;
    }
    if( st < step ){
        return  ;
    }
    fun( N*2 , 1-a , step+1 , st ) ;
    fun( N*3 , 1-a , step+1 , st ) ;
    fun( N*4 , 1-a , step+1 , st ) ;
    fun( N*5 , 1-a , step+1 , st ) ;
    fun( N*6 , 1-a , step+1 , st ) ;
    fun( N*7 , 1-a , step+1 , st ) ;
    fun( N*8 , 1-a , step+1 , st ) ;
    fun( N*9 , 1-a , step+1 , st ) ;

}
*/
int main( )
{
    while( cin >> n ){
        bool p = 1 ;
        int cnt = 1  ;
        while( cnt < n ){
            if( p )cnt*=9;
            else{cnt*=2;} ;
            p  = !p ;
        }
        if( p ){
            cout << "Ollie wins." << endl ;
        }
        else{
            cout << "Stan wins." << endl ;
        }
    }
}

