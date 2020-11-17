#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000
#define MAX 120
#define MOD  1000000009
#define pii pair<int, int>
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///468_Key_to_Success.cpp

class node{
public:
    char ch;
    int frequency;
    node(char ch, int frequency){
        this->ch = ch;
        this->frequency = frequency;
    }
    bool operator<(node other)const{
        return frequency < other.frequency;
    }
};

int32_t main(){
   int cs, tc = 0;
   cin >> cs;
   while(cs--){
       if(tc){
           cout << "\n";
       }
       tc = 1;
       string a, b;
       cin >> a >> b;
       map<char, int>mp;
       for(char ch : a){
           if(mp.count(ch) == 0){
               mp[ch] = 1;
           }else{
               mp[ch]++;
           }
       }
       vector<node>aFrequency, bFrequency;
       for(auto x : mp){
           aFrequency.push_back(node(x.first, x.second));
       }
       mp.clear();
       for(char ch : b){
           if(mp.count(ch) == 0){
               mp[ch] = 1;
           }else{
               mp[ch]++;
           }
       }
       for(auto x : mp){
           bFrequency.push_back(node(x.first, x.second));
       }
       sort(aFrequency.begin(), aFrequency.end());
       sort(bFrequency.begin(), bFrequency.end());
       map<char, char>oneToOne;
       for(int i = 0; i < aFrequency.size(); i++){
           oneToOne[bFrequency[i].ch] = aFrequency[i].ch;
       }
       for(int i = 0; i < b.size(); i++){
           b[i] = oneToOne[b[i]];
       }
       cout << b << "\n";
   }
}