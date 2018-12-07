#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
typedef long long ll;

ll n,K;
ll arr[MAX];
bool flag ;

void f( ll sum , ll  sum1,  int i )
{
    if( i == (n-1) ){
        cout << sum << " " << sum1 << endl ;
        if( sum%K == 0 ){
            flag = true ;
        }
        return;
    }
    f( sum+arr[i] ,sum1-arr[i] ,i+1 );
    //f( sum-arr[i] , i+1 );
}

int main()
{
    int t;
    cin >> t;

    while( t-- ){
        cin >> n >> K;

        for( int i = 0; i < n; i++ ){
            cin >> arr[i];
        }
        flag = false;
        f( arr[0] ,arr[0], 1);
        if( flag ){
            cout << "Divisible" << endl ;
        }
        else{
            cout << "Not divisible" << endl ;
        }
    }
}
