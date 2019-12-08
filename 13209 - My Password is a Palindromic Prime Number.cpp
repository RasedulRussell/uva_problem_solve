#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define MAX 100000
vector<int>palindromPrime;
vector<int>prime;
bool isPrime[MAX];

bool isPalindrom(int n){
    int N = n;
    int ok = 0;
    while( n ){
        ok = ok*10 + n%10;
        n = n/10;
    }
    return (ok == N);
}

void seive(){
    memset( isPrime, true, sizeof isPrime );
    for( int i = 2; i < MAX; ++i ){
        if( isPrime[i] ){
            prime.push_back(i);
            for( int j = i*2; j < MAX; j+=i ){
                isPrime[j] = false;
            }
        }
    }
    for( int i = 0; i < (int)prime.size(); ++i ){
        if( prime[i] >= 10 ){
            if( isPalindrom(prime[i]) ){
                palindromPrime.push_back(prime[i]);
            }
        }
    }
    //~cout << palindromPrime.size() << "\n";
}

string solve( int n ){
    unordered_map<int, int>mp;
    int rem = 1;
    string res = "";
    while( true ){
        res.push_back( (rem/n) + '0' );
        rem = rem%n;
        mp[rem]++;
        if( mp[rem] == 2 ){
            break;
        }
        if( rem < n ){
            rem = rem*10;
        }
    }
    return res;
}

int main(){

    int times;
    cin >> times;
    while( times-- ){
        int n;
        cin >> n;
        string ok = solve(n);
        for( int i = 0; i < ok.size(); ++i ){
            cout << ok[i];
            if( i == 0 ){
                cout << ".";
            }
        }
        cout << "\n";
    }
    return 0;
}
///13209

