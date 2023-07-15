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

int count(Node* root){ 
    if(root == NULL) return 0;

    int l = count(root->left);
    int r = count(root->right);
    
    return l+r+1;
}

/*

Method 2:

void countNode(Node* root, int &count){ 
    if(root == NULL) return;

    count++;
    
    countNode(root->left, count);
    countNode(root->right, count);
}

*/

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
        
        // 2.  Do all the operations with it
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

        // 3. Push the children to the line
        if(left) q.push(left);
        if(right) q.push(right);
    }
    
}

int main(){
    Node* root = NULL;

    input_tree(root);
    
    cout << count(root);
    
    return 0;
}