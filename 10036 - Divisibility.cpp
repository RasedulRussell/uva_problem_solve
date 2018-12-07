#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 10005

ll n , k;
ll arr[MAX];
bool flag = false;

void f( ll sum , int idx )
{
    if( idx == n-1 ){
        cout << "hello" << endl ;
        if( sum % k == 0 ){
            flag = true;
        }
        return;
    }
    if( idx <= n-1 ){
        f( sum+arr[idx] , idx+1 );
        f( sum-arr[idx] , idx+1 );
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while( t-- ){
        cin >> n >> k;
        for( int i =0; i < n; i++ ){
            cin >> arr[i];
        }
        flag = false;
        //f( 0 , 0 );
        queue<ll>q;
        for( int i = 0; i < n; i++ ){
            ll a = arr[i];
            ll sz = q.size();
            for( int j = 0; j < sz; j++ ){
                ll sum =
            }
        }
        if( flag ){
            cout << "Di" << endl ;
        }
        else{
            cout << "Not" << endl ;
        }
    }
}
