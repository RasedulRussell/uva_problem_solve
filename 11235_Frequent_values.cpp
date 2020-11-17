#include<bits/stdc++.h>
using namespace std;

#define int int
#define INF 1000000
#define MAX 100005 ///100000
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///11235_Frequent_values.cpp

int tree[4 * MAX];

void update(int idx, int val, int node, int l, int r){
   if(l+1 == r){
      tree[node] = val;
      return;
   }
   int mid = (l + r) / 2;
   if(idx < mid){
      update(idx, val, 2 * node + 1, l, mid);
   }else{
      update(idx, val, 2 * node + 2, mid, r);
   }
   tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
   return;
}

int query(int lq, int rq, int node, int l, int r){
   if(lq <= l && rq+1 >= r){
      return tree[node];
   }
   if(lq >= r || rq < l){
      return 0;
   }
   int mid = (l + r) / 2;
   return max(query(lq, rq, 2 * node + 1, l, mid), query(lq, rq, 2 * node + 2, mid, r));
}

int32_t main(){
   __FastIO;
   int n, q;
   while(cin >> n && n){
      cin >> q;
      int arr[n];
      for(int i = 0; i < n; i++){
         cin >> arr[i];
      }
      map<int, pii>maping;
      for(int i = 0; i < n; i++){
         int val = arr[i];
         int left = i;
         int cnt = 1;
         while(i+1 < n && arr[i+1] == val){
            cnt++;
            i++;
         }
         for(int j = left; j <= i; j++){
            update(j, cnt, 0, 0, n);
         }
         maping[val] = make_pair(left, i);
      }
      while(q--){
         int l, r;
         cin >> l >> r;
         l--; r--;
         int leftVal = arr[l];
         int rightVal = arr[r];
         if(leftVal == rightVal){
            cout << (r - l + 1) << "\n";
         }else{
            auto leftPart = maping[leftVal];
            auto rightPart = maping[rightVal];
            int a = leftPart.second - l + 1;
            int b = r - rightPart.first + 1;
            l = leftPart.second + 1;
            r = rightPart.first - 1;
            cout << max(max(a, b), query(l, r, 0, 0, n)) << "\n";
         }
      }
   }
   return 0;
}