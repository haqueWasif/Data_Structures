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

void levelorder(Node* root){
    queue <Node*> q;

    q.push(root);
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


int main(){
    Node* root = new Node(10);
    
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);
    Node* f = new Node(70);
    Node* g = new Node(80);
    Node* h = new Node(90);
    Node* i = new Node(100);

    // Connection
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    b->right = d;
    c->right = e;
    d->left = f;
    d->right = g;
    h->right = i;

    // Order of Traversal
    /*
        -> Depth wise and Level wise
    
        // Depth Wise 
        -> Pre Order (root -> left sub-tree -> right sub-tree)
        -> Post Order (left sub-tree -> right sub-tree -> root)
        -> In Order (left sub-tree -> root -> right sub-tree)

        # Pre Order, Post Order, In Order are (dfs: depth first search)
        # Level Order (bfs: breadth first search)


    */

    cout << "Pre Order: ";
    preorder(root);
    cout<<endl;
    cout<<endl;

    cout << "Post Order: ";
    postorder(root);
    cout<<endl;
    cout<<endl;
    
    cout << "In Order: ";
    inorder(root);
    cout<<endl;
    cout<<endl;
    
    cout << "Level Order: ";
    levelorder(root);
    
    return 0;
}