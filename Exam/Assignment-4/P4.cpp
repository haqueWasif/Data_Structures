#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }   
};

void input_tree(Node* &root)
{   
    int val;
    cin >> val;

    if(val != -1) root = new Node(val);
    
    queue <Node*> q;
    if(root) q.push(root);

    while(!q.empty()){
        // 1. Take it out from the line
        Node* f = q.front();
        q.pop();
        
        int l, r;
        cin >> l >> r;

        Node* left=NULL;
        Node* right=NULL;

        if(l != -1) {
            left = new Node(l);
            f->left = left;
        }
        if(r != -1) {
            right = new Node(r);
            f->right = right;
        }

        if(left) q.push(left);
        if(right) q.push(right);
    }
    
}

vector <int> levelNode(Node* root, int x){
    queue < pair < Node*, int > > q;
    if(root != NULL) q.push({root, 0});

    vector <int> v;
    while(!q.empty()){
        pair <Node*, int> f = q.front();
        Node* parent = f.first;
        int level = f.second;  
        q.pop(); 

        if(level == x){
            v.push_back(parent->val);
        }
        
        if(parent->left != NULL) q.push({parent->left, level+1});   
        if(parent->right != NULL) q.push({parent->right, level+1});

    }

    return v;

}


int main(){
    Node* root;
    input_tree(root);

    int x;
    cin >> x;
    vector <int> v = levelNode(root, x);

    if(v.empty()) cout << "Invalid";
    else {
        for(int val : v) cout << val << " ";
    }

    return 0;
}