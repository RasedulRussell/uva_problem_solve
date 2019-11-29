#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int changedN = 0;

int BTD(string n){
    int sz = n.size();
    int N = 0;
    reverse( n.begin(), n.end() );
    ///cout << n << endl;
    for( int i = 0; i < sz; i++ ){
        N += (n[i]-'0')*pow( 2,i );
    }
    changedN = N;
    return N;
}

bool fun( int n, int &cost ){
    string binary = "";
    int tempN = n;
    bool flag = true;
    int cnt = 0;
    while( n ){
        if( n%2 ){
            cnt++;
        }
        binary.push_back( n%2+'0' );
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    binary.push_back( binary[0] );
    binary[0] = '0';
    int ok = BTD(binary);
    if( ok == tempN ){
        cost += ok*2;
        return false;
    }
    cost += tempN - ok;
    return true;
}

int main(){
    int n;
    while( cin >> n ){
        int cost = 0;
        while( fun( n, cost ) ){
            n = changedN;
        }
        cout << cost << "\n";
    }
    return 0;
}

