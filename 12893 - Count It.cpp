#include<bits/stdc++.h>
using namespace std;

#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 500009
#define log_size 18
#define MOD 1000000007
#define INF 10000000000
#define ii pair<ll,ll>
#define presion cout << fixed << setprecision(6)


int main() {
	__FastIO;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		int cnt = 0;
		while(n){
			cnt += (n&1);
			n >>= 1;
		}
		cout << cnt << "\n";
	}
	return 0;
}
