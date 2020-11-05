#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll>inorder, postorder;
unordered_map<ll, int>inorderIdx;
unordered_map<ll, int>ans;
int idx = 0;

struct treeNode{
    ll data;
    treeNode *left, *right;
};

treeNode *newNode(ll val){
    treeNode *temp = new treeNode;
    temp->data = val;
    temp->left = temp->right = NULL;
    return (temp);
}

void process(string line, vector<ll>&v){
    ll val;
    stringstream s;
    s << line;
    while(s >> val){
        v.push_back(val);
    }
    return;
}

treeNode *builtTree(int l, int r){
    if(l > r)return NULL;

    ll val = postorder[idx--];
    int currentIdx = inorderIdx[val];
    treeNode *current = newNode(val);

    if(l == r)return current;

    current->right = builtTree(currentIdx+1, r);
    current->left = builtTree(l, currentIdx-1);

    return current;
}

void dfs(treeNode *root, ll val){
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        ans[val+root->data] = root->data;
        ///cout << val+root->data << " " << root->data << "\n";
        return;
    }
    dfs(root->left, val+root->data );
    dfs(root->right, val+root->data);
}

void ini(){
    inorder.clear();
    postorder.clear();
    inorderIdx.clear();
    ans.clear();

}

int main(){
    string line;
    while(getline(cin , line)){
        ini();
        process(line, inorder);
        getline(cin, line);
        process(line, postorder);
        idx = postorder.size() - 1;
        for(int i = 0; i <= idx; i++){
            inorderIdx[inorder[i]] = i;
        }
        treeNode *root = builtTree(0, idx);
        dfs(root, 0);
        ll minVal = LONG_LONG_MAX;
        int data;
        for(auto x : ans){
            if(x.first < minVal){
                minVal = x.first;
                data = x.second;
            }
        }
        cout << data << "\n";
    }
}
