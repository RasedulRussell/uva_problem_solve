#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 2
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11997_K_Smallest_Sums.cpp

class node{
public:
    int value, idx;
    node(int value, int idx){
        this->value = value;
        this->idx = idx;
    }
    bool operator<(node other)const{
        return value > other.value;
    }
};

int32_t main(){
    ///__FastIO;
    int n;
    while(cin >> n){
        int ans[n];
        for(int i = 0; i < n; i++){
            cin >> ans[i];
        }
        sort(ans, ans+n);
        int temp[n];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> temp[j];
            }
            sort(temp, temp+n);
            priority_queue<node>pq;
            for(int j = 0; j < n; j++){
                pq.push(node(ans[j]+temp[0], 1));
            }
            for(int j = 0; j < n; j++){
                node front = pq.top();
                pq.pop();
                ans[j] = front.value;
                if(front.idx < n){
                    pq.push(node(ans[j] - temp[front.idx-1] + temp[front.idx], front.idx+1));
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i];
            if(i != n-1){
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}