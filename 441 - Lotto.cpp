#include<bits/stdc++.h>

using namespace std ;


int main()
{
    int K ;
    int p = 0 ;
    while( cin >> K ){
        if(K==0)return 0 ;
        if( p != 0 ){
            cout << endl ;
        }
        p =1 ;
        int arr[K+1] ;
        for( int i = 0 ; i < K ; i++ )
            cin >> arr[i] ;
        for( int i = 0 ; i < K-5 ; i++ ){
            for( int j = i+1 ; j < K-4 ; j++ ){
                for( int k = j+1 ; k < K-3 ; k++ ){
                    for( int l = k+1 ; l < K-2 ; l++ ){
                        for( int m = l+1; m < K-1 ; m++ ){
                            for( int n = m+1 ; n < K ; n++ ){
                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[l],arr[m],arr[n]) ;
                            }
                        }
                    }
                }
            }
        }
    }
}
