#include<bits/stdc++.h>

using namespace std ;

int idx ;

bool find_reminder( vector<pair<int,int>>&a , int b )
{
    for( int i = 0 ; i < a.size() ; i++ ){
        if( a[i].first == b ){
            cout << a[i].second << endl ;
            return true ;
        }
    }
    return false ;
}

void printVector( vector<int>&a )
{
    for( int i = 0 ; i < a.size() ; i++ ){
        cout << a[i] ;
    }
    cout << endl ;
}

int main( )
{
    int n , m ;
    while( cin >> n >> m ){
        vector<int>v ;
        map<int,int>reminder;

        while( 1 ){
            reminder[n%m]++;
            if( reminder[n%m] > 1 ){
                break ;
            }
            cout << n%m ;
            n = n%m ;
            n*=10 ;

        }
        cout << endl ;
    }
}
