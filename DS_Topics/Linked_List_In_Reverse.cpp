#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this -> val = val;
            this -> next = NULL;
        }

};

void insertAtTail2(Node* &head, Node* &tail, int v){
    // O(1)
    Node* newNode = new Node(v);
    
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail -> next = newNode;
    tail = newNode;
}

void printLinkedList(Node* head){
    if(head == NULL) return;

    printLinkedList(head -> next);
    
    cout << head -> val << " ";
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    while(true){        
        int v;
        cin >> v;
        if(v==-1) break;
        insertAtTail2(head, tail, v);
    }
    printLinkedList(head);

    return 0;
}