#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 209
#define INF 100000000
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

///860_Entropy_Text_Analyzer.cpp

map<string, int>words;

int32_t main(){
    ///cout << fixed << setprecision(1);
    string endOfInput = "****END_OF_INPUT****";
    string endOfText = "****END_OF_TEXT****";
    string line;
    while(getline(cin, line)){
        if(line == endOfInput)return 0;
        if(line == endOfText){
            double entropy = 0.0;
            double maxEntropy = 0.0;
            int lemda = 0;
            for(auto i : words){
                lemda += i.second;
            }
            maxEntropy = log10((double)lemda);
            for(auto x : words){
                double val = (double)x.second;
                entropy = entropy + (val * (maxEntropy - log10(val)));
            }
            entropy = entropy / (double)lemda;
            double relativeEntropy = (entropy / maxEntropy) * 100.0;
            cout << lemda << " " << fixed << setprecision(1) << entropy << " " << fixed << setprecision(0) << relativeEntropy << "\n";
            words.clear();
            continue;
        }
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        for(int i = 0, sz = line.size(); i < sz; i++){
            if(line[i] == '.' || line[i] == ',' || line[i] == ':' || line[i] == ';' || line[i] == '!' || line[i] == '?' || line[i] == '"' || line[i] == '(' || line[i] == ')' || line[i] == '\t' || line[i] == '\n'){
                line[i] = ' ';
            }
        }
        string word;
        stringstream ss(line);
        while(ss >> word){
            if(words.find(word) == words.end()){
                words[word] = 1;
            }else{
                words[word]++;
            }
        }
    }
    return 0;
}