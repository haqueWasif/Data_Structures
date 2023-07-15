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

int sumNode(Node* root){
    queue <Node*> q;
    q.push(root);
    
    int s=0;
    while(!q.empty()){
        Node* f = q.front(); 
        q.pop(); 

        s += f->val;
        
        if(f->left != NULL) q.push(f->left);
        if(f->right != NULL) q.push(f->right);   

    }

    return s;
}
int main(){
    Node* root;
    input_tree(root);

    int ssum = sumNode(root);
    cout << ssum << " ";

    return 0;
}