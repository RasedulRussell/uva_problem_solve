#include <bits/stdc++.h>
using namespace std;

#define __FastIO                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define dbg cout << "dbg\n"
#define nll cout << "\n"
#define ll long long
#define MAX 100005
#define log_size 18
#define MOD 1000000007
#define INF 10000000000
#define ii pair<ll, ll>
#define presion cout << fixed << setprecision(6)

struct itm {
	bool a, b;
};

struct segmentTree {
	int size;
	vector<int>tree;
	void ini(int n){
		size = 1;
		while(size < n) size = 2 * size;
		tree.assign(2 * size, 0);
		return;
	}
	void update(int l, int r, int value, int x, int lx, int rx){
		if(l <= lx && rx-1 <= r){
			tree[x] = value;
			return;
		}
		if(l >= rx || r < lx){
			return;
		}
		if(tree[x] == 2){
			tree[2 * x + 1] = tree[x];
			tree[2 * x + 2] = tree[x];
			tree[x] = 0;
		}
		int mid = (lx + rx) / 2;
		update(l, r, value, 2 * x + 1, lx, mid);
		update(l, r, value, 2 * x + 2, mid, rx);
	}
	void update(int l, int r, int value){
		update(l, r, value, 0, 0, size);
	}
	int query(int idx, int x, int lx, int rx){
		if(rx - lx == 1){
			return tree[x];
		}
		if(tree[x] == 2){
			tree[2 * x + 1] = tree[x];
			tree[2 * x + 2] = tree[x];
			tree[x] = 0;
		}
		int mid = (lx + rx) / 2;
		int a = -1;
		if(idx < mid){
			a = query(idx, 2 * x + 1, lx, mid);
		}else{
			a = query(idx, 2 * x + 2, mid, rx);
		}
		return a;
	}
	int query(int idx){
		return query(idx, 0, 0, size);
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		int cnt = 0;
		segmentTree st;
		st.ini(1000005);
		for(int i = 0; i < n; i++){
			int value;
			cin >> value;
			int a = st.query(value);
			if(a == 1){
				cnt++;
				st.update(1, 100003, 2);
			}
			st.update(value, value, 1);
		}
		cout << cnt << "\n";
	}
	return 0;
}