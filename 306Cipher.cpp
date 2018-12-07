#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n ;
    ///ofstream myfile ;
    ///myfile.open( "306.txt" ) ;
    int h = 1 ;
    while( cin >> n && n != 0 ){
        int k ;
        string s ;
        int a[n+2] ;

        for( int i = 1 ; i <= n ; i++ ){
            cin >> a[i] ;
        }
        char ch ;

        int cycle = 0 ;
            int l = 1 ;
            while( 1 ){
                if( cycle > 0 && l == 1 ){
                    break ;
                }
                l = a[l] ; cycle++ ;
            }

        while( cin >> k && k != 0 ){
            string t ;
            getline( cin , t ) ;
            int len = t.size() ;
            char huha[n+1] ;
            cout << t << endl ;
            for( int i = 0 ; i <= n ; i++ ){
                huha[i] = ' ' ;
            }

            map<int , char>mp ;

            for( int i = 1 ; i < len; i++ ){
                huha[i] = t[i] ;
                mp[i] = t[i] ;
            }
            ///cout << cycle << endl ;
            k = k%cycle ;
            if( k == 0 ){
                k = cycle ;
            }
             char temp[n+3] ;
             bool flag = false ;
            for( int i = 1 ; i <= k*2 ; i++ ){
                for( int j = 0 ; j <= n ; j++ ){
                    temp[j] = ' ' ;
                }
                for( int j = 1 ; j <= n ; j++ ){
                    int aa = a[j] ;
                    ch = huha[j] ;
                    temp[aa] = ch ;
                }

                for( int j = 0 ; j <= n ; j++ ){
                    huha[j] = ' ' ;
                }
                for( int j = 1 ; j <= n ; j++ ){
                    huha[j] = temp[j] ;
                }
            }
            for( int i = 1 ; i <= n ; i++ ){
                cout << temp[i] ;
            }
            cout << endl ;
        }
        cout << endl ;
    }
    return 0 ;
}
