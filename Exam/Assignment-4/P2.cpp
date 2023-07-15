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

void leafNode(Node* root, queue <int> &q){ 
    if(root == NULL) return;
    if(root -> left == NULL && root -> right == NULL){
        q.push(root->val);
    }

    leafNode(root->left, q);
    leafNode(root->right, q);

}

int maxNode(Node* root){
    queue <int> q;
    
    int mx=INT_MIN;
    leafNode(root, q);

    while(!q.empty()){
        if(mx < q.front()){
            mx = q.front();
        }
        q.pop();
    }

    return mx;
}


int minNode(Node* root){
    queue <int> q;
    
    int mn=INT_MAX;
    leafNode(root, q);

    while(!q.empty()){
        if(mn > q.front()){
            mn = q.front();
        }
        q.pop();
    }

    return mn;
}

int main(){
    Node* root;
    input_tree(root);

    int mx = maxNode(root), mn = minNode(root);
    cout << mx << " " << mn;

    return 0;
}