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
	int n, totalPoint;
	int tc;
	cin >> tc;
	for(int cs = 1; cs <= tc; cs++){
		cin >> n >> totalPoint;
		vector<int>points(n+1);
		for(int i = 1; i <= n; i++){
			cin >> points[i];
		}
		ll dp[n+2][totalPoint+2];
		for(int i = 0; i <= n; i++){
			dp[i][0] = 0;
		}
		
		int from[n+1][totalPoint+1];
		memset(from, 0, sizeof from);

		for(int i = 0; i <= n; i++){
			for(int j = 1; j <= totalPoint; j++){
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= totalPoint; j++){
				if(j >= points[i]){
					if(dp[i][j-points[i]] + 1 <= dp[i-1][j]){
						dp[i][j] = dp[i][j-points[i]] + 1;
						from[i][j] = 1;
					}else{
						dp[i][j] = dp[i-1][j];
						from[i][j] = -1;
					}
				}else{
					dp[i][j] = dp[i-1][j];
					from[i][j] = -1;
				}
			}
		}
		vector<int>path;
		if(dp[n][totalPoint] == INF){
			cout << "Case " << cs << ": impossible\n"; continue;
		}
		int i = n, j = totalPoint;
		while( i >= 0 && j > 0 &&  from[i][j] != 0){
			///cout << i << " " << j << "\n";
			if(from[i][j] == 1){
				path.push_back(points[i]);
				j = j - points[i];
			}else{
				i--;
			}
		}
		cout << "Case " << cs << ": [" << dp[n][totalPoint] << "]";
		for(int i = 0; i < path.size(); i++){
			cout << " " << path[i];
		}
		nll;
	}
	return 0;
}