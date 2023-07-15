#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> prev = NULL;
            this -> next = NULL;
        }

};

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);

    if(tail == NULL){
        head = newNode;
        tail = newNode;        
        return;
    }

    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode; 
}

int size(Node* head){
    int n=0;
    while(head!=NULL){
        n++;
        head = head -> next;
    }
    return n;
}

int checkSame(Node* h1, Node* h2){
    int n1 = size(h1), n2 = size(h2);
    
    if(n1 == 0 || n2 == 0) return 0; 
    else if(n1 == n2){
        while(h1 -> val == h2 -> val){
            h1 = h1 -> next;
            h2 = h2 -> next;
            if(h1 == NULL && h2 == NULL){
                return 1;
            }
        }
        return 0;
    }
    
    return 0;
}

int main(){
    Node* h1=NULL;
    Node* t1=NULL;

    Node* h2=NULL;
    Node* t2=NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        insertAtTail(h1, t1, v);
    }

    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        insertAtTail(h2, t2, v);
    }  

    int isSame = checkSame(h1, h2);
    if(isSame) cout << "YES";
    else cout << "NO";
    
    return 0;
}