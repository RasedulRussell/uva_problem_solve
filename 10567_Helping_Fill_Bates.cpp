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

vector<int>frequency[60];

void ini(){
	for(int i = 0; i < 60; i++){
		frequency[i].clear();
	}
	return;
}

int main() {
	__FastIO;
	string input;
	while(cin >> input){
		ini();
		int n = input.size();
		for(int i = 0; i < n; i++){
			int val = input[i] - 'A';
			frequency[val].push_back(i);
		}
		int query;
		cin >> query;
		while(query--){
			int lastValue = -1;
			string word;
			cin >> word;
			int first = -1, last = -1;
			
			for(int i = 0; i < word.size(); i++){
				int root = word[i] - 'A';
				int idx = upper_bound(frequency[root].begin(), frequency[root].end(), lastValue) - frequency[root].begin();
				if(idx == frequency[root].size()){
					break;
				}
				if(i == 0){
					first = frequency[root][idx];
				}
				if(i == word.size()-1){
					last = frequency[root][idx];
				}
				lastValue = frequency[root][idx];
			}
			if(last == -1){
				cout << "Not matched\n";
			}else{
				cout << "Matched " << first << " " << last << "\n";
			}
		}
	}
	return 0;
}