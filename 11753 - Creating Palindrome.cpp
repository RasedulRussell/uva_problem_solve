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

vector<int>v;
int n, k;

ll utilFun(int i, int j, int op){
	if(op > k){
        return INF;
    }
    if(j <= i){
		return op;
	}
	if(v[i] == v[j]){
		return utilFun(i+1, j-1, op);
	}else{
		return min(utilFun(i, j-1, op+1), utilFun(i+1, j, op+1));
	}
}

int main() {
    __FastIO;
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cin >> n >> k;
		v.resize(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
        ll ans = utilFun(0, n-1, 0);
		cout << "Case " << tc << ": ";
        if(ans == 0){
            cout << "Too easy\n";
        }else if(ans <= k){
            cout << ans << "\n";
        }else{
            cout << "Too difficult\n";
        }
	}
	return 0;
}