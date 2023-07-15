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

int totalNodes(Node* root){ 
    queue <Node*> q;
    if(root != NULL) q.push(root);

    int count=0;
    while(!q.empty()){
        Node* f = q.front(); 
        q.pop(); 

        count++;
        
        if(f->left != NULL) q.push(f->left);   
        if(f->right != NULL) q.push(f->right);

    }

    return count;
}

// vector <int> leafNodeLevel(Node* root){ 
//     queue < pair < Node*, int > > q;
//     if(root != NULL) q.push({root, 0});

//     vector <int> v;
//     while(!q.empty()){
//         pair <Node*, int> f = q.front();
//         Node* parent = f.first;
//         int level = f.second;  
//         q.pop(); 

//         if(parent->left == NULL && parent->right == NULL){
//             v.push_back(level);
//             continue;
//         }
//         else if(parent->left == NULL || parent->right == NULL)  v.push_back(-1);
        
//         if(parent->left != NULL) q.push({parent->left, level+1});   
//         if(parent->right != NULL) q.push({parent->right, level+1});

//     }
//     return v;
// }

int getMaxHeight(Node* root){ 
    if(root == NULL) return 0;

    int l = getMaxHeight(root->left);
    int r = getMaxHeight(root->right);

    return  max(l,r) + 1;

}

bool checkPerfectTree(Node* root){
    int total_nodes = totalNodes(root);
    int h = getMaxHeight(root);

    if(total_nodes == pow(2, h) - 1){
        return true;
    }

    return false;
    
}

int main(){
    Node* root;
    input_tree(root);

    bool isPerfect = checkPerfectTree(root);

    if(isPerfect) cout << "YES";
    else cout << "NO";

    return 0;
}