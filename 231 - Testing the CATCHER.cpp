#include<bits/stdc++.h>

using namespace std ;


int main()
{
    int n ;
    int t = 1 ;
    while( cin >> n && n != -1 ){
        if( t != 1 ){
            cout << endl ;
        }
        int arr[100000] ;
        int sz = 0 ;
        arr[sz] = n ; sz++ ;
        while( cin >> n && n != -1 ){
            arr[sz] = n ; sz++ ;
        }
        int LIS[sz+1] ;
        int LIS1[sz+1] ;
        for( int i = 0 ; i < sz ; i++ ){
            LIS[i] = 1 ;
            LIS1[i] = 1 ;
        }
        ///cout << LIS[0] << endl ;
        for( int i = 1 ; i < sz ; i++ ){
            for( int j = 0 ; j < i ; j++ ){
                if( arr[j] < arr[i] && LIS[i] < LIS[j]+1 ){
                    LIS[i] = LIS[j]+1 ;
                }
            }
        }
        for( int i = sz-2 ; i >= 0 ; i-- ){
            for( int j = sz-1 ; j > i ; j-- ){
                if( arr[j] < arr[i] && LIS1[i] < LIS1[j]+1 ){
                    LIS1[i] = LIS1[j]+1 ;
                }
            }
        }

        int lis = 0 ;
        for( int i = 0 ; i < sz ; i++ ){
            lis = max( lis , max(LIS[i] , LIS1[i] )) ;
        }
        cout << "Test #" << t++ << ":" << endl ;
        cout << "  maximum possible interceptions: " << lis << endl  ;
    }
    return 0 ;
}

