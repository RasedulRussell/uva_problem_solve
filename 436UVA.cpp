#include<bits/stdc++.h>
//AC
using namespace std ;
#define EPS 1e-9

int main()
{
    int n;
    int testCase = 1 ;
    while( cin >> n && n ){
        map<string,int>mp;
        int cnt = 1;
        for( int i = 0; i < n; i++ ){
            string s;
            cin >> s;
            mp[s] = cnt++ ;
        }
        int m ;
        cin >> m;
        double table[50][50];
        for( int i = 0; i <50; i++ ){
            for( int j = 0; j < 50; j++ ){
                table[i][j] = 0.0 ;
            }
        }

        for( int i = 0; i < m; i++ ){
            string s1 , s2 ;
            double c;
            cin >> s1 >> c >> s2;
            table[mp[s1]][mp[s2]] = c;
        }

        for( int k = 1; k <= n; k++ ){
            for( int i = 1; i <= n; i++ ){
                for( int j = 1;  j <= n; j++ ){
                    table[i][j] = max( table[i][j] , table[i][k]*table[k][j] ) ;
                }
            }
        }
        bool flag = false ;
        for( int i = 1; i <= n; i++ ){
            //cout << i << " " << table[i][i] << endl ;
            if( table[i][i] > 1.0 ){
                flag = true ;
                break ;
            }
        }
        if( flag ){
            cout << "Case " << testCase++ << ": Yes" << endl ;
        }
        else{
            cout << "Case " << testCase++ << ": No" << endl ;
        }
    }
}
