#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll W,w,n;
ll needTime[35];
ll gold[35];
ll table[40][1500];

ll max( ll a , ll b ){return (a>=b)?a:b;}

void KS()
{
    for( int i = 0; i <= n; i++ ){
        for( int waight = 0; waight <= W; waight++ ){
            if( i == 0 || waight == 0 ){
                table[i][waight] = 0;
            }
            else if( needTime[i-1] <= waight ){
                table[i][waight] = max( gold[i-1]+table[i-1][waight-needTime[i-1]] , table[i-1][waight] );
            }
            else{
                table[i][waight] = table[i-1][waight];
            }
        }
    }
}

int main()
{
    int flag = false;
    while( cin >> W >> w ){
        if( flag ){
            cout << endl ;
        }
        flag = true;
        cin >> n ;
        for( int i = 0 ; i < n; i++ ){
            ll d , ww;
            cin >> d >> ww ;
            ll actualTime = d*3*w ;
            needTime[i] = actualTime;
            gold[i] = ww;
        }

        KS();

        vector<pair<ll,ll>>result;
        ll huntingGold = table[n][W];
        ll res = huntingGold,ww = W;

        for( int i = n; i > 0 && res > 0; i-- ){
            if( res == table[i-1][ww] ){
                continue;
            }
            else{
                result.push_back( make_pair( (needTime[i-1])/(3*w) , gold[i-1] ) );
                res -= gold[i-1];
                ww = ww-needTime[i-1];
            }
        }
        cout << huntingGold << endl << result.size() << endl;
        for( int i = result.size()-1; i >= 0; i-- ){
            cout << result[i].first << " " << result[i].second << endl ;
        }
    }
}
