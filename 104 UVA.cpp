#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    while( cin >> n ){
        double table[n+3][n+3];
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= n; j++ ){
                if( i == j ){
                    table[i][j] = 1.0;
                    continue;
                }
                cin >> table[i][j];
            }
        }

        int parent[n+2][n+3];
        //for( int i = 1; i <=  )
    }
}
