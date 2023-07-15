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

void reverse(Node* head, Node* tail){
    while(head != tail){
        swap(head->val, tail->val);
        if(head -> next == tail) return;
        head = head -> next;
        tail = tail -> prev;
    }
}

void printList(Node* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> next;
    }
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;

    while(true){
        int v;
        cin >> v;
        if(v==-1)break;
        insertAtTail(head, tail, v);
    }

    reverse(head,tail);
    printList(head);
    
    return 0;
}