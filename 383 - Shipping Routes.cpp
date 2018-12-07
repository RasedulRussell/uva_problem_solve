#include<bits/stdc++.h>

using namespace std ;
typedef unsigned long long ull ;

int main()
{
    cout << "SHIPPING ROUTES OUTPUT" << endl << endl ;
    int test ;
    cin >> test ;

    for( int t = 1 ; t <= test ; t++ ){

        int n , m , p ;
        map<string,int>mp ;
        cin >> n >> m >> p ;
        for( int i = 1 ; i <= n ; i++  ){
            string s ; cin >> s ;
            mp[s] = i ;
        }

        ull fw[n+2][n+2] ;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j =1 ; j <= n ; j++ ){
                fw[i][j] = ( i==j )?0:10000000 ;
            }
        }

        for( int i = 0 ; i < m ; i++ ){
            string a , b ; cin >> a >> b ;
            fw[mp[a]][mp[b]] = 1 ;
            fw[mp[b]][mp[a]] = 1 ;
        }

        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    fw[i][j] = min( fw[i][j] , fw[i][k]+fw[k][j] ) ;
                }
            }
        }

        cout << "DATA SET  " << t << endl << endl ;
        for( int i = 0 ; i < p ; i++ ){
            int cost ; string a , b ;
            cin >> cost >> a >> b ;
            ull tk = fw[mp[a]][mp[b]] ;
            if( tk < 10000000 ){
                cout << "$" << tk*cost*100 << endl ;
            }
            else{
                cout << "NO SHIPMENT POSSIBLE" << endl ;
            }
        }
        cout << endl ;
    }
    cout << "END OF OUTPUT" << endl ;
}
