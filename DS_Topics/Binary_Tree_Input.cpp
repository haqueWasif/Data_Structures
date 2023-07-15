#include<bits/stdc++.h>
using namespace std;

/*

Array, Linked List -> Linear Data Structure
(Stack, Queue are not included as these are also created using Array, Linked List)

Tree Data Structure
-> Non-Linear Data Structure (No library)
-> Follows Hiearchy Structure (Grandfather -> Father -> Son )
-> Root is from where it starts (Grandfather) , Branches or Parent Nodes (Father, Fathers Brother, Sister..), and ends at leaf (Son)
-> A member can be parent as well as children at the same time (Branches)

Binary Tree
-> Maximum 2 node from a particular node

N-ary Tree
-> Maximum n node from a particular node

Properties for a node
-> Data type of node (depends upon data)
-> Left (Node* )
-> Right (Node* )

Application of Binary Tree (Not used directly but is implemented within)
-> In Machine Learning Algorithm , AI for creating decision tree
-> Binary Search (Visualization) not for creating it
-> Implementation of Heap Sort
-> Syntax Tree within compiler

*/

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

void preorder(Node* root){ // Depth Wise (Pre Order)
    if(root == NULL) return;

    cout << root->val << " ";
    
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){ // Depth Wise (Post Order)
    if(root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);

    cout << root->val << " ";

}

void inorder(Node* root){ // Depth Wise (In Order)
    if(root == NULL) return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);

}

void levelorder(Node* root){ // Level Order
    queue <Node*> q;

    if(root) q.push(root);
    while(!q.empty()){

        // 1. Take it out from the line
        Node* f = q.front(); 
        q.pop(); 

        // 2.  Do all the operations with it
        cout << f->val << " "; 
        
        // 3. Push the children to the line
        if(f->left != NULL) q.push(f->left);
        if(f->right != NULL) q.push(f->right);   

        // if(f->left != NUll) and if(f->right != NULL) is same as if(f->left) and if(f->right) respectively
    }

}

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
    levelorder(root);
    
    return 0;
}